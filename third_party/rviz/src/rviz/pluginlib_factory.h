/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef PLUGINLIB_FACTORY_H
#define PLUGINLIB_FACTORY_H

#include <QHash>
#include <QSet>
#include <QMap>
#include <QString>
#include <QStringList>

#include <string>
#include <vector>
#include <tinyxml.h>

#ifndef Q_MOC_RUN
#include <tiny_ros/pluginlib/class_loader.h>
#endif

#include "rviz/class_id_recording_factory.h"
#include "rviz/load_resource.h"

namespace rviz
{

template<class Type>
class PluginlibFactory: public ClassIdRecordingFactory<Type>
{
private:
  struct BuiltInClassRecord
  {
    QString class_id_;
    QString package_;
    QString name_;
    QString description_;
    Type*(*factory_function_)();
  };

public:
  PluginlibFactory( const QString& package, const QString& base_class_type )
    {
    }
  virtual ~PluginlibFactory()
    {
    }

  virtual QStringList getDeclaredClassIds()
    {
      QStringList ids;
      typename QHash<QString, BuiltInClassRecord>::const_iterator iter;
      for( iter = built_ins_.begin(); iter != built_ins_.end(); iter++ )
      {
        ids.push_back( iter.key() );
      }
      return ids;
    }

  virtual QString getClassDescription( const QString& class_id ) const
    {
      typename QHash<QString, BuiltInClassRecord>::const_iterator iter = built_ins_.find( class_id );
      if( iter != built_ins_.end() )
      {
        return iter->description_;
      }
      return "";
    }

  virtual QString getClassName( const QString& class_id ) const
    {
      typename QHash<QString, BuiltInClassRecord>::const_iterator iter = built_ins_.find( class_id );
      if( iter != built_ins_.end() )
      {
        return iter->name_;
      }
      return "";
    }

  virtual QString getClassPackage( const QString& class_id ) const
    {
      typename QHash<QString, BuiltInClassRecord>::const_iterator iter = built_ins_.find( class_id );
      if( iter != built_ins_.end() )
      {
        return iter->package_;
      }
      return "";
    }

  virtual QString getPluginManifestPath( const QString& class_id ) const
    {
      return "";
    }

  virtual QIcon getIcon( const QString& class_id ) const
  {
    QString package = getClassPackage( class_id );
    QString class_name = getClassName( class_id );
    QIcon icon = loadPixmap( "package://"+package+"/icons/classes/"+class_name+".svg" );
    if ( icon.isNull() )
    {
      icon = loadPixmap( "package://"+package+"/icons/classes/"+class_name+".png" );
      if ( icon.isNull() )
      {
        icon = loadPixmap( "package://rviz/icons/default_class_icon.png");
      }
    }
    return icon;
  }

  virtual void addBuiltInClass( const QString& package, const QString& name, const QString& description,
                                Type* (*factory_function)())
    {
      QSet<QString> message_types = QSet<QString>();
      addBuiltInClass(package, name, description, factory_function, message_types);
    }

  virtual void addBuiltInClass( const QString& package, const QString& name, const QString& description,
                                Type* (*factory_function)(), const QSet<QString>& message_types)
    {
      BuiltInClassRecord record;
      record.class_id_ = package + "/" + name;
      record.package_ = package;
      record.name_ = name;
      record.description_ = description;
      record.factory_function_ = factory_function;
      built_ins_[ record.class_id_ ] = record;

      if (message_types.size() > 0) {
        message_type_cache_[record.class_id_] = message_types;
      }
    }

  /** @brief Get all supported message types for the given class id. */
  virtual QSet<QString> getMessageTypes( const QString& class_id )
    {
      // lookup in cache
      if ( message_type_cache_.find( class_id ) != message_type_cache_.end() )
      {
        return message_type_cache_[class_id];
      }

      // Always initialize cache as empty so if we don't find it, next time
      // we won't look for it anymore either.
      message_type_cache_[ class_id ] = QSet<QString>();

      // parse xml plugin description to find out message types of all displays in it.
      QString xml_file = getPluginManifestPath( class_id );

      if ( !xml_file.isEmpty() )
      {
        tinyros_log_debug("Parsing %s", xml_file.toStdString().c_str());
        TiXmlDocument document;
        document.LoadFile(xml_file.toStdString());
        TiXmlElement * config = document.RootElement();
        if (config == NULL)
        {
          tinyros_log_error("Skipping XML Document \"%s\" which had no Root Element.  This likely means the XML is malformed or missing.", xml_file.toStdString().c_str());
          return QSet<QString>();
        }
        if (config->ValueStr() != "library" &&
            config->ValueStr() != "class_libraries")
        {
          tinyros_log_error("The XML document \"%s\" given to add must have either \"library\" or \
              \"class_libraries\" as the root tag", xml_file.toStdString().c_str());
          return QSet<QString>();
        }
        //Step into the filter list if necessary
        if (config->ValueStr() == "class_libraries")
        {
          config = config->FirstChildElement("library");
        }

        TiXmlElement* library = config;
        while ( library != NULL)
        {
          TiXmlElement* class_element = library->FirstChildElement("class");
          while (class_element)
          {
            std::string derived_class = class_element->Attribute("type");

            std::string current_class_id;
            if(class_element->Attribute("name") != NULL)
            {
              current_class_id = class_element->Attribute("name");
              tinyros_log_debug("XML file specifies lookup name (i.e. magic name) = %s.", current_class_id.c_str());
            }
            else
            {
              tinyros_log_debug("XML file has no lookup name (i.e. magic name) for class %s, assuming class_id == real class name.", derived_class.c_str());
              current_class_id = derived_class;
            }

            QSet<QString> message_types;
            TiXmlElement* message_type = class_element->FirstChildElement("message_type");

            while ( message_type )
            {
              if ( message_type->GetText() )
              {
                const char* message_type_str = message_type->GetText();
                tinyros_log_debug("%s supports message type %s", current_class_id.c_str(), message_type_str);
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
                message_types.insert( QString::fromAscii( message_type_str ) );
#else
                message_types.insert( QString(message_type_str) );
#endif
              }
              message_type = message_type->NextSiblingElement("message_type");
            }

            message_type_cache_[ QString::fromStdString(current_class_id) ] = message_types;

            //step to next class_element
            class_element = class_element->NextSiblingElement( "class" );
          }
          library = library->NextSiblingElement( "library" );
        }
      }

      // search cache again.
      if ( message_type_cache_.find( class_id ) != message_type_cache_.end() )
      {
        return message_type_cache_[class_id];
      }

      return QSet<QString>();
    }

protected:
  /** @brief Instantiate and return a instance of a subclass of Type using our
   *         pluginlib::ClassLoader.
   * @param class_id A string identifying the class uniquely among
   *        classes of its parent class.  rviz::GridDisplay might be
   *        rviz/Grid, for example.
   * @param error_return If non-NULL and there is an error, *error_return is set to a description of the problem.
   * @return A new instance of the class identified by class_id, or NULL if there was an error.
   *
   * If makeRaw() returns NULL and error_return is not NULL,
   * *error_return will be set.  On success, *error_return will not be
   * changed. */
  virtual Type* makeRaw( const QString& class_id, QString* error_return = NULL )
    {
      typename QHash<QString, BuiltInClassRecord>::const_iterator iter = built_ins_.find( class_id );
      if( iter != built_ins_.end() )
      {
        Type* instance = iter->factory_function_();
        if( instance == NULL && error_return != NULL )
        {
          *error_return = "Factory function for built-in class '" + class_id + "' returned NULL.";
        }
        return instance;
      }
      return NULL;
    }

private:
  QHash<QString, BuiltInClassRecord> built_ins_;
  QMap< QString, QSet<QString> > message_type_cache_;
};

} // end namespace rviz

#endif // PLUGINLIB_FACTORY_H
