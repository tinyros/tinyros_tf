#include <tiny_ros/ros.h>
#include <tiny_ros/tf/transform_listener.h>


int main(int argc, char** argv)
{
  tinyros::init("tinyros_tf_empty_listener");
  tinyros::tf::TransformListener listener;
  while (tinyros::nh()->ok()){
    tinyros::tf::StampedTransform transform;
    try 
    {
      listener.lookupTransform("base_link", "child_link", tinyros::Time(), transform);
    }
    catch (tinyros::tf::TransformException ex)
    {
      tinyros_log_error("%s",ex.what());
    }

    tinyros::Duration(1.0/10.0).sleep();
  }
  return 0;
}
