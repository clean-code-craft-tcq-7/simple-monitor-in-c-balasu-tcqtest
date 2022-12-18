typedef enum
{
	NORMAL = 1,
	LOW_VALUE_WARNING,
	HIGH_VALUE_WARNING,
	LOW_VALUE_BREACH,
	HIGH_VALUE_BREAH,
} valueRangeStatus;

valueRangeStatus checkMinOrMaxBreach(float min, float max, float value);
valueRangeStatus checkForWarning(float minWithTolerance,float maxWithTolerance, float value);
valueRangeStatus chackValueRange(float min, float max, float value, float tolerance,int warningEnabled);
