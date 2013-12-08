#ifndef MATH_H
#define MATH_H

#include <vector>

class Math
{
public:
    Math();
    virtual ~Math();

    template <class T>
    static bool checkColinearity   (std::vector<T> firstVec,std::vector<T> secondVec);

    template <class T>
    static void normalizeVector    (std::vector<T>& vec);

    template <class T>
    static T vectorModule    (std::vector<T> vec);
};

#include "math_impl.h"

#endif // MATH_H
