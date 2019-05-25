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

PYBIND11_MODULE(numpytest, m)
{
    m.doc() = "pybind11 example plugin";
    m.def("ones", &ones, "A function which returns ones array");
}