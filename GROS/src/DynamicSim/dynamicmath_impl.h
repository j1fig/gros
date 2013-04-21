#ifndef DYNAMICMATH_IMPL_H
#define DYNAMICMATH_IMPL_H

template <class T>
bool DynamicMath::checkColinearity   (std::vector<T> firstVec,std::vector<T> secondVec)
{
    bool vectorsColinear = false;

    T firstVecModule = 0;
    T secondVecModule = 0;

    // If vector sizes match, they can be colinear
    if (firstVec.size() == secondVec.size())
    {
        firstVecModule = this->vectorModule<T>(firstVec);
        secondVecModule = this->vectorModule<T>(secondVec);

        this->normalizeVector<T>(firstVec);
        this->normalizeVector<T>(secondVec);

        // Assumes true vale before check
        vectorsColinear = true;
        // check equal parameters
        for (short vecIndex=0; vecIndex<firstVec.size(); vecIndex++)
        {
            if (firstVec[vecIndex]!=secondVec[vecIndex])
                vectorsColinear = false;
        }
    }

    return vectorsColinear;
}


template <class T>
void DynamicMath::normalizeVector    (std::vector<T>& vec)
{
    T vecModule = this->vectorModule(vec);

    for (short vecIndex=0; vecIndex<vec.size(); vecIndex++)
    {
        vec[vecIndex] = vec[vecIndex]/vecModule;
    }
}

template <class T>
T DynamicMath::vectorModule    (std::vector<T> vec)
{
    T module = 0;
    T squaredSum = 0;

    for (short vecIndex=0; vecIndex<vec.size(); vecIndex++)
    {
        squaredSum += pow(vec[vecIndex],2);
    }

    module = sqrt(squaredSum);

    return module;
}

#endif // DYNAMICMATH_IMPL_H
