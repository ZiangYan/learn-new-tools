cmake_minimum_required(VERSION 2.8)

# 项目信息
project(Demo1)

# 编译库
add_subdirectory(math)

# 寻找源文件
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

# 指定链接库
target_link_libraries(Demo MathFunctions)
