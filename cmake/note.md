###
增加新库：
1. 在子目录下写CMakeLists.txt, 内容是add_library()
2. 顶层CMakeLists.txt使用add_subdirectory()
3. 在顶层CMakeLists.txt加入库的包含目录
4. 在顶层CMakeLists.txt的target_link_libraries里加入该库

###
option:
1. option(变量名 "描述文字" 默认值)
2. configure_file(模板文件 h文件)
3. 注意!!options一定要放在configure_file前面,默认值才能发挥作用.否则只能cmake .. -D变量名

###

