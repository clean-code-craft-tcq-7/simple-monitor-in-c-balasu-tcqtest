#include <stdio.h>
#include <assert.h>
#include "analyze_value_range.h"
#include "print_functions.h"
#include "checker.h"

int batteryIsOk(float temperature, float soc, float chargeRate, int warningEnabled) 
{
  int retStatus = 1;
  
  retStatus &= analyzeTemperatureInRange(temperature, &printTempratureMessage, warningEnabled);
  retStatus &= analyzeSocInRange(soc,&printSOCMessage, warningEnabled);
  retStatus &= analyzeChargeRateInRange(chargeRate, &printChargeRateMessage, warningEnabled);
  
  return retStatus;
}


