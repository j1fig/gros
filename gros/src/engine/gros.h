#ifndef GROS_H
#define GROS_H

#include <vector>
#include <boost/smart_ptr.hpp>

#include "../entity/entity.h"
#include "../node/node.h"

// Forward declarations
class Heuristic;



class GROS 
{
public:
    
    GROS();
    virtual ~GROS();

    void run ();

private:
    void init(std::vector<Node::Ptr> nodes, std::vector<Entity::Ptr> entities);

    void addEntity(char* id);
    void removeEntity(char* id);

    void addNode(short number);
    void removeNode(short number);

    std::vector< std::vector<short> > optimizeRoutes();
    std::vector<short> optimizeRoute(char* entityId);


private:

    boost::shared_ptr<Heuristic> heuristic;

    std::vector<Node::Ptr> nodes;
    std::vector<Entity::Ptr> entities;
};

#endif // GROS_H
