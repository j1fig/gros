#ifndef GROS_H
#define GROS_H

#include <vector>
#include <tr1/memory>

#include "../entity/entity.h"
#include "../node/node.h"

// Forward declarations
class Heuristic;

typedef std::tr1::shared_ptr<Entity> entityPtr;
typedef std::tr1::shared_ptr<Node> nodePtr;


class GROS {
public:
    GROS();
    virtual ~GROS();

    void init(std::vector<nodePtr> nodes, std::vector<entityPtr> entities);

    void addEntity(char* id);
    void removeEntity(char* id);

    void addNode(short number);
    void removeNode(short number);

    std::vector< std::vector<short> > optimizeRoutes();
    std::vector<short> optimizeRoute(char* entityId);


private:

    Heuristic* heuristic;

    std::vector<nodePtr> nodes;
    std::vector<entityPtr> entities;
};

#endif // GROS_H
