#include <boost/python.hpp>
#include <iostream>
#include <boost/lexical_cast.hpp>
namespace bp = boost::python;


class World {
public:
    World(std::string msg): msg(msg) {}
    World(double x, double y) { this->msg = boost::lexical_cast<std::string>(x); }
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }
    std::string msg;
};


BOOST_PYTHON_MODULE(hello) {
    bp::class_<World>("World", bp::init<std::string>())
        .def(bp::init<double, double>())
        .def("greet", &World::greet)
        .def("set", &World::set);
}
