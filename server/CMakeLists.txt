file(GLOB server_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(traffic_service ${server_SOURCES})

link_libraries(traffic_service messages)
link_libraries(traffic_service backend)

