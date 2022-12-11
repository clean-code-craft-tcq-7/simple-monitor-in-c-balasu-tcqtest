#include <stdio.h>
#include <assert.h>
#include "checker.h"
#include "analyze_value_range.h"

int main() {
  // Test for temperature, soc, charge current in range
  assert(batteryIsOk(25, 70, 0.7));
  // Test for temperature not in Range, soc and charge current in range
  assert(!batteryIsOk(50, 70, 0.5));
  // Test for temperature, charge current in range and soc out of range
  assert(!batteryIsOk(30, 85, 0.5));
  // Test for temperature, soc in range and charge current out of range
  assert(!batteryIsOk(30, 70, 0.9));
  
  // Test individual analyze functions --> analyzeTemperatureInRange
  assert(analyzeTemperatureInRange(20) == 1);
  assert(analyzeTemperatureInRange(0) == 1);
  assert(analyzeTemperatureInRange(45) == 1);
  assert(analyzeTemperatureInRange(-0.95) == 0);
  assert(analyzeTemperatureInRange(45.5) == 0);
  
  // Test individual analyze functions --> analyzeSocInRange
  assert(analyzeSocInRange(30) == 1);
  assert(analyzeSocInRange(20) == 1);
  assert(analyzeSocInRange(80) == 1);
  assert(analyzeSocInRange(19) == 0);
  assert(analyzeSocInRange(80.5) == 0);
  
  // Test individual analyze functions --> analyzeChargeRateInRange
  assert(analyzeChargeRateInRange(0.75) == 1);
  assert(analyzeChargeRateInRange(0.8) == 0);
  assert(analyzeChargeRateInRange(0.85) == 0);
}
