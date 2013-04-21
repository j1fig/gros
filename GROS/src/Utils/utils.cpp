#include "utils.h"

#include <cstring>

Utils::Utils()
{
}

Utils::~Utils()
{
}


short Utils::charCopy(char* destChar,const char* inputChar,unsigned short maxSize)
{
    short errorCode = -1;
    short lastCharIndex = 0;
    char* returnAddress = 0;

    // Adjust max size to prevent buffer overflow/overrun
    if (maxSize>strlen(inputChar))
    {
        maxSize = strlen(inputChar);
    }
    if (maxSize>strlen(destChar))
    {
        maxSize = strlen(destChar);
    }

    returnAddress = strncpy(destChar,inputChar,maxSize);

    // Null-termination enforcing
    lastCharIndex = strlen(destChar) -1;
    destChar[lastCharIndex] = '\0';

    if (returnAddress)
    {
        errorCode = 0;
    }

    return errorCode;
}

short Utils::charToShort(const char* charString)
{
    char *garbage = NULL;
    long value = 0;

    // TODO

    return (short)value;
}

char Utils::shortToChar(const short shortNumber)
{
    char value = 0;

    value = (char) shortNumber;

    return value;
}

float Utils::charToFloat(const char* charString)
{
    char *garbage = NULL;
    double value = 0;

    // TODO

    return (float)value;
}
