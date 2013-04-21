///////////////////////////////////////////////////////////
//  Constants.h
//  Implementation of the Class Constants
//  Created on:      28-Dec-2011 13:23:24
//  Original author: joao.figueiredo
///////////////////////////////////////////////////////////

#if !defined(CONSTANTS_H)
#define CONSTANTS_H

#include <climits>
#include <vector>

/**
 * Holds constants and reference values
 */

// Dynamic Simulator Constants
#define INTEGRATION_TIME_STEP 0.1
#define INFINITE_TIME LONG_MAX;

#define NOMINAL_TAXI_SPEED 7.71666667
#define NOMINAL_TAXI_ACCELERATION 0.5
#define DISTANCE_TO_START_DEACCELERATION 10.0
#define NOMINAL_HOLD_SPEED 1.0

enum Cartesian_t
{
    X,
    Y,
    Z,
    CARTESIAN_NUM
};

enum Euler_t
{
    YAW,      // phi
    PITCH,    // theta
    ROLL,     // psi
    EULER_NUM
};

struct State_t
{
    std::vector<float> position;
    std::vector<float> linearVelocity;
    std::vector<float> linearAcceleration;

    std::vector<float> heading;
    std::vector<float> angularVelocity;

};

enum
{
    NODE_TYPE_GATE,
    NODE_TYPE_MOVE,
    NODE_TYPE_HOLD,
    NODE_TYPE_DEPART,
    NODE_TYPE_NONE
};

enum
{
    COMMAND_STOP,
    COMMAND_HOLD,
    COMMAND_MOVE
};

#endif // !defined(CONSTANTS_H)
