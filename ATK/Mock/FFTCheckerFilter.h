/**
 * \file FFTCheckerFilter.h
 */

#ifndef ATK_MOCK_FFTCHECKERFILTER_H
#define ATK_MOCK_FFTCHECKERFILTER_H

#include <ATK/Mock/config.h>

#include <ATK/Core/TypedBaseFilter.h>

namespace ATK
{
  template<class DataType>
  class FFT;
  
  /// Checks the input signal has a specific spectrum template
  template<class DataType_>
  class ATK_MOCK_EXPORT FFTCheckerFilter final: public TypedBaseFilter<DataType_>
  {
  public:
    /// Simplify parent calls
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::converted_inputs;
    using Parent::input_sampling_rate;
    
    /// Constructor
    FFTCheckerFilter();
    /// Destructor
    ~FFTCheckerFilter() override;
    
    /// Sets the template we require
    void set_checks(const std::vector<std::pair<int, DataType> >& frequency_checks);
    
  protected:
    void process_impl(std::size_t size) const final;
    void setup() final;

  private:
    std::vector<std::pair<int, DataType> > frequency_checks;
    std::unique_ptr<FFT<DataType> > FFTimpl;
  };
}

#endif
