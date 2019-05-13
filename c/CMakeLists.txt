cmake_minimum_required(VERSION 2.8.7)
project(librtcm)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake/common")

include(GNUInstallDirs)
include(SwiftCmakeOptions)

add_subdirectory (src)

if(librtcm_BUILD_TESTS)
  add_subdirectory (test)
endif()
