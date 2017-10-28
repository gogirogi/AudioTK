/**
 * \file DecimationFilter.cpp
 */

#include <ATK/Tools/DecimationFilter.hxx>

#include <complex>
#include <cstdint>

namespace ATK
{
  template class DecimationFilter<std::int16_t>;
  template class DecimationFilter<std::int32_t>;
  template class DecimationFilter<int64_t>;
  template class DecimationFilter<float>;
  template class DecimationFilter<double>;
  template class DecimationFilter<std::complex<float>>;
  template class DecimationFilter<std::complex<double>>;
}
