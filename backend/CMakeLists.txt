file(GLOB server_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(backend STATIC ${server_SOURCES})
