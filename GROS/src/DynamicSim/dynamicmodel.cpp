#include "dynamicmodel.h"
#include <cmath>
#include <iostream>

DynamicModel::DynamicModel()
{
}

DynamicModel::~DynamicModel()
{
}

void DynamicModel::initModel()
{
}

bool DynamicModel::integrate(State_t *state, float timeStep)
{
  bool success = true;

  // Checks for time until max or min speed are reached

  return success;
}

float DynamicModel::stateDistance(State_t initState, State_t endState)
{
    float distance = 0;

    distance = sqrt(pow((endState.position[X]-initState.position[X]),2) +
                    pow((endState.position[Y]-initState.position[Y]),2) +
                    pow((endState.position[Z]-initState.position[Z]),2));

    return distance;
}

float DynamicModel::timeToTarget(State_t initState, State_t targetState)
{
    float distance = this->stateDistance(initState,targetState);

    float t1 = 0;
    float t2 = 0;

    float speed = 0;
    float acceleration = 0;

    float timeToTarget = 0;

    if (DynamicMath::checkColinearity<float>(initState.linearVelocity,initState.linearAcceleration))
    {
        speed = DynamicMath::vectorModule<float>(initState.linearVelocity);
        acceleration = DynamicMath::vectorModule<float>(initState.linearAcceleration);

        t1 = (-speed + sqrt(pow(speed,2) + (4*(acceleration/2)*distance)))/(2*(acceleration/2));
        t1 = (-speed - sqrt(pow(speed,2) + (4*(acceleration/2)*distance)))/(2*(acceleration/2));

        if (t2<0 && t1>0)
        {
            timeToTarget = t1;
        }
        else if (t1<0 && t2>0)
        {
            timeToTarget = t2;
        }
        else if (t2>0 && t1>0)
        {
            if (t1 < t2)
            {
                timeToTarget = t1;
            }
            else
            {
                timeToTarget = t2;
            }
        }
        else
        {
#ifdef DEBUG
            std::cout << " DynamicModel: Warning @ getTimeToTarget - condition not caught! " << std::endl;
#endif
        }
    }
    else
    {
#ifdef DEBUG
        std::cout << " DynamicModel: Warning @ getTimeToTarget - speed and acceleration not colinear! " << std::endl;
#endif
    }

    return timeToTarget;
}



//	// State acceleration logic switch
//
//	// State deaccelerating
//	if (initState.acceleration < 0)
//	{
//
//
//	float timeToTargetSpeed = this->getTimeToTargetSpeed(initState,targetState);
//
//	float distanceToTargetSpeed = this->getDistanceToTargetSpeed(initState,timeToTargetSpeed);
//
//	this->updateAcceleration(initState,targetState,timeToTargetSpeed);
//
//
//	// Time left logic
//
//	// At normal taxi speed
//	if (initState.speed == Constants::NOMINAL_TAXI_SPEED && targetState.speed == Constants::NOMINAL_TAXI_SPEED)
//	{
//
//	}
//
//}

float DynamicModel::timeToTargetSpeed(State_t initState, State_t targetState)
{
    // Acceleration is constant, deacceleration is regulated so that it reaches target with target speed

    float distance = this->stateDistance(initState,targetState);
    float initSpeed = 0;
    float targetSpeed = 0;
    float initAcceleration = 0;

    float timeToTargetSpeed = 0.0;

    if (DynamicMath::checkColinearity<float>(initState.linearVelocity,initState.linearAcceleration))
    {
        initSpeed = DynamicMath::vectorModule<float>(initState.linearVelocity);
        targetSpeed = DynamicMath::vectorModule<float>(targetState.linearVelocity);
        initAcceleration = DynamicMath::vectorModule<float>(initState.linearAcceleration);

        // Tests the 3 cases - initSpeed less/equal/greater than targetSpeed
        if (initSpeed < targetSpeed)
        {
            // accelerates at constant rate
            timeToTargetSpeed = (targetSpeed - initSpeed)/NOMINAL_TAXI_ACCELERATION;
        }
        else if (initSpeed == targetSpeed)
        {
            // no acceleration
            timeToTargetSpeed = distance/initSpeed;

            if (initAcceleration !=0)
            {
#ifdef DEBUG
                std::cout << " DynamicSimulator: Warning @ getTimeToTargetSpeed - acceleration not zero despite same speed" << std::endl;
#endif
            }

            if (initSpeed != NOMINAL_TAXI_SPEED)
            {
#ifdef DEBUG
                std::cout << " DynamicSimulator: Warning @ getTimeToTargetSpeed - maintaining speed different than nominal speed " << std::endl;
#endif
            }
        }
        else if (initSpeed > targetSpeed)
        {
            // deaccelerates as necessary to reach hold speed at target state
            timeToTargetSpeed = (2*distance)/(initSpeed + NOMINAL_HOLD_SPEED);
        }
    }
    else
    {
#ifdef DEBUG
        std::cout << " DynamicModel: Warning @ getTimeToTargetSpeed - speed and acceleration not colinear! " << std::endl;
#endif
    }

    return timeToTargetSpeed;
}


float DynamicModel::distanceToTargetSpeed(State_t initState, State_t targetState)
{
  float distance = 0;

  float initSpeed = 0;
  float initAcceleration = 0;

  float timeToTargetSpeed = this->timeToTargetSpeed(initState,targetState);

  if (DynamicMath::checkColinearity<float>(initState.linearVelocity,initState.linearAcceleration))
  {
    initSpeed = DynamicMath::vectorModule<float>(initState.linearVelocity);
    initAcceleration = DynamicMath::vectorModule<float>(initState.linearAcceleration);

    distance = ((initAcceleration/2)*pow(timeToTargetSpeed,2)) + (initSpeed*timeToTargetSpeed);
  }
  else
  {
#ifdef DEBUG
      std::cout << " DynamicModel: Warning @ getDistanceToTargetSpeed - speed and acceleration not colinear! " << std::endl;
#endif
  }
  return distance;
}

void DynamicModel::updateAcceleration(State_t *state, State_t targetState)
{
    float timeToTargetSpeed = this->timeToTargetSpeed(*state,targetState);
}

void DynamicModel::updateStatePosition(State_t *state, float percent, State_t origState, State_t destState)
{
}


//void DynamicSimulator::updateAcceleration(State_t* state, State_t targetState, float timeToTargetSpeed)
//{
//	if (state->speed < targetState.speed)
//	{
//		state->acceleration = Constants::NOMINAL_TAXI_ACCELERATION;
//	}
//	else if (state->speed > targetState.speed)
//	{
//		state->acceleration = (Constants::NOMINAL_HOLD_SPEED - state->speed)/timeToTargetSpeed;
//	}
//}

