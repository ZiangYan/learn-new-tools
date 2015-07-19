### 增加新库

1. 在子目录下写CMakeLists.txt, 内容是add\_library()
2. 顶层CMakeLists.txt使用add\_subdirectory()
3. 在顶层CMakeLists.txt加入库的包含目录
4. 在顶层CMakeLists.txt的target\_link\_libraries里加入该库
5. 可用aux\_source\_directory(. LIB\_DIR\_SRCS)遍历.目录下所有源文件，并把它们放入变量LIB\_DIR\_SRCS当中

### option
1. 增加选项，在cmake中用```option(变量名 "描述文字" 默认值)```
2. 要在C文件中读取cmake中定义的选项，就要在cmake中用```configure_file(模板文件 h文件)```命令。其原理是从一个模板文件（通常以.h.in为后缀）出发，把模板文件中的值用CMakeLists.txt计算一次，然后生成符合C/C++规范的.h文件。例如，在CMakeListst.txt中定义了```USE_MYMATH```选项，在模板文件中加入```#cmakedefine USE_MYMATH```，则cmake会按照CMakeLists.txt中的该变量的值在.h文件中生成```#define USE_MYMATH```或者```/* #undef USE_MYMATH */```。如果在模板文件中加入```#cmakedefine01
   USE_MYMATH```，则cmake会在.h文件中生成```#define USE_MYMATH 0```或者```#define USE_MYMATH 1```，视该变量的真假而定。
3. 注意!!```options```一定要放在```configure_file```前面,默认值才能发挥作用.否则只能用```cmake .. -D变量名```方式来设定CMakeLists.txt文件中变量的值。

###

