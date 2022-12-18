#include <stdio.h>

#include "product_config.h"
#include "print_messages.h"

char* TempreatureMessageEnglish[4] = {
	"Low Temperature Warning\n",
	"High Temperature Warning\n",
	"Low Temperature Breach\n",
	"High Temperature Breach\n",
};

char* SOCMessageEnglish[4] = {
	"Low SOC Warning\n",
	"High SOC Warning\n",
	"Low SOC Breach\n",
	"High SOC Breach\n",
};

char* TempreatureMessageGerman[4] = {
	"Warnung vor niedriger Temperatur\n",
	"Warnung vor hoher Temperatur\n",
	"Niedrige Temperaturverletzung\n",
	"Hohe Temperaturverletzung\n",
};

char* SOCMessageGerman[4] = {
	"Niedrige SOC-Warnung\n",
	"Warnung zu hohem SOC\n",
	"Niedrige SOC-Verletzung\n",
	"Hohe SOC-Verletzung\n",
};

char* ChargeRateMessageEnglish[1] = {
	"High Charge Rate Breach\n"
}

char* ChargeRateMessageGerman[1] = {
	"Verstoß gegen hohe Gebührenrate\n"
}

char* TemperatureMessageList[MAX_LANGUAGE_SUPRTD] = {
	&TempreatureMessageEnglish,
	&TempreatureMessageGerman,
}

char* SOCMessageList[MAX_LANGUAGE_SUPRTD] = {
	&SOCMessageEnglish,
	&SOCMessageGerman,
}

char* ChargeRateMessageList[MAX_LANGUAGE_SUPRTD] = {
	&ChargeRateMessageEnglish,
	&ChargeRateMessageGerman,
}