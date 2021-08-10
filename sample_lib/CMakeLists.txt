cmake_minimum_required(VERSION 3.5.0)
project(SampleProject)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)


add_library(sample_lib SHARED src/sample_lib/sample_lib.cpp)
set_target_properties(sample_lib PROPERTIES PUBLIC_HEADER src/sample_lib/sample_lib.h)
target_include_directories(sample_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/sample_lib>
    $<INSTALL_INTERFACE:include/sample_lib>)

add_executable(sample_exec src/sample_exec/sample_exec.cpp)
target_include_directories(sample_exec PUBLIC src/sample_lib)
target_link_libraries(sample_exec PUBLIC sample_lib)

install(TARGETS sample_exec
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include/sample_lib)

install(TARGETS sample_lib
    EXPORT sample_lib_targets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include/sample_lib)

install(EXPORT sample_lib_targets
    FILE sample_lib_targets.cmake
    NAMESPACE sample_lib::
    DESTINATION lib/cmake/sample_lib)

install(FILES "cmake/sample_libConfig.cmake"
        DESTINATION lib/cmake/sample_lib/)

# cpack for generating debain package
set(CPACK_PACKAGE_VENDOR "GNU")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Anonymous")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A very simple package")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 0)

include(CPack)
