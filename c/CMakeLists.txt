cmake_minimum_required(VERSION 2.8.7)
project(librtcm)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake/common")

include(GNUInstallDirs)
include(SwiftCmakeOptions)
swift_create_project_options(
    HAS_TESTS
    )

include(ClangFormat)
swift_setup_clang_format()

include(ClangTidy)

add_subdirectory (src)

if(librtcm_BUILD_TESTS)
  add_subdirectory (test)
endif()

swift_setup_clang_tidy()
