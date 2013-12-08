#ifndef UTILS_IMPL_H
#define UTILS_IMPL_H

#include <cstring>

template <class T>
short Utils::initStruct(T* structVar)
{
    short errorCode = -1;
    void* returnVal = 0;
    returnVal = memset(structVar,0,sizeof(T));

    if (returnVal)
        errorCode =0;

    return errorCode;
}


#endif // UTILS_IMPL_H
