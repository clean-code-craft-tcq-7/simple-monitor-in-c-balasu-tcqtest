#include <stdio.h>
#include <string.h>

#include "product_config.h"
#include "print_messages.h"
#include "check_value_breach.h"

printLangType printLanguage = ENGLISH;

void setPrintLanguage(printLangType language)
{
	printLanguage = language;
}

void printToConsole(char* text)
{
	printf("%s", text);
}

void printTempratureMessage(int rangeStatus, void(*printFunc)(char*))
{
    if(rangeStatus > NORMAL)
    {
        char** printMessageData = TemperatureMessageList[printLanguage];
        int offset = rangeStatus - 2; // To get the proper indexing
        char* stringValue = printMessageData[offset];
        printFunc(stringValue);
    }
}

void printSOCMessage(int rangeStatus, void(*printFunc)(char*))
{
    if(rangeStatus > NORMAL)
    {
        char** printMessageData = SOCMessageList[printLanguage];
        int offset = rangeStatus - 2; // To get the proper indexing
        char* stringValue = printMessageData[offset];
        printFunc(stringValue);
    }
}

void printChargeRateMessage(int rangeStatus, void(*printFunc)(char*))
{
    if(rangeStatus > NORMAL)
    {
        char** printMessageData = ChargeRateMessageList[printLanguage];
        int offset = rangeStatus - 2; // To get the proper indexing
        char* stringValue = printMessageData[offset];
        printFunc(stringValue);
    }
}
