#include <stdio.h>
#include <string.h>

#include "product_config.h"
#include "print_messages.h"

printLangType printLanguage = ENGLISH;

void setPrintLanguage(printLangType language)
{
	printLanguage = language;
}

void printToConsole(char* text)
{
	printf("%s", text);
}

void printTempratureMessage(int rangeStatus, char* printStr)
{
	char** printMessageData = TemperatureMessageList[printLanguage];
	int offset = rangeStatus - 2; // To get the proper indexing
	char* stringValue = printMessageData[offset];
    strcpy(printStr, stringValue);
}

void printSOCMessage(int rangeStatus, char* printStr)
{
	char** printMessageData = SOCMessageList[printLanguage];
	int offset = rangeStatus - 2; // To get the proper indexing
	char* stringValue = printMessageData[offset];
	strcpy(printStr, stringValue);
}

void printChargeRateMessage(int rangeStatus, char* printStr)
{
	char** printMessageData = ChargeRateMessageList[printLanguage];
	int offset = rangeStatus - 2; // To get the proper indexing
	char* stringValue = printMessageData[offset];
    strcpy(printStr, stringValue);
}
