cmake_minimum_required(VERSION 3.10)

project(yaml-cpp-sample)

set(CMAKE_CXX_STANDARD 14)

find_package(yaml-cpp REQUIRED)

include_directories(${YAML_CPP_INCLUDE_DIR})

add_executable(data-emit src/data_emit.cpp)
target_link_libraries(data-emit ${YAML_CPP_LIBRARIES})

add_executable(data-read src/data_read.cpp)
target_link_libraries(data-read ${YAML_CPP_LIBRARIES})
