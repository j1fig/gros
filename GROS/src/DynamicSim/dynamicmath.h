#ifndef DYNAMICMATH_H
#define DYNAMICMATH_H

#include <vector>

class DynamicMath
{
protected:
    DynamicMath();
    virtual ~DynamicMath();

    template <class T>
    bool checkColinearity   (std::vector<T> firstVec,std::vector<T> secondVec);

    template <class T>
    void normalizeVector    (std::vector<T>& vec);

    template <class T>
    T vectorModule    (std::vector<T> vec);
};

#include "dynamicmath_impl.h"

#endif // DYNAMICMATH_H
