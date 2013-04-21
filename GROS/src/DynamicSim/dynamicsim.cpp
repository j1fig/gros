#include "dynamicsim.h"
#include "../Utils/utils.h"

#include <cstring>

DynamicSim::DynamicSim()
{
}

DynamicSim::~DynamicSim()
{
}

void DynamicSim::init()
{
    // Clears previous nodes and entities
    this->_nodes.clear();
    this->_entities.clear();

//    while (!this->_nodeQueue.empty())
//        this->_nodeQueue.pop();

//    while (!this->_entityQueue.empty())
//        this->_entityQueue.pop();


    DynamicModel::initModel();
}

void DynamicSim::init(std::vector<Node> nodes,std::vector<Entity> entities)
{
    // Clears previous nodes and entities
    this->_nodes.clear();
    this->_entities.clear();

//    while (!this->_nodeQueue.empty())
//        this->_nodeQueue.pop();

//    while (!this->_entityQueue.empty())
//        this->_entityQueue.pop();

    // Sets new nodes and entities
    this->_nodes = nodes;
    this->_entities = entities;

//    for (int nodeIndex=0; nodeIndex<nodes.size(); nodeIndex++)
//    {
//        _nodeQueue.push(nodes[nodeIndex]);
//    }

//    for (int entityIndex=0; entityIndex<entities.size(); entityIndex++)
//    {
//        _entityQueue.push(entities[entityIndex]);
//    }


    DynamicModel::initModel();
}

short DynamicSim::update(float timeStep)
{
    short entitiesUpdated = 0;

    // Updates all entities by the given time-step
    for (short entityIndex=0; entityIndex<this->_entities.size(); entityIndex++)
    {
        // Checks current entity command and proceeds accordingly
        switch (this->_entities[entityIndex].getCommand())
        {
        case COMMAND_MOVE:
            // There can be 3 scenarios
            // Entity at target speed for the whole time window

            // Entity accelerating to target speed for the whole time window

            // Entity reaches target speed during the time window

            break;
        case COMMAND_STOP:
            // There can be 3 scenarios
            // Entity at target speed for the whole time window

            // Entity deccelerating to target speed for the whole time window

            // Entity reaches target speed during the time window
            break;
        case COMMAND_HOLD:
            break;
        default:
            break;
        }

        // Checks time until next node against current time-step


        // If time until next node is greater than the step, simply integrates the state


        State_t entityState = this->_entities[entityIndex].getState();
        DynamicModel::integrate(&entityState,timeStep);
        this->_entities[entityIndex].setState(entityState);

        entitiesUpdated++;
    }

    return entitiesUpdated;

}

std::vector<Node> DynamicSim::getNodes()
{
    return this->_nodes;
}

std::vector<Entity> DynamicSim::getEntities()
{
    return this->_entities;
}

Node DynamicSim::findNode(int number)
{
    Node nullNode;

    nullNode.setNumber(-1);


    for (int nodeIndex=0; nodeIndex<_nodes.size(); nodeIndex++)
    {
        if (_nodes[nodeIndex].getNumber() == number)
        {
            return _nodes[nodeIndex];
        }
    }

    return nullNode;
}

Entity DynamicSim::findEntity(char *id)
{
    for (int entityIndex=0; entityIndex<_entities.size(); entityIndex++)
    {
        if (strcmp(_entities[entityIndex].getID(),id) == 0)
        {
            return _entities[entityIndex];
        }
    }

    return 0;
}

float DynamicSim::nodeDistance(short node1, short node2)
{
    float nodeDistance = 0;

    State_t initState;
    State_t endState;

    Utils::initStruct<State_t>(&initState);
    Utils::initStruct<State_t>(&endState);

    initState.position[X] = this->_nodes[node1].getX();
    initState.position[Y] = this->_nodes[node1].getY();
    initState.position[Z] = this->_nodes[node1].getZ();

    endState.position[X] = this->_nodes[node2].getX();
    endState.position[Y] = this->_nodes[node2].getY();
    endState.position[Z] = this->_nodes[node2].getZ();

    nodeDistance = DynamicModel::stateDistance(initState,endState);

    return nodeDistance;
}


//float DynamicSim::timeToState(char *entityId, State_t endState)
//{
//    float timeToState = 0;

////    State_t

////    timeToState = DynamicModel::timeToTarget(initState,endState);

//    return timeToState;
//}

//float DynamicSim::timeToState(State_t initState, State_t endState)
//{
//    float timeToState = 0;

//    timeToState = DynamicModel::timeToTarget(initState,endState);

//    return timeToState;
//}

float DynamicSim::timeToNextNode(char *entityId)
{
    float timeToNode = 0;

    return timeToNode;
}
