#include <stdio.h>
#include "check_value_breach.h"

int checkOutsideBoundaryMinOrMax(float min, float max, float value)
{
    int returnVal;
	if(value < min)
	{
	    returnVal = 0;
	}
	else if(value > max)
	{
	    returnVal = 1;
	}

	return returnVal;
}

int checkOutsideBoundary(float min, float max, float value)
{
    int returnValue = 0;

    if(value < min || value > max)
    {
        returnValue = 1;
    }

    return returnValue;
}
valueRangeStatus checkMinOrMaxBreach(float min, float max, float value)
{
	valueRangeStatus returnValue = NORMAL;
	int boundaryOutsideRetVal = checkOutsideBoundaryMinOrMax(min, max, value);
	
	if(boundaryOutsideRetVal == 0)
	{
		returnValue = LOW_VALUE_BREACH;
	}
	else if(boundaryOutsideRetVal == 1)
	{
		returnValue = HIGH_VALUE_BREACH;
	}
	
	return returnValue;
}

valueRangeStatus checkForWarning(float minWithTolerance,float maxWithTolerance, float value)
{
	valueRangeStatus returnValue = NORMAL;
	
	int boundaryOutsideRetVal = checkOutsideBoundaryMinOrMax(minWithTolerance, maxWithTolerance, value);
	
	if(boundaryOutsideRetVal == 0)
	{
		returnValue = LOW_VALUE_WARNING;
	}
	else if(boundaryOutsideRetVal == 1)
	{
		returnValue = HIGH_VALUE_WARNING;
	}
	
	return returnValue;
}
		
valueRangeStatus chackValueRange(float min, float max, float value, float tolerance,int warningEnabled)
{
	valueRangeStatus returnValue = NORMAL;

	float toleranceVal = (max * tolerance) / 100;
	float minWithTolerance = min + toleranceVal;
	float maxWithTolerance = max - toleranceVal;
	
	if(checkOutsideBoundary(min, max, value) == 1)
	{
		returnValue = checkMinOrMaxBreach(min,max,value);
	}
	else if(warningEnabled == 1)
	{
		returnValue = checkForWarning(minWithTolerance,maxWithTolerance, value);
	}
	
	return returnValue;
		
}
