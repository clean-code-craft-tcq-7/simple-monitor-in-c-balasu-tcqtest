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
  // Test for temperature not in Range, soc and charge current in range
  assert(!batteryIsOk(8, 70, 0.5,&printToConsole));
  // Test for temperature, charge current in range and soc out of range
  assert(!batteryIsOk(30, 85, 0.5, &printToConsole));
  // Test for temperature, soc in range and charge current out of range
  assert(!batteryIsOk(30, 70, 0.9, &printToConsole));
  setWarningSupport(CHARGE_RATE_ANALYSIS, 1);
  assert(batteryIsOk(25, 70, 0.79, &printToConsole));
  return 0;
}
