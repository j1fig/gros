#ifndef UTILS_H
#define UTILS_H

class Utils {
public:
    Utils();
    virtual ~Utils();

    static short charCopy		(char* destChar, const char* inputChar,unsigned short maxSize);
    static short charToShort	(const char* charString);
    static float charToFloat	(const char* charString);

    static char shortToChar     (const short shortNumber);

    template <class T>
    static short initStruct     (T* structVar);
};

#include "utils_impl.h"

#endif // UTILS_H
