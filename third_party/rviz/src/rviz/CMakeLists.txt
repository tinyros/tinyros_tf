find_package(PkgConfig)
pkg_check_modules(NEW_YAMLCPP yaml-cpp>=0.5)
if(NEW_YAMLCPP_FOUND)
  add_definitions(-DRVIZ_HAVE_YAMLCPP_05)
endif(NEW_YAMLCPP_FOUND)

#add_subdirectory(default_plugin)

include_directories(.)

include_directories(default_plugin)

include_directories(default_plugin/interactive_markers)

# Build the version number and other build-time constants into the
# source for access at run-time.
set(ENV_CONFIG_FILE ${PROJECT_SOURCE_DIR}/src/rviz/env_config.cpp)
set(RVIZ_VERSION 1.0)
message("making version ${RVIZ_VERSION}.")

configure_file(${PROJECT_SOURCE_DIR}/src/rviz/env_config.cpp.in ${ENV_CONFIG_FILE} @ONLY)

set(RVIZ_SOURCES
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/axes_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/camera_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/depth_cloud_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/depth_cloud_mld.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/effort_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/effort_visual.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/fluid_pressure_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/grid_cells_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/grid_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/illuminance_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/image_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_marker_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/integer_action.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/interactive_marker_control.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/interactive_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/interactive_marker_client.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/menu_handler.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/message_context.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/single_client.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/tools.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/interactive_markers/interactive_marker_server.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/laser_scan_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/laser_geometry.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/map_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/marker_array_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/marker_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/arrow_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/line_list_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/line_strip_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/marker_base.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/marker_selection_handler.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/mesh_resource_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/points_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/shape_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/text_view_facing_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/markers/triangle_list_marker.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/odometry_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/path_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/point_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/point_visual.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/point_cloud2_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/point_cloud_common.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/point_cloud_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/point_cloud_transformer.h
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/point_cloud_transformers.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/polygon_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/pose_array_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/pose_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/range_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/relative_humidity_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/robot_model_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/temperature_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tf_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/focus_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/measure_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/move_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/point_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/pose_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/goal_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/initial_pose_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/selection_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/tools/interaction_tool.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/view_controllers/orbit_view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/view_controllers/xy_orbit_view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/view_controllers/third_person_follower_view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/view_controllers/fixed_orientation_ortho_view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/view_controllers/fps_view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/wrench_display.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/default_plugin/wrench_visual.cpp
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
  ${PROJECT_SOURCE_DIR}/src/rviz/tool_factory.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/uniform_string_stream.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/view_controller.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/view_controller_factory.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/view_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/views_panel.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/visualization_frame.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/visualization_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/rviz/visualizer_app.cpp
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
  ${MOC_FILES}
)

add_library( ${PROJECT_NAME} ${RVIZ_SOURCES})

target_link_libraries(${PROJECT_NAME}
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
  target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
endif()

if(APPLE)
  set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
endif(APPLE)

########### The tinyros_rviz executable ###########
add_executable(tinyros_rviz_executable main.cpp)
target_link_libraries(tinyros_rviz_executable ${PROJECT_NAME})

if (UseQt5)
  target_link_libraries(tinyros_rviz_executable Qt5::Widgets)
endif()

set_target_properties(tinyros_rviz_executable PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

########### The tinyros_image_view executable ###########
add_executable(tinyros_image_view image_view/image_view.cpp image_view/main.cpp ${MOC_FILES})

target_link_libraries(tinyros_image_view ${PROJECT_NAME} ${QT_LIBRARIES} ${OGRE_OV_LIBRARIES_ABS})

