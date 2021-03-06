/**
* \file Reverberation.cpp
*/

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <ATK/Reverberation/AllPassReverbFilter.h>
#include <ATK/Reverberation/LowPassReverbFilter.h>

namespace py = pybind11;

using namespace ATK;

namespace
{
  template<typename Filter, typename T>
  void populate_ReverbFilter(py::module& m, const char* type, T& parent)
  {
    py::class_<Filter>(m, type, parent)
    .def(py::init<std::size_t>(), py::arg("max_delay"))
    .def_property("delay", &Filter::get_delay, &Filter::set_delay)
    .def_property("feedback", &Filter::get_feedback, &Filter::set_feedback);
  }
}

PYBIND11_PLUGIN(PythonReverberation) {
  py::module m("PythonReverberation", "Audio ToolKit Reverberation module");

  py::object f1 = (py::object) py::module::import("ATK.Core").attr("FloatTypedBaseFilter");
  py::object f2 = (py::object) py::module::import("ATK.Core").attr("DoubleTypedBaseFilter");

  populate_ReverbFilter<AllPassReverbFilter<float>>(m, "FloatAllPassReverbFilter", f1);
  populate_ReverbFilter<AllPassReverbFilter<double>>(m, "DoubleAllPassReverbFilter", f2);
  populate_ReverbFilter<LowPassReverbFilter<float>>(m, "FloatLowPassReverbFilter", f1);
  populate_ReverbFilter<LowPassReverbFilter<double>>(m, "DoubleLowPassReverbFilter", f2);

  return m.ptr();
}
