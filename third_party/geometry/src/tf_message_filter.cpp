#include <tiny_ros/ros.h>
#include <tiny_ros/tf/message_filter.h>
#include <tiny_ros/tf/transform_listener.h>
#include <tiny_ros/tf/transform_broadcaster.h>
#include <tiny_ros/geometry_msgs/PointStamped.h>

class Notification
{
public:
  Notification(int expected_count)
  : count_(0)
  , expected_count_(expected_count)
  , failure_count_(0)
  {
  }

  void notify(const tinyros::geometry_msgs::PointStampedConstPtr& message)
  {
    ++count_;
  }

  void failure(const tinyros::geometry_msgs::PointStampedConstPtr& message, tinyros::tf::FilterFailureReason reason)
  {
    ++failure_count_;
  }

  int count_;
  int expected_count_;
  int failure_count_;
};

static void EXPECT_EQ(int cond, int value, std::string func, int line) 
{
  if (cond == value)
    std::cout << func.c_str() << "(" << line << ") : OK!" << std::endl;
  else
    std::cout << func.c_str() << "(" << line << ") : NG!" << std::endl;
}

static void TEST_noTransforms()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 1);
  filter.registerCallback(std::bind(&Notification::notify, &n, std::placeholders::_1));

  tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
  msg->header.stamp = tinyros::Time::now();
  msg->header.frame_id = "/frame2";
  filter.add(msg);

  EXPECT_EQ(0, n.count_, __FUNCTION__, __LINE__);
}

static void TEST_noTransformsSameFrame()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 1);
  filter.registerCallback(std::bind(&Notification::notify, &n, std::placeholders::_1));

  tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
  msg->header.stamp = tinyros::Time::now();
  msg->header.frame_id = "/frame1";
  filter.add(msg); 

  EXPECT_EQ(1, n.count_, __FUNCTION__, __LINE__);
}

static void TEST_preexistingTransforms()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 1);
  filter.registerCallback(std::bind(&Notification::notify, &n, std::placeholders::_1));

	tinyros::Time stamp = tinyros::Time::now();
	tinyros::tf::StampedTransform transform(tinyros::tf::Transform(tinyros::tf::Quaternion(0,0,0,1), tinyros::tf::Vector3(1,2,3)), stamp, "frame1", "frame2");
	tf_client.setTransform(transform);

	tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
	msg->header.stamp = stamp;
	msg->header.frame_id = "/frame2";

	filter.add(msg);

  EXPECT_EQ(1, n.count_, __FUNCTION__, __LINE__);
}

static void TEST_postTransforms()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 1);
  filter.registerCallback(std::bind(&Notification::notify, &n, std::placeholders::_1));

	tinyros::Time stamp = tinyros::Time::now();

	tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
  msg->header.stamp = stamp;
  msg->header.frame_id = "/frame2";

  filter.add(msg); 

  EXPECT_EQ(0, n.count_, __FUNCTION__, __LINE__);

	tinyros::tf::StampedTransform transform(tinyros::tf::Transform(tinyros::tf::Quaternion(0,0,0,1), tinyros::tf::Vector3(1,2,3)), stamp, "frame1", "frame2");
	tf_client.setTransform(transform);

	tinyros::Duration(0.1).sleep(); 

  EXPECT_EQ(1, n.count_, __FUNCTION__, __LINE__);
}

static void TEST_queueSize()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(10);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 10);
  filter.registerCallback(std::bind(&Notification::notify, &n, std::placeholders::_1));
  filter.registerFailureCallback(std::bind(&Notification::failure, &n, std::placeholders::_1, std::placeholders::_2));

	tinyros::Time stamp = tinyros::Time::now();

	for (int i = 0; i < 20; ++i)
	{
	  tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
    msg->header.stamp = stamp;
    msg->header.frame_id = "/frame2";

    filter.add(msg);
	}

  EXPECT_EQ(0, n.count_, __FUNCTION__, __LINE__);
  EXPECT_EQ(10, n.failure_count_, __FUNCTION__, __LINE__);
  
	tinyros::tf::StampedTransform transform(tinyros::tf::Transform(tinyros::tf::Quaternion(0,0,0,1), tinyros::tf::Vector3(1,2,3)), stamp, "frame1", "frame2");
	tf_client.setTransform(transform);

	tinyros::Duration(0.1).sleep(); 
  
  EXPECT_EQ(10, n.count_, __FUNCTION__, __LINE__);
}

static void TEST_setTargetFrame()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 1);
  filter.registerCallback(std::bind(&Notification::notify, &n, std::placeholders::_1));
	filter.setTargetFrame("frame1000");

	tinyros::Time stamp = tinyros::Time::now();
  tinyros::tf::StampedTransform transform(tinyros::tf::Transform(tinyros::tf::Quaternion(0,0,0,1), tinyros::tf::Vector3(1,2,3)), stamp, "frame1000", "frame2");
  tf_client.setTransform(transform);

  tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
  msg->header.stamp = stamp;
  msg->header.frame_id = "/frame2";

	filter.add(msg); 

  EXPECT_EQ(1, n.count_, __FUNCTION__, __LINE__);
}

static void TEST_multipleTargetFrames()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "", 1);
  filter.registerCallback(std::bind(&Notification::notify, &n, std::placeholders::_1));

  std::vector<std::string> target_frames;
  target_frames.push_back("frame1");
  target_frames.push_back("frame2");
	filter.setTargetFrames(target_frames);

	tinyros::Time stamp = tinyros::Time::now();
  tinyros::tf::StampedTransform transform(tinyros::tf::Transform(tinyros::tf::Quaternion(0,0,0,1), tinyros::tf::Vector3(1,2,3)), stamp, "frame1", "frame3");
  tf_client.setTransform(transform);

  tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
  msg->header.stamp = stamp;
  msg->header.frame_id = "/frame3";
  filter.add(msg);

  tinyros::Duration(0.1).sleep();

	EXPECT_EQ(0, n.count_, __FUNCTION__, __LINE__); // frame1->frame3 exists, frame2->frame3 does not (yet)

	transform.child_frame_id_ = "frame2";
	tf_client.setTransform(transform);

	tinyros::Duration(0.1).sleep();

	EXPECT_EQ(1, n.count_, __FUNCTION__, __LINE__);  // frame2->frame3 now exists
}

static void TEST_tolerance()
{
  tinyros::Duration offset(0.2);
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 1);
  filter.registerCallback(std::bind(&Notification::notify, &n, std::placeholders::_1));
  filter.setTolerance(offset);

	tinyros::Time stamp = tinyros::Time::now();
  tinyros::tf::StampedTransform transform(tinyros::tf::Transform(tinyros::tf::Quaternion(0,0,0,1), tinyros::tf::Vector3(1,2,3)), stamp, "frame1", "frame2");
  tf_client.setTransform(transform);

  tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
  msg->header.stamp = stamp;
  msg->header.frame_id = "/frame2";
  filter.add(msg);

	EXPECT_EQ(0, n.count_, __FUNCTION__, __LINE__); //No return due to lack of space for offset

	transform.stamp_ += offset*1.1;
	tf_client.setTransform(transform);

	tinyros::Duration(0.1).sleep();

	EXPECT_EQ(1, n.count_, __FUNCTION__, __LINE__); // Now have data for the message published earlier

	msg->header.stamp = stamp + offset;
	filter.add(msg);

	EXPECT_EQ(1, n.count_, __FUNCTION__, __LINE__); // Latest message is off the end of the offset
}


static void TEST_outTheBackFailure()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 1);
  filter.registerFailureCallback(std::bind(&Notification::failure, &n, std::placeholders::_1, std::placeholders::_2));

  tinyros::Time stamp = tinyros::Time::now();
  tinyros::tf::StampedTransform transform(tinyros::tf::Transform(tinyros::tf::Quaternion(0,0,0,1), tinyros::tf::Vector3(1,2,3)), stamp, "frame1", "frame2");
  tf_client.setTransform(transform);

  transform.stamp_ = stamp + tinyros::Duration(10000);
  tf_client.setTransform(transform);

  tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
  msg->header.stamp = stamp;
  msg->header.frame_id = "/frame2";
  filter.add(msg);

  EXPECT_EQ(1, n.failure_count_, __FUNCTION__, __LINE__);
}

static void TEST_emptyFrameIDFailure()
{
  tinyros::tf::TransformListener tf_client;
  Notification n(1);
  tinyros::tf::MessageFilter<tinyros::geometry_msgs::PointStamped> filter(tf_client, "frame1", 1);
  filter.registerFailureCallback(std::bind(&Notification::failure, &n, std::placeholders::_1, std::placeholders::_2));

  tinyros::geometry_msgs::PointStampedPtr msg(new tinyros::geometry_msgs::PointStamped);
  msg->header.frame_id = "";
  filter.add(msg);

  EXPECT_EQ(1, n.failure_count_, __FUNCTION__, __LINE__);
}


int main(int argc, char** argv)
{
  tinyros::init("tinyros_tf_message_filter");

  TEST_noTransforms();
  TEST_noTransformsSameFrame();
  TEST_preexistingTransforms();
  TEST_postTransforms();
  TEST_queueSize();
  TEST_setTargetFrame();
  TEST_multipleTargetFrames();
  TEST_tolerance();
  TEST_outTheBackFailure();
  TEST_emptyFrameIDFailure();

  return 0;
}

