# Traffic accounting service

This is a simple server to query traffic accounting data.

## Requirements

To compile this you need:

* Cmake
* Google Protobuf
* ZeroMQ
* Boost.Program_options

### Installing

|Program|Command|
|---|---|
    Cmake 3.0+|`export fn=/tmp/cmake.sh && ls $fn && (echo "use previous $fn? Enter for yes, ctrl+d for no." && read) || (wget -O $fn http://www.cmake.org/files/v3.0/cmake-3.0.2-Linux-i386.sh 1>&2) && (cd /opt && sudo bash ${fn} && echo sudo ln -f -s /opt/cmake*/bin/cmake /usr/local/bin/cmake && cd -)`
    Google Protobuf|`sudo apt-get install protobuf-compiler protobuf-c-compiler`
    ZeroMQ|`sudo apt-get install libzmq3-dev libzmq3-dbg`
    Boost.Program_options|`sudo apt-get install libboost-program-options-dev`

## How to build

First make all requirements available, then:

    $ git clone git@github.com:agdsn/traffic-service-server.git
    $ cd traffic-service-server
    $ git submodule init
    $ git submodule update
    
    $ mkdir build
    $ cd build
    $ cmake .. -DCMAKE_BUILD_TYPE=Debug
    $ make

## Commandline options

    -h [ --help ]               Print help message.
    -b [ --bind ] arg (=*:3444) address:port combinations to bind to

## How to use in CodeBlocks

Install Code::Blocks and create `Makefile`:

    sudo apt-get install codeblocks
    ls CMakeLists.txt && cmake -DCMAKE_BUILD_TYPE=Debug

Then

1. Create new project of `Console application` in Codeblocks, ensure that path for `*.cbp` file reminds following tree:

        | + traffic-server-service
        |   + TSS (Code::Blocks project)
        |     - project.cbp
        |   - CMakeLists.txt

2. right click on project and select `Add recursively files` and add all `*.cpp,*.h` files from project directory,
3. right click on project, select `Properties...`, select `[x] This is custom Makefile`,
4. change `Execution directory` to that one which will directly contains `CMakeLists.txt`,
5. right click on the project, go to `Properties...`, then `Build targets` and rename _Debug_ build target to `all` (CMake by default generates target `all`),
    * also change `Output filename` to `../server/traffic_service` (so CB will know where executable file is located),
6. now you can run project from Code::Blocks (even in debug mode - `F8`).

## Contributing

As long as this is developed by a single person (me) I will push
directly to this repository. When someone want to join, we should
clone our personal copies and synchronize via pull-requensts.

## FAQ

### Error: `PROTOBUF_GENERATE_CPP()` called without any proto files

If while building Makefile:

    $ cmake -G 'CodeBlocks - Unix Makefiles'

Such an error occcurs, then definitely submodules are not initialized correctly:

    ...
    CMake Error at /opt/cmake-3.0.2-Linux-i386/share/cmake-3.0/Modules/FindProtobuf.cmake:144 (message):
      Error: PROTOBUF_GENERATE_CPP() called without any proto files
    Call Stack (most recent call first):
      messages/CMakeLists.txt:3 (PROTOBUF_GENERATE_CPP)

#### Answer

Then you should ensure that submodules were initialized correctly:

    git submodule init # or git submodule update --init

Remember that Git will not reinitialize submodule until it exists in the index,
so in order to reset submodule, execute:

    git reset -- 'messages/proto' && git submodule update 'messages/proto' || (cd messages/proto && git checkout master) && ls messages/proto

_Command after `||` (double pipe) ensures that even if one has executed `rm messages/proto/*`, state of submodule will be reset._

### Error: `PROTOBUF_PROTOC_EXECUTABLE-NOTFOUND: not found`

If executing

    cmake -G 'CodeBlocks - Unix Makefiles' && make

results in:

    /bin/sh: 1: PROTOBUF_PROTOC_EXECUTABLE-NOTFOUND: not found
    make[2]: *** [messages/test.pb.cc] Error 127
    make[1]: *** [messages/CMakeFiles/messages.dir/all] Error 2
    make: *** [all] Error 2

Then there is no Google Protobuf installed.
