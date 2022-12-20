#include <stdio.h>
#include <assert.h>

#include "product_config.h"
#include "battery_status_checker.h"
#include "print_functions.h"
#include "analyze_value_range.h"

int main() {

  setPrintLanguage(ENGLISH);
  // Test for temperature, soc, charge current in range
  assert(batteryIsOk(25, 70, 0.7, &printToConsole));

  // Test for temperature less than min, soc and charge current in range
  assert(!batteryIsOk(8, 70, 0.5,&printToConsole));
  // Test for temperature greater than max, soc and charge current in range
  assert(!batteryIsOk(46, 70, 0.5,&printToConsole));

  // Test for soc less than min and temperature, charge current in range
  assert(!batteryIsOk(25, 10, 0.5,&printToConsole));
  // Test for soc greater than max and temperature, charge current in range
  assert(!batteryIsOk(25, 81, 0.5,&printToConsole));

  // Test for charge current greater than max and temperature,soc  in range
  assert(!batteryIsOk(25, 70, 0.9,&printToConsole));

  // Temperature test with warning enabled
  setWarningSupport(TEMPERATURE_ANALYSIS, 1);
  // Test for temperature greater than min and less than tolerance, soc and charge current in range
  assert(batteryIsOk(11.5, 70, 0.5,&printToConsole));
  // Test for temperature greater than tolerance and less than max, soc and charge current in range
  assert(batteryIsOk(44.5, 70, 0.5,&printToConsole));

  // SOC test with warning enabled
  setWarningSupport(SOC_ANALYSIS, 1);
  // Test for SOC greater than min and less than tolerance, temperature and charge current in range
  assert(batteryIsOk(25, 22, 0.5,&printToConsole));
  // Test for SOC greater than tolerance and less than max, temperature and charge current in range
  assert(batteryIsOk(25, 77.5, 0.5,&printToConsole));

  // SOC test with warning enabled
  setWarningSupport(CHARGE_RATE_ANALYSIS, 1);
  // Test for charge current greater than tolerance and less than max, temperature and SOC in range
  assert(batteryIsOk(25, 50, 0.787,&printToConsole));

  return 0;
}
