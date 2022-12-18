#include <stdio.h>
#include "product_config.h"
#include "analyze_value_range.h"
#include "check_value_breach.h"

int analyzeTemperatureInRange(float temperature, (void)(*printFunc)(int rangeStatus), int warningEnabled)
{
  int retStatus = 1;
  valueRangeStatus rangeStatus = chackValueRange(TEMPERATURE_MIN_VALUE, TEMPERATURE_MAX_VALUE, temperature, warningEnabled);
  
  if(rangeStatus > NORMAL)
  {
	  retStatus = 0;
	  printFunc(rangeStatus)
  }
  return retStatus;
}

int analyzeSocInRange(float soc, (void)(*printFunc)(int rangeStatus), int warningEnabled)
{
  int retStatus = 1;
  valueRangeStatus rangeStatus = chackValueRange(SOC_MIN_VALUE, SOC_MAX_VALUE, soc, warningEnabled);
  
  if(rangeStatus > NORMAL)
  {
	  retStatus = 0;
	  printFunc(rangeStatus)
  }
  return retStatus;
}

int analyzeChargeRateInRange(float chargeRate, (void)(*printFunc)(int rangeStatus))
{
  int retStatus = 1;
  if(chargeRate > CHARGE_RATE_MAX_VALUE)
  {
    printFunc(HIGH_VALUE_BREAH);
    retStatus = 0;
  }
  return retStatus;
}