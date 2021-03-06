#include <chrono>
#include <cassert>
#include "calculation_time.hpp"

namespace TrRouting
{

  long long CalculationTime::getEpoch()
  {
    calculationEpoch = std::chrono::duration_cast< std::chrono::microseconds >(
      std::chrono::system_clock::now().time_since_epoch()
    );
    return calculationEpoch.count();
  }
  
  void CalculationTime::start()
  {
    startEpoch = getEpoch();
  }
  
  void CalculationTime::stop()
  {
    endEpoch = getEpoch();
  }
  
  long long CalculationTime::getDurationMicroseconds()
  {
    assert(startEpoch && endEpoch && startEpoch >= 0 && endEpoch >= 0 && endEpoch >= startEpoch);
    return endEpoch - startEpoch;
  }
  
  long long CalculationTime::getDurationMicrosecondsNoStop()
  {
    long long actualEpoch {getEpoch()};
    assert(startEpoch && actualEpoch && startEpoch >= 0 && actualEpoch >= 0 && actualEpoch >= startEpoch);
    return actualEpoch - startEpoch;
  }
  
  void CalculationTime::startStep()
  {
    startStepEpoch = getEpoch();
  }
  
  void CalculationTime::stopStep()
  {
    endStepEpoch = getEpoch();
  }
  
  long long CalculationTime::getStepDurationMicroseconds()
  {
    assert(startStepEpoch && endStepEpoch && startStepEpoch >= 0 && endStepEpoch >= 0 && endStepEpoch >= startStepEpoch);
    return endStepEpoch - startStepEpoch;
  }
  
  //CalculationTime CalculationTime::algorithmCalculationTime;
  
}
