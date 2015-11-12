#include <boost/python.hpp>
#include <iostream>
namespace bp = boost::python;

std::string greet() {
    return "hello, world";
}


BOOST_PYTHON_MODULE(hello) {
    bp::def("greet", greet);
}
