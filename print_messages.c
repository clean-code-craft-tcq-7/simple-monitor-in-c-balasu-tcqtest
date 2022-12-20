#include <stdio.h>

#include "product_config.h"
#include "print_messages.h"

char* TempreatureMessageEnglish[MAX_PRINT_MESSAGES] = {
	"Low Temperature Warning\n",
	"High Temperature Warning\n",
	"Low Temperature Breach\n",
	"High Temperature Breach\n",
};

char* SOCMessageEnglish[MAX_PRINT_MESSAGES] = {
	"Low SOC Warning\n",
	"High SOC Warning\n",
	"Low SOC Breach\n",
	"High SOC Breach\n",
};

char* TempreatureMessageGerman[MAX_PRINT_MESSAGES] = {
	"Warnung vor niedriger Temperatur\n",
	"Warnung vor hoher Temperatur\n",
	"Niedrige Temperaturverletzung\n",
	"Hohe Temperaturverletzung\n",
};

char* SOCMessageGerman[MAX_PRINT_MESSAGES] = {
	"Niedrige SOC-Warnung\n",
	"Warnung zu hohem SOC\n",
	"Niedrige SOC-Verletzung\n",
	"Hohe SOC-Verletzung\n",
};

char* ChargeRateMessageEnglish[MAX_PRINT_MESSAGES] = {
                "Low Charge Rate Warning\n",
                "High Charge Rate Warning\n",
                "Low Charge Rate Breach\n",
                "High Charge Rate Breach\n",
};

char* ChargeRateMessageGerman[MAX_PRINT_MESSAGES] = {
	"Warnung zu niedrigem Ladestrom\n",
	"Warnung vor hoher Laderate\n",
	"Verstoß gegen niedrige Gebührenrate\n",
	"Verstoß gegen hohe Gebührenrate\n",


};

char** TemperatureMessageList[MAX_LANGUAGE_SUPRTD] = {
	TempreatureMessageEnglish,
	TempreatureMessageGerman,
};

char** SOCMessageList[MAX_LANGUAGE_SUPRTD] = {
	SOCMessageEnglish,
	SOCMessageGerman,
};

char** ChargeRateMessageList[MAX_LANGUAGE_SUPRTD] = {
	ChargeRateMessageEnglish,
	ChargeRateMessageGerman,
};
