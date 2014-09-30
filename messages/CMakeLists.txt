file(GLOB ProtoFiles "${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto")

PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})

add_library(messages SHARED ${ProtoSources} ${ProtoHeaders})

target_include_directories(messages PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(messages ${Boost_LIBRARIES} ${PROTOBUF_LIBRARY})
