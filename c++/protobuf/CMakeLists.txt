cmake_minimum_required(VERSION 2.8)
project(Demo1)

include(cmake/ProtoBuf.cmake)

include_directories(${PROJECT_BINARY_DIR})

file(GLOB proto_files proto/*.proto)
caffe_protobuf_generate_cpp_py(${proto_gen_folder} proto_srcs proto_hdrs proto_python ${proto_files})


add_library(proto STATIC ${proto_hdrs} ${proto_srcs} ${proto_python})


add_executable(learn_proto learn_proto.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(learn_proto ${PROTOBUF_LIBRARIES} proto)
