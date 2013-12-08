#include "gros.h"
#include "../heuristic/heuristic.h"

GROS::GROS()
{
    this->heuristic = new Heuristic();
}

GROS::~GROS()
{
    delete this->heuristic;
}

void GROS::init(std::vector<nodePtr> nodes, std::vector<entityPtr> entities)
{
    this->nodes.clear();
    this->entities.clear();
    this->nodes = nodes;
    this->entities = entities;

    this->heuristic->init(this->nodes, this->entities);

}
