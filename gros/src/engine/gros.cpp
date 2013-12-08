#include "gros.h"
#include "../heuristic/heuristic.h"
#include <boost/smart_ptr.hpp>

GROS::GROS()
{
    this->heuristic = boost::make_shared<Heuristic>();
}

GROS::~GROS()
{
}


void GROS::run()
{

}

void GROS::init(std::vector<Node::Ptr> nodes, std::vector<Entity::Ptr> entities)
{
    this->nodes.clear();
    this->entities.clear();
    this->nodes = nodes;
    this->entities = entities;

    this->heuristic->init(this->nodes, this->entities);

}
