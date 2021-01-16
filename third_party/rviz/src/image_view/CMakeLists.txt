
add_executable(tinyros_rviz_image_view
  image_view.cpp
  main.cpp
  ${MOC_FILES}
)

target_link_libraries(tinyros_rviz_image_view
  ${OGRE_OV_LIBRARIES_ABS}
  ${rviz_ADDITIONAL_LIBRARIES}
  ${PROJECT_NAME}
)

set_target_properties(tinyros_rviz_image_view
                      PROPERTIES OUTPUT_NAME tinyros_image_view
                      PREFIX "")

