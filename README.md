# Traffic accounting service

This is a simple server to query traffic accounting data.

## Requirements

To compile this you need:

* Cmake
* Google Protobuf
* ZeroMQ
* Boost.Program_options

## How to build

First make all requirements available, then:

    git clone git@github.com:agdsn/traffic-service-server.git
    cd traffic-service-server
    git submodule init
    git submodule update
    
    mkdir build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Debug
    make

## Commandline options

    -h [ --help ]               Print help message.
    -b [ --bind ] arg (=*:3444) address:port combinations to bind to

