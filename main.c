#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "product_config.h"
#include "battery_status_checker.h"
#include "print_functions.h"
#include "analyze_value_range.h"
#include "print_messages.h"
#include "check_value_breach.h"

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


  // Test print functions
  setPrintLanguage(ENGLISH);
  char testString[50];
    // Test temperature English messages
    printTempratureMessage(LOW_VALUE_WARNING, testString);
    assert(strcmp(testString, "Low Temperature Warning\n") == 0);
    printTempratureMessage(HIGH_VALUE_WARNING, testString);
    assert(strcmp(testString, "High Temperature Warning\n") == 0);
    printTempratureMessage(LOW_VALUE_BREACH, testString);
    assert(strcmp(testString, "Low Temperature Breach\n") == 0);
    printTempratureMessage(HIGH_VALUE_BREACH, testString);
    assert(strcmp(testString, "High Temperature Breach\n") == 0);

    // Test SOC English messages
    printSOCMessage(LOW_VALUE_WARNING, testString);
    assert(strcmp(testString, "Low SOC Warning\n") == 0);
    printSOCMessage(HIGH_VALUE_WARNING, testString);
    assert(strcmp(testString, "High SOC Warning\n") == 0);
    printSOCMessage(LOW_VALUE_BREACH, testString);
    assert(strcmp(testString, "Low SOC Breach\n") == 0);
    printSOCMessage(HIGH_VALUE_BREACH, testString);
    assert(strcmp(testString, "High SOC Breach\n") == 0);

    // Test Charge rate English messages
    printChargeRateMessage(LOW_VALUE_WARNING, testString);
    assert(strcmp(testString, "Low Charge Rate Warning\n") == 0);
    printChargeRateMessage(HIGH_VALUE_WARNING, testString);
    assert(strcmp(testString, "High Charge Rate Warning\n") == 0);
    printChargeRateMessage(LOW_VALUE_BREACH, testString);
    assert(strcmp(testString, "Low Charge Rate Breach\n") == 0);
    printChargeRateMessage(HIGH_VALUE_BREACH, testString);
    assert(strcmp(testString, "High Charge Rate Breach\n") == 0);

    // Test print functions
    setPrintLanguage(GERMAN);

    // Test temperature German messages
    printTempratureMessage(LOW_VALUE_WARNING, testString);
    assert(strcmp(testString, "Warnung vor niedriger Temperatur\n") == 0);
    printTempratureMessage(HIGH_VALUE_WARNING, testString);
    assert(strcmp(testString, "Warnung vor hoher Temperatur\n") == 0);
    printTempratureMessage(LOW_VALUE_BREACH, testString);
    assert(strcmp(testString, "Niedrige Temperaturverletzung\n") == 0);
    printTempratureMessage(HIGH_VALUE_BREACH, testString);
    assert(strcmp(testString, "Hohe Temperaturverletzung\n") == 0);

    // Test SOC German messages
    printSOCMessage(LOW_VALUE_WARNING, testString);
    assert(strcmp(testString, "Niedrige SOC-Warnung\n") == 0);
    printSOCMessage(HIGH_VALUE_WARNING, testString);
    assert(strcmp(testString, "Warnung zu hohem SOC\n") == 0);
    printSOCMessage(LOW_VALUE_BREACH, testString);
    assert(strcmp(testString, "Niedrige SOC-Verletzung\n") == 0);
    printSOCMessage(HIGH_VALUE_BREACH, testString);
    assert(strcmp(testString, "Hohe SOC-Verletzung\n") == 0);

    // Test Charge rate German messages
    printChargeRateMessage(LOW_VALUE_WARNING, testString);
    assert(strcmp(testString, "Warnung zu niedrigem Ladestrom\n") == 0);
    printChargeRateMessage(HIGH_VALUE_WARNING, testString);
    assert(strcmp(testString, "Warnung vor hoher Laderate\n") == 0);
    printChargeRateMessage(LOW_VALUE_BREACH, testString);
    assert(strcmp(testString, "Verstoß gegen niedrige Gebührenrate\n") == 0);
    printChargeRateMessage(HIGH_VALUE_BREACH, testString);
    assert(strcmp(testString, "Verstoß gegen hohe Gebührenrate\n") == 0);

  return 0;
}
