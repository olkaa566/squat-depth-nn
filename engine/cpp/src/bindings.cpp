#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../include/matrix.hpp"

namespace py = pybind11;

PYBIND11_MODULE(cpp_engine, m) {
    m.doc() = "Custom C++ Math Engine for Neural Networks";

    // 1. Expose the Matrix Class
    py::class_<Matrix>(m, "Matrix")
        .def(py::init<int, int>())
        .def(py::init<int, int, const std::vector<float>&>())
        .def("get_rows", &Matrix::get_rows)
        .def("get_columns", &Matrix::get_columns)
        .def("get_data", &Matrix::get_data)
        .def("transpose", &Matrix::transpose)
        .def("dot", &Matrix::dot);

    // 2. Expose Geometry
    m.def("calculate_joint_angle", &calculate_joint_angle);

    // 3. Expose the AI Brain
    py::class_<MultiLayerPerceptron>(m, "MultiLayerPerceptron")
        .def(py::init<int, int, int, float>(), 
             py::arg("input_nodes"), py::arg("hidden_nodes"), py::arg("output_nodes"), py::arg("lr") = 0.01f)
        .def("forward", &MultiLayerPerceptron::forward)
        .def("train", &MultiLayerPerceptron::train);
}