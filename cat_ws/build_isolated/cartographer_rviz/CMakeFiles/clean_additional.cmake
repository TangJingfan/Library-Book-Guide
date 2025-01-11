# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/cartographer_rviz_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/cartographer_rviz_autogen.dir/ParseCache.txt"
  "cartographer_rviz_autogen"
  )
endif()
