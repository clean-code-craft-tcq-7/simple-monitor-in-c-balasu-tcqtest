#ifndef PRODUCT_CONFIG_H_
#define PRODUCT_CONFIG_H_
typedef enum{
	ENGLISH,
	GERMAN,
	MAX_LANGUAGE_SUPRTD,
}printLangType;

typedef enum{
    TEMPERATURE_ANALYSIS,
    SOC_ANALYSIS,
    CHARGE_RATE_ANALYSIS,
    MAX_ANALYSIS_SUPPORTED
}analysisType;

#define TEMPERATURE_MIN_VALUE   10
#define TEMPERATURE_MAX_VALUE	45
#define TEMPERATURE_TOLERANCE   5   // Value in %

#define SOC_MIN_VALUE   20
#define SOC_MAX_VALUE   80
#define SOC_TOLERANCE   5   // Value in %

#define CHARGE_RATE_MAX_VALUE 0.8
#define CHARGE_RATE_TOLERANCE 2 // Value in %

#endif
