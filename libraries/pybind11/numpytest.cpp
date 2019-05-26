#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>

namespace py = pybind11;
using namespace std;

#include <Eigen/Dense>

// https://pybind11.readthedocs.io/en/stable/advanced/cast/eigen.html

class MyClass
{
private:
    Eigen::MatrixXd ary;

public:
    Eigen::MatrixXd &ones(int, int);
};

Eigen::MatrixXd &MyClass::ones(int ny, int nx)
{
    ary = Eigen::MatrixXd::Zero(ny, nx);

    for (int y = 0; y < ny; ++y)
    {
        for (int x = 0; x < nx; ++x)
        {
            ary(y, x) = 1;
        }
    }

    return ary;
}

py::array_t<int> ones(int ny, int nx)
{
    vector<int> arraysize{ny, nx};
    py::array_t<int> ary{arraysize};

    for (int y = 0; y < ny; ++y)
    {
        for (int x = 0; x < nx; ++x)
        {
            *ary.mutable_data(y, x) = 1;
        }
    }

    return ary;
}

py::tuple oneses(int ny0, int nx0, int ny1, int nx1)
{

    return py::make_tuple(ones(ny0, nx0), ones(ny1, nx1));
}

PYBIND11_MODULE(numpytest, m)
{
    m.doc() = "pybind11 example plugin";
    m.def("ones", &ones, "A function which returns ones array");
    m.def("oneses", &oneses, "A function which returns ones array x2");

    py::class_<MyClass>(m, "MyClass")
        .def(py::init<>())
        .def("ones", &MyClass::ones, py::return_value_policy::reference_internal); // reference
    //        .def("ones", &MyClass::ones); //copy
}