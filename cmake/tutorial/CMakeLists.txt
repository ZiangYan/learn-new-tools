cmake_minimum_required(VERSION 2.6)
project(Tutorial)

# 版本号
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# 可选库
option( USE_MYMATH "Use tutorial provided math implementation" ON )

# 配置一个头文件，通过它向源代码中传递一些设置
configure_file(
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.cmake"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
  

if(USE_MYMATH)
  include_directories("${PROJECT_SRC_DIR}/MathFunctions")
  add_subdirectory(MathFunctions)
  set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH) 

# 讲二进制文件树天价到包含文件的搜索目录中，以便源代码能够找到TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")

# 添加可执行文件
add_executable(Tutorial tutorial.cxx)
target_link_libraries(Tutorial ${EXTRA_LIBS})


# 安装
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# Test
 # 应用程序是否运行?
add_test (TutorialRuns Tutorial 25)
 
# 它是否对25做了开平方运算
add_test (TutorialComp25 Tutorial 25)
  
set_tests_properties (TutorialComp25
  PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
 
# 它是否能处理是负数作为输入的情况
add_test (TutorialNegative Tutorial -25)
set_tests_properties (TutorialNegative
  PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")
 
# 它是否可以处理较小的数字。
add_test (TutorialSmall Tutorial 0.0001)
set_tests_properties (TutorialSmall
  PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
 
# 用法信息是否可用？
add_test (TutorialUsage Tutorial)
set_tests_properties (TutorialUsage
  PROPERTIES
  PASS_REGULAR_EXPRESSION "Usage:.*number")
