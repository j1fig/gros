#ifndef HEURISTIC_H
#define HEURISTIC_H

#include <vector>
#include <map>
#include <iostream>
#include <boost/smart_ptr.hpp>

#include "../node/node.h"
#include "../entity/entity.h"


// Forward declarations
class DynamicSim;
class Utils;


class Heuristic
{
public:
    Heuristic();
    virtual ~Heuristic();

    void init(std::vector<Node::Ptr> nodes, std::vector<Entity::Ptr> entities);

private:
    struct Vertex
    {
        float dist;
        float pred;
        char vertex;
    };

    void constructGraph				(void);
    std::map<char,float> Dijkstra	(char node);

    float getOptimisticCost			(short node1, short node2);

    boost::shared_ptr<DynamicSim> dynamicSim;

    std::vector<Node::Ptr> nodes;
    std::vector<Entity::Ptr> entities;

    std::map< char, std::map<char,float> > graph;
    std::map< char, std::map<char,float> > heuristic;
};

#endif // HEURISTIC_H
