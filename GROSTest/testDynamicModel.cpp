#include "UnitTest++.h"

#include "../GROS/src/DynamicSim/dynamicmodel.h"


class DynamicModelFixture
{
public:
    DynamicModelFixture()
    {
        dynamicModel = new DynamicModel();
    }

    ~DynamicModelFixture()
    {
        delete dynamicModel;
    }

    DynamicModel* dynamicModel;

};


SUITE(DynamicModelTestSuite)
{
    TEST_FIXTURE(DynamicModelFixture,firstTest)
    {
//        dynamicModel->
    }
}



