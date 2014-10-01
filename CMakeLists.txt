cmake_minimum_required (VERSION 3.0)
project (traffic-service)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS program_options REQUIRED)

find_package(Protobuf REQUIRED)



find_package(PkgConfig)
pkg_check_modules(PC_ZMQ REQUIRED libzmq>=3.0)
find_library(ZMQ_LIBRARIES NAMES zmq libzmq
             HINTS ${PC_ZMQ_LIBDIR} ${PC_ZMQ_LIBRARY_DIRS})


add_definitions(-std=c++11)

add_subdirectory(messages)
add_subdirectory(backend)
add_subdirectory(server)
