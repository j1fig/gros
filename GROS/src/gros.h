#ifndef GROS_H
#define GROS_H

#include <vector>

#include "Entity/entity.h"
#include "Node/node.h"

// Forward declarations
class DynamicSim;
class Heuristic;


class GROS {
public:
    GROS();
    virtual ~GROS();

    void init();
    void init(std::vector<Node> nodes, std::vector<Entity> entities);

    void addEntity(char* id);
    void removeEntity(char* id);

    void addNode(short number);
    void removeNode(short number);

    std::vector< std::vector<short> > optimizeRoutes();
    std::vector<short> optimizeRoute(char* entityId);


private:

    DynamicSim* _dynamicSim;
    Heuristic* _heuristic;

    std::vector<Entity> _entities;
    std::vector<Node> _nodes;
};

#endif // GROS_H
