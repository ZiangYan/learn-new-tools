cmake_minimum_required(VERSION 2.8.3)
find_package(PythonInterp)
find_package(PythonLibs)
find_package(Boost COMPONENTS python)

# include
include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
python_add_module(hello classes.cpp)
target_link_libraries(hello ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
