#include "gros.h"
#include "DynamicSim/dynamicsim.h"
#include "Heuristic/heuristic.h"

GROS::GROS()
{
    this->_dynamicSim = new DynamicSim();
    this->_heuristic = new Heuristic();

}

GROS::~GROS()
{
    delete this->_dynamicSim;
    delete this->_heuristic;
}

void GROS::init()
{
    this->_nodes.clear();
    this->_entities.clear();

    this->_dynamicSim->init();
    this->_heuristic->init();
}

void GROS::init(std::vector<Node> nodes, std::vector<Entity> entities)
{
    this->_nodes = nodes;
    this->_entities = entities;

    this->_dynamicSim->init(this->_nodes,this->_entities);
    this->_heuristic->init(this->_nodes);

}
