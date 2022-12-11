#include <stdio.h>
#include <assert.h>
#include "analyze_value_range.h"
#include "checker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  int retStatus = 1;
  
  retStatus &= analyzeTemperatureInRange(temperature);
  retStatus &= analyzeSocInRange(soc);
  retStatus &= analyzeChargeRateInRange(chargeRate);
  
  return retStatus;
}

