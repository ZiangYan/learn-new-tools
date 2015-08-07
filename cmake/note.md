### 增加新库

1. 在子目录下写CMakeLists.txt, 内容是```add_library()```
2. 顶层CMakeLists.txt使用```add_subdirectory()```
3. 在顶层CMakeLists.txt加入库的包含目录
4. 在顶层CMakeLists.txt的```target_link_libraries```里加入该库
5. 可用```aux_source_directory(. LIB_DIR_SRCS)```遍历.目录下所有源文件，并把它们放入变量```LIB_DIR_SRCS```当中

### option
1. 增加选项，在cmake中用```option(变量名 "描述文字" 默认值)```
2. 要在C文件中读取cmake中定义的选项，就要在cmake中用```configure_file(模板文件 h文件)```命令。其原理是从一个模板文件（通常以.h.in为后缀）出发，把模板文件中的值用CMakeLists.txt计算一次，然后生成符合C/C++规范的.h文件。例如，在CMakeListst.txt中定义了```USE_MYMATH```选项，在模板文件中加入```#cmakedefine USE_MYMATH```，则cmake会按照CMakeLists.txt中的该变量的值在.h文件中生成```#define USE_MYMATH```或者```/* #undef USE_MYMATH */```。如果在模板文件中加入```#cmakedefine01  USE_MYMATH```，则cmake会在.h文件中生成```#define USE_MYMATH 0```或者```#define USE_MYMATH 1```，视该变量的真假而定。
3. 注意!!```options```一定要放在```configure_file```前面,默认值才能发挥作用.否则只能用```cmake .. -D变量名```方式来设定CMakeLists.txt文件中变量的值。
4. 同一个变量多次添加option，默认值以第一次option为准。例如，

   option(FOO "Some variable" ON)
   option(FOO "Some variable" OFF)

这两句执行之后，FOO变量默认为ON。

### foreach
1. 其基本语法为

    foreach(arg arg0 arg1 arg2 ...)

2. 如果有一个list变量x,也可以采用

    foreach(arg ${x})
      #do something
      ...
    endforeach()

### DEFINED
1. 判断变量FOO是否被定义过，可以用

    if(DEFINED FOO)
      #do something
      ...
    endif()

而不是

    if(DEFINED ${FOO})
      #do something
      ...
    endif()

因为```${FOO}```会把FOO替换为其内容（不妨假设为"abc"）。命令就变成了```if(DEFINED "abc")```，我们无从判断"abc"是否被定义过。因此DEFINED都直接采用原名，而非其值。

### 定义函数
1. 如下代码定义了两个参数的函数```fun````

    function(fun arg0 arg1)
      #do something
      ...
    endfunction()

2. 可以用```ARGN```变量收集多余参数，例如用如下方式调用函数

    fun(a b c d e)

在函数体中，```ARGN```变量就会把两个参数以外的参数全部收集起来形成list，可以用```foreach```遍历：

    function(fun arg0 arg1)
      #do something
      ...
      foreach(arg ${ARGN}) #用${ARGN}展开list
        #do something
        ...
      endforeach()
    endfunction()


