#include <stdio.h>
#include "analyze_value_range.h"

void printError(char* errStr)
{
  printf("%s", errStr);
}

int analyzeTemperatureInRange(float temperature)
{
  int retStatus = 1;
  if(temperature < 0 || temperature > 45) 
  {
    printError("Temperature out of range!\n");
    retStatus = 0;
  }
  return retStatus;
}

int analyzeSocInRange(float soc)
{
  int retStatus = 1;
  if(soc < 20 || soc > 80)
  {
    printError("State of Charge out of range!\n");
    retStatus = 0;
  }
  return retStatus;
}

int analyzeChargeRateInRange(float chargeRate)
{
  int retStatus = 1;
  if(chargeRate > 0.8)
  {
    printError("Charge Rate out of range!\n");
    retStatus = 0;
  }
  return retStatus;
}
