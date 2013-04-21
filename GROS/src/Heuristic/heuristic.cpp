#include "heuristic.h"
#include "../Node/node.h"
#include "../Utils/utils.h"
#include "../DynamicSim/dynamicsim.h"


Heuristic::Heuristic()
{
    this->_dynamicSim = new DynamicSim();
}

Heuristic::~Heuristic()
{
    delete this->_dynamicSim;
}

void Heuristic::init()
{
    this->_nodes.clear();
    this->_dynamicSim->init();
    this->constructGraph();
}

void Heuristic::init(std::vector<Node> nodes)
{
    std::map< char, std::map<char,float> >::iterator node;

    this->_nodes = nodes;

//    this->_dynamicSim->init(this->_nodes);

    this->constructGraph();

    for (node = this->_graph.begin(); node != this->_graph.end(); node++)
    {
        this->_heuristic[node->first] = this->Dijkstra(node->first);
    }

}

void Heuristic::constructGraph()
{
    for (unsigned short nodeIndex=0; nodeIndex<this->_nodes.size(); nodeIndex++)
    {
        for (unsigned short connectIndex=0;
            connectIndex<this->_nodes[nodeIndex].getConnections().size();
            connectIndex++)
        {
            this->_graph[Utils::shortToChar(nodeIndex)][Utils::shortToChar(connectIndex)] =
            this->getOptimisticCost(this->_nodes[nodeIndex].getNumber(),
                                    this->_nodes[nodeIndex].getConnections()[connectIndex]);
        }
    }
}

std::map<char,float> Heuristic::Dijkstra(char graphNode)
{
    std::map<char,float>::iterator dbgIter;
    std::map<char,float> care;

    care = this->_graph[graphNode];

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

    initState.position[0] = this->_nodes[node1].getX();
    initState.position[1] = this->_nodes[node1].getY();
    initState.position[2] = this->_nodes[node1].getZ();

    // TO DO
//    initState.linearVelocity = NOMINAL_TAXI_SPEED;
//    initState.linearAcceleration = 0;

    endState.position[0] = this->_nodes[node2].getX();
    endState.position[1] = this->_nodes[node2].getY();
    endState.position[2] = this->_nodes[node2].getZ();

    // TO DO
//    initState.linearVelocity = NOMINAL_TAXI_SPEED;
//    initState.linearAcceleration = 0;

    // TO DO
//    optimisticCost = this->_dynamicSim->timeToState(initState,endState);

    return optimisticCost;

}
