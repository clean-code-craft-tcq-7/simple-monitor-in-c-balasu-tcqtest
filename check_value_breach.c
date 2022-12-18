#inlcude <stdio.h>
#include "check_value_breach.h"

int checkOutsideBoundary(float min, float max, float value)
{
	if(value < min)
	{
		return 0;
	}
	else if(value > max)
	{
		return 1;
	}
}

valueRangeStatus checkMinOrMaxBreach(float min, float max, float value)
{
	valueRangeStatus returnValue = NORMAL;
	int boundaryOutsideRetVal = checkOutsideBoundary(min, max, value);
	
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
	
	int boundaryOutsideRetVal = checkOutsideBoundary(minWithTolerance, maxWithTolerance, value);
	
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
	
	if(value < min || value > max)
	{
		returnValue = checkMinOrMaxBreach(min,max,value);
	}
	else if(warningEnabled == 1)
	{
		returnValue = checkForWarning(minWithTolerance,minWithTolerance, value);
	}
	
	return returnValue;
		
}