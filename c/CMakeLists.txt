cmake_minimum_required(VERSION 3.2)
project(librtcm LANGUAGES C CXX VERSION 0.2.41)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake/common")

include(GNUInstallDirs)
include(CCache)
include(SwiftCmakeOptions)
swift_create_project_options(
    HAS_TESTS
    )

include(ClangFormat)
swift_setup_clang_format()

include(ClangTidy)
swift_setup_clang_tidy(PATTERNS "src/*.c")

include(SwiftPackageHelpers)

add_subdirectory (src)

if(librtcm_BUILD_TESTS)
  add_subdirectory (test)
endif()

