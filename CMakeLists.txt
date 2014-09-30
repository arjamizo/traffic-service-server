project(traffic-service-server)
cmake_minimum_required(VERSION 2.8.12)

add_definitions(-std=c++11)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS program_options REQUIRED)

find_package(Protobuf REQUIRED)

add_subdirectory(messages)
