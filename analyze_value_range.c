#include <stdio.h>
#include <float.h>
#include "product_config.h"
#include "analyze_value_range.h"
#include "check_value_breach.h"
#include "print_functions.h"

int analyzeTemperatureInRange(float temperature, void (*printFunc)(char*), int warningEnabled)
{
    int retStatus = 1;

    valueRangeStatus rangeStatus = chackValueRange(TEMPERATURE_MIN_VALUE, TEMPERATURE_MAX_VALUE,
                    temperature, TEMPERATURE_TOLERANCE, warningEnabled);

    if(rangeStatus > HIGH_VALUE_WARNING)
    {
        retStatus = 0;
    }
    printTempratureMessage(rangeStatus, printFunc);

    return retStatus;
}

int analyzeSocInRange(float soc, void (*printFunc)(char*), int warningEnabled)
{
    int retStatus = 1;

    valueRangeStatus rangeStatus = chackValueRange(SOC_MIN_VALUE, SOC_MAX_VALUE, soc,
                    SOC_TOLERANCE, warningEnabled);

    if(rangeStatus > HIGH_VALUE_WARNING)
    {
        retStatus = 0;

    }

    printSOCMessage(rangeStatus, printFunc);

    return retStatus;
}

int analyzeChargeRateInRange(float chargeRate, void (*printFunc)(char*), int warningEnabled)
{
    int retStatus = 1;

    valueRangeStatus rangeStatus = chackValueRange(-FLT_MAX, CHARGE_RATE_MAX_VALUE, chargeRate,
                    CHARGE_RATE_TOLERANCE, warningEnabled);

    if(rangeStatus > HIGH_VALUE_WARNING)
    {
        retStatus = 0;

    }

    printChargeRateMessage(rangeStatus, printFunc);

    return retStatus;
}
