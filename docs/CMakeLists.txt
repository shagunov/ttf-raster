find_program(DOXYGEN_PATH doxygen REQUIRED)

if(DOXYGEN_PATH_NOTFOUND)
  message(FATAL_ERROR "Doxygen is needed to build the documentation. Please install it on your system")
  else()
     message(STATUS "Doxygen found.")
     add_custom_target(documentation COMMAND ${DOXYGEN_PATH} ${CMAKE_CURRENT_LIST_DIR}/Doxyfile WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                     BYPRODUCTS ${CMAKE_BINARY_DIR}/html/index.html)
     add_custom_command(
     TARGET documentation POST_BUILD COMMAND echo "Documentation successfully generated. You can preview at: ${CMAKE_BINARY_DIR}/html/index.html")
endif()