#include "heuristic.h"
#include "../node/node.h"
#include "../utils/utils.h"
#include "dynamicsim/dynamicsim.h"


Heuristic::Heuristic()
{
    this->dynamicSim = new DynamicSim();
}

Heuristic::~Heuristic()
{
    delete this->dynamicSim;
}


void Heuristic::init(std::vector<nodePtr> nodes, std::vector<entityPtr> entities)
{
    std::map< char, std::map<char,float> >::iterator node;

    this->nodes.clear();
    this->nodes = nodes;

    this->entities .clear();
    this->entities = entities;

    this->dynamicSim->init(this->nodes,this->entities);

    this->constructGraph();

    for (node = this->graph.begin(); node != this->graph.end(); node++)
    {
        this->heuristic[node->first] = this->Dijkstra(node->first);
    }

}

void Heuristic::constructGraph()
{
    for (unsigned short nodeIndex=0; nodeIndex<this->nodes.size(); nodeIndex++)
    {
        for (unsigned short connectIndex=0;
            connectIndex<this->nodes[nodeIndex]->getConnections().size();
            connectIndex++)
        {
            this->graph[Utils::shortToChar(nodeIndex)][Utils::shortToChar(connectIndex)] =
            this->getOptimisticCost(this->nodes[nodeIndex]->getNumber(),
                                    this->nodes[nodeIndex]->getConnections()[connectIndex]);
        }
    }
}

std::map<char,float> Heuristic::Dijkstra(char graphNode)
{
    std::map<char,float>::iterator dbgIter;
    std::map<char,float> care;

    care = this->graph[graphNode];

    for (dbgIter = care.begin(); dbgIter != care.end(); dbgIter++)
    {
        std::cout << " Graph Node (Key): " << dbgIter->first << " Neighbours (Values): " << dbgIter->second << std::endl;
    }

    return care;
}

float Heuristic::getOptimisticCost(short node1, short node2)
{
    // Here the optimistic cost is simply the time between the nodes, travelling at maximum allowable speed
    float optimisticCost = 0;

    State_t initState;
    State_t endState;

    Utils::initStruct<State_t>(&initState);
    Utils::initStruct<State_t>(&endState);

    initState.position[0] = this->nodes[node1]->getX();
    initState.position[1] = this->nodes[node1]->getY();
    initState.position[2] = this->nodes[node1]->getZ();

    // TO DO
//    initState.linearVelocity = NOMINAL_TAXI_SPEED;
//    initState.linearAcceleration = 0;

    endState.position[0] = this->nodes[node2]->getX();
    endState.position[1] = this->nodes[node2]->getY();
    endState.position[2] = this->nodes[node2]->getZ();

    // TO DO
//    initState.linearVelocity = NOMINAL_TAXI_SPEED;
//    initState.linearAcceleration = 0;

    // TO DO
//    optimisticCost = this->_dynamicSim->timeToState(initState,endState);

    return optimisticCost;

}
