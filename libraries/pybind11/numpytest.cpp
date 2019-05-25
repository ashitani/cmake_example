#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;
using namespace std;


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
}