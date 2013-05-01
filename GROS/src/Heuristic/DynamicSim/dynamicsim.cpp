#include "dynamicsim.h"
#include "../../Utils/utils.h"

#include <cstring>

DynamicSim::DynamicSim()
{
}

DynamicSim::~DynamicSim()
{
}

void DynamicSim::init(std::vector<nodePtr> nodes,std::vector<entityPtr> entities)
{
    // Clears previous nodes and entities
    this->nodes.clear();
    this->entities.clear();

//    while (!this->_nodeQueue.empty())
//        this->_nodeQueue.pop();

//    while (!this->_entityQueue.empty())
//        this->_entityQueue.pop();

    // Sets new nodes and entities
    this->nodes = nodes;
    this->entities = entities;

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
    for (short entityIndex=0; entityIndex<this->entities.size(); entityIndex++)
    {
        // Checks current entity command and proceeds accordingly
        switch (this->entities[entityIndex]->getCommand())
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


        State_t entityState = this->entities[entityIndex]->getState();
        DynamicModel::integrate(&entityState,timeStep);
        this->entities[entityIndex]->setState(entityState);

        entitiesUpdated++;
    }

    return entitiesUpdated;

}

nodePtr DynamicSim::findNode(int number)
{
    nodePtr nullNode;

    nullNode->setNumber(-1);


    for (int nodeIndex=0; nodeIndex<nodes.size(); nodeIndex++)
    {
        if (nodes[nodeIndex]->getNumber() == number)
        {
            return nodes[nodeIndex];
        }
    }

    return nullNode;
}

entityPtr DynamicSim::findEntity(char *id)
{
    entityPtr nullEntity(new Entity(""));

    for (int entityIndex=0; entityIndex<entities.size(); entityIndex++)
    {
        if (strcmp(entities[entityIndex]->getID(),id) == 0)
        {
            return entities[entityIndex];
        }
    }

    return nullEntity;
}

float DynamicSim::nodeDistance(short node1, short node2)
{
    float nodeDistance = 0;

    State_t initState;
    State_t endState;

    Utils::initStruct<State_t>(&initState);
    Utils::initStruct<State_t>(&endState);

    initState.position[X] = this->nodes[node1]->getX();
    initState.position[Y] = this->nodes[node1]->getY();
    initState.position[Z] = this->nodes[node1]->getZ();

    endState.position[X] = this->nodes[node2]->getX();
    endState.position[Y] = this->nodes[node2]->getY();
    endState.position[Z] = this->nodes[node2]->getZ();

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
