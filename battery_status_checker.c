#include <stdio.h>
#include <assert.h>
#include "product_config.h"
#include "analyze_value_range.h"
#include "print_functions.h"
#include "battery_status_checker.h"

int warningEnabled[MAX_ANALYSIS_SUPPORTED] = { 0,0,0};

void setWarningSupport(analysisType type, int value)
{
    warningEnabled[type] = value;
}

int batteryIsOk(float temperature, float soc, float chargeRate, void(*printFunc)(char*))
{
  int retStatus = 1;
  retStatus &= analyzeTemperatureInRange(temperature, printFunc, warningEnabled[TEMPERATURE_ANALYSIS]);
  retStatus &= analyzeSocInRange(soc,printFunc, warningEnabled[SOC_ANALYSIS]);
  retStatus &= analyzeChargeRateInRange(chargeRate, printFunc, warningEnabled[CHARGE_RATE_ANALYSIS]);
  
  return retStatus;
}


