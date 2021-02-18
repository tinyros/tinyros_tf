find_package(PkgConfig)
pkg_check_modules(NEW_YAMLCPP yaml-cpp>=0.5)
if(NEW_YAMLCPP_FOUND)
  add_definitions(-DRVIZ_HAVE_YAMLCPP_05)
endif(NEW_YAMLCPP_FOUND)

add_subdirectory(default_plugin)

include_directories(.)

# Build the version number and other build-time constants into the
# source for access at run-time.
set(ENV_CONFIG_FILE ${PROJECT_SOURCE_DIR}/src/rviz/env_config.cpp)
set(RVIZ_VERSION 1.0)
message("making version ${RVIZ_VERSION}.")

configure_file(${PROJECT_SOURCE_DIR}/src/rviz/env_config.cpp.in ${ENV_CONFIG_FILE} @ONLY)

set(RVIZ_SOURCES
  ${PROJECT_SOURCE_DIR}/src/rviz/bit_allocator.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/config.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/display_context.h
  ${PROJECT_SOURCE_DIR}/src/rviz/display_factory.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/display_group.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/displays_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/failed_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/failed_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/failed_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/failed_view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/frame_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/load_resource.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/frame_position_tracking_view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/geometry.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/help_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/image/ros_image_texture.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/image/image_display_base.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/loading_dialog.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/message_filter_display.h
  ${PROJECT_SOURCE_DIR}/src/rviz/mesh_loader.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/new_object_dialog.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/add_display_dialog.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/apply_visibility_bits.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/arrow.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/axes.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/billboard_line.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/camera_base.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/grid.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/initialization.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/line.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/movable_text.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/object.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/ogre_logging.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/ogre_render_queue_clearer.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/orthographic.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/point_cloud.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/qt_ogre_render_window.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/render_system.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/render_widget.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/shape.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/mesh_shape.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/ogre_helpers/stl_loader.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/panel_dock_widget.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/panel_factory.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/bool_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/color_editor.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/color_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/combo_box.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/display_visibility_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/display_group_visibility_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/editable_combo_box.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/editable_enum_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/enum_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/float_edit.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/float_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/int_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/line_edit_with_button.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/parse_color.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/property_tree_delegate.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/property_tree_model.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/property_tree_widget.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/property_tree_with_help.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/quaternion_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/ros_topic_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/splitter_handle.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/status_list.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/status_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/string_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/tf_frame_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/properties/vector_property.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/render_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/robot/robot_link.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/robot/robot_joint.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/robot/robot.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/robot/tf_link_updater.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/scaled_image_widget.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/screenshot_dialog.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/selection_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/selection/selection_handler.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/selection/selection_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/splash_screen.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/time_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/tool_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/uniform_string_stream.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/view_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/views_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/visualization_frame.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/visualization_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/wait_for_master_dialog.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/widget_geometry_change_detector.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/tool_properties_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/yaml_config_reader.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/yaml_config_writer.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/retriever.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/urdf/model.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/utils/utils.cpp
  ${tinyros_lib_SRC_LIST} 
  ${tinyros_tf_SRC_LIST}
  ${tinyros_param_SRC_LIST}
  ${tinyros_package_SRC_LIST}
  ${class_loader_SRC_LIST}
  ${ENV_CONFIG_FILE}
)

########### The rviz executable ###########
add_executable(tinyros_rviz main.cpp visualizer_app.cpp ${RVIZ_SOURCES} ${MOC_FILES})

target_link_libraries(tinyros_rviz
  ${Boost_LIBRARIES}
  ${OGRE_OV_LIBRARIES_ABS}
  ${OPENGL_LIBRARIES}
  ${QT_LIBRARIES}
  ${rviz_ADDITIONAL_LIBRARIES}
  ${orocos_kdl_LIBRARIES}
  assimp
  yaml-cpp
  X11
  tinyxml
  ${Poco_LIBRARIES}
  curl
  urdfdom_model
)

if (UseQt5)
  target_link_libraries(tinyros_rviz Qt5::Widgets)
endif()

if(APPLE)
  set_target_properties(tinyros_rviz PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
endif(APPLE)

