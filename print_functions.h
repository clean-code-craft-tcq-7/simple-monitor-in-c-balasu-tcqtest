
#include "product_config.h"

void setPrintLanguage(printLangType language);
void printTempratureMessage(int rangeStatus, void(*printFunc)(char*));
void printSOCMessage(int rangeStatus, void(*printFunc)(char*));
void printChargeRateMessage(int rangeStatus, void(*printFunc)(char*));
void printToConsole(char* text);
