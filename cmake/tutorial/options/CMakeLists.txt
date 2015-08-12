cmake_minimum_required(VERSION 2.8)

# 项目信息
project(Demo1)

# 可选项
option(USE_MYMATH "Use my math implementation" ON)
if(USE_MYMATH)
    message("Use my math implementation")
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
else()
    message("Use system provided math implementation")
endif(USE_MYMATH)

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )

include_directories(${PROJECT_BINARY_DIR})

# 寻找源文件
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

# 指定链接库
target_link_libraries(Demo ${EXTRA_LIBS})
