cmake_minimum_required(VERSION 3.5.0)
project(sample_user)

find_package(sample_lib REQUIRED)

add_executable(sample_user src/main.cpp)
target_link_libraries(sample_user sample_lib::sample_lib)
