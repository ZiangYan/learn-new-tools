cmake_minimum_required(VERSION 2.8)
project(learn_opencv)

find_package(OpenCV)

add_executable(demo main.cpp)
target_link_libraries(demo ${OpenCV_LIBRARIES})
