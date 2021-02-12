#ifndef EFFORT_DISPLAY_H
#define EFFORT_DISPLAY_H

#ifndef Q_MOC_RUN
#include <boost/circular_buffer.hpp>
#endif

#include <tiny_ros/sensor_msgs/JointState.h>
#include <rviz/message_filter_display.h>

namespace Ogre
{
    class SceneNode;
}

namespace rviz
{
    class FloatProperty;
    class IntProperty;
    class StringProperty;
    class CategoryProperty;
    class BoolProperty;
    class RosTopicProperty;
}

namespace urdf
{
    class Model;
}
#ifndef Q_MOC_RUN
#include <tiny_ros/tf/message_filter.h>
#endif
#include "rviz/display_context.h"
#include "rviz/frame_manager.h"
#include "rviz/properties/ros_topic_property.h"

namespace rviz
{
/** @brief Display subclass using a tf::MessageFilter, templated on the ROS message type.
 *
 * This class brings together some common things used in many Display
 * types.  It has a tf::MessageFilter to filter incoming messages, and
 * it handles subscribing and unsubscribing when the display is
 * enabled or disabled.  It also has an Ogre::SceneNode which  */
class MessageFilterJointStateDisplay: public _RosTopicDisplay
{
// No Q_OBJECT macro here, moc does not support Q_OBJECT in a templated class.
public:
  /** @brief Convenience typedef so subclasses don't have to use
   * the long templated class name to refer to their super class. */
  typedef MessageFilterJointStateDisplay MFDClass;

  MessageFilterJointStateDisplay()
    : tf_filter_( NULL )
    , messages_received_( 0 )
    {
      QString message_type = QString::fromStdString( tinyros::sensor_msgs::JointState::getTypeStatic() );
      topic_property_->setMessageType( message_type );
      topic_property_->setDescription( message_type + " topic to subscribe to." );
    }

  virtual void onInitialize()
    {
      tf_filter_ = new tinyros::tf::MessageFilter<tinyros::sensor_msgs::JointState>( *context_->getTFClient(),
                                                    fixed_frame_.toStdString(), 10);
      tf_filter_->registerCallback(std::bind( &MessageFilterJointStateDisplay::incomingMessage, this, std::placeholders::_1 ));
      context_->getFrameManager()->registerFilterForTransformStatusCheck(tf_filter_, this );
    }

  virtual ~MessageFilterJointStateDisplay()
    {
      unsubscribe();
      delete tf_filter_;
    }

  virtual void reset()
    {
      Display::reset();
      tf_filter_->clear();
      messages_received_ = 0;
    }

protected:
  virtual void updateTopic()
    {
      unsubscribe();
      reset();
      subscribe();
      context_->queueRender();
    }

  virtual void subscribe()
    {
      if( !isEnabled() )
      {
        return;
      }

      try
      {
        tf_filter_->connectInput(topic_property_->getTopicStd());
        setStatus( StatusProperty::Ok, "Topic", "OK" );
      }
      catch( std::exception& e )
      {
        setStatus( StatusProperty::Error, "Topic", QString( "Error subscribing: " ) + e.what() );
      }
    }

  virtual void unsubscribe()
    {
      tf_filter_->connectEnable(false);
    }

  virtual void onEnable()
    {
      subscribe();
    }

  virtual void onDisable()
    {
      unsubscribe();
      reset();
    }

  virtual void fixedFrameChanged()
    {
      tf_filter_->setTargetFrame( fixed_frame_.toStdString() );
      reset();
    }

  /** @brief Incoming message callback.  Checks if the message pointer
   * is valid, increments messages_received_, then calls
   * processMessage(). */
  void incomingMessage( const tinyros::sensor_msgs::JointStateConstPtr& msg )
    {
      if( !msg )
      {
        return;
      }

      ++messages_received_;
      setStatus( StatusProperty::Ok, "Topic", QString::number( messages_received_ ) + " messages received" );

      processMessage( msg );
    }

  /** @brief Implement this to process the contents of a message.
   *
   * This is called by incomingMessage(). */
  virtual void processMessage( const tinyros::sensor_msgs::JointStateConstPtr& msg ) = 0;

  tinyros::tf::MessageFilter<tinyros::sensor_msgs::JointState>* tf_filter_;
  uint32_t messages_received_;
};
} // rviz

namespace rviz
{
    class JointInfo: public QObject {
        Q_OBJECT
        public:
        JointInfo(const std::string name, rviz::Property* parent_category);
        ~JointInfo();

        void setEffort(double e);
        double getEffort();
        void setMaxEffort(double m);
        double getMaxEffort();
        bool getEnabled() const;

        tinyros::Time last_update_;

    public Q_SLOTS:
        void updateVisibility();

    private:
        std::string name_;
        double effort_, max_effort_;

        rviz::Property* category_;
        rviz::FloatProperty* effort_property_;
        rviz::FloatProperty* max_effort_property_;
    };

    typedef std::set<JointInfo*> S_JointInfo;
    typedef std::vector<std::string> V_string;

    class EffortVisual;

    class EffortDisplay: public rviz::MessageFilterJointStateDisplay
    {
    Q_OBJECT
    public:
    // Constructor.  pluginlib::ClassLoader creates instances by calling
    // the default constructor, so make sure you have one.
    EffortDisplay();
    virtual ~EffortDisplay();

    // Overrides of public virtual functions from the Display class.
    virtual void onInitialize();
    virtual void reset();

    private Q_SLOTS:
    // Helper function to apply color and alpha to all visuals.
    void updateColorAndAlpha();
        void updateHistoryLength();
        void updateRobotDescription();

        JointInfo* getJointInfo( const std::string& joint);
        JointInfo* createJoint(const std::string &joint);

    protected:
        // overrides from Display
        virtual void onEnable();
        virtual void onDisable();

        // load
        void load();
        void clear();

        // The object for urdf model
        boost::shared_ptr<urdf::Model> robot_model_;

        //
        std::string robot_description_;

    private:
    void processMessage( const tinyros::sensor_msgs::JointStateConstPtr& msg );

        // Storage for the list of visuals.  It is a circular buffer where
        // data gets popped from the front (oldest) and pushed to the back (newest)
        boost::circular_buffer<boost::shared_ptr<EffortVisual> > visuals_;

        typedef std::map<std::string, JointInfo*> M_JointInfo;
        M_JointInfo joints_;

    // Property objects for user-editable properties.
        rviz::FloatProperty *alpha_property_,* width_property_,* scale_property_;
        rviz::IntProperty *history_length_property_;

        rviz::StringProperty *robot_description_property_;
        rviz::Property *joints_category_;
        rviz::BoolProperty *all_enabled_property_;
    };
} // end namespace rviz_plugin_tutorials

#endif // EFFORT_DISPLAY_H
