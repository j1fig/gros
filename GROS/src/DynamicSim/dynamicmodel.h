#ifndef DYNAMICMODEL_H
#define DYNAMICMODEL_H

#include <vector>
#include "../constants.h"
#include "dynamicmath.h"

class DynamicModel: public DynamicMath
{
    ///////////////////////////////////////////////////////////
    //   A simple dynamic simulating class that considers constant
    //  positive acceleration and uses simple quadratic formula for
    //  integrating time and position
    //  Receives 3D state, but doesn't model heading
    //  Assumes movement (speed and acceleration) is linear between states
    ///////////////////////////////////////////////////////////
public:
    DynamicModel();
    virtual ~DynamicModel();

    virtual void initModel	();

    virtual bool integrate  (State_t* state, float timeStep);


    virtual float stateDistance     (State_t initState, State_t endState);
    virtual float timeToTarget      (State_t initState, State_t targetState);

    virtual float timeToTargetSpeed		(State_t initState, State_t targetState);
    virtual float distanceToTargetSpeed	(State_t initState, State_t targetState);

    virtual void updateAcceleration			(State_t* state, State_t targetState);

    virtual void updateStatePosition(State_t* state, float percent, State_t origState, State_t destState);

};

#endif // DYNAMICMODEL_H
