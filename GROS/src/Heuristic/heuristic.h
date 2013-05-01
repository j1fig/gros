#ifndef HEURISTIC_H
#define HEURISTIC_H

#include <vector>
#include <map>
#include <iostream>
#include <tr1/memory>

#include "../Node/node.h"
#include "../Entity/entity.h"

typedef std::tr1::shared_ptr<Entity> entityPtr;
typedef std::tr1::shared_ptr<Node> nodePtr;

// Forward declarations
class DynamicSim;
class Utils;


class Heuristic
{
public:
    Heuristic();
    virtual ~Heuristic();

    void init(std::vector<nodePtr> nodes, std::vector<entityPtr> entities);

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

    DynamicSim* dynamicSim;

    std::vector<nodePtr> nodes;
    std::vector<entityPtr> entities;

    std::map< char, std::map<char,float> > graph;
    std::map< char, std::map<char,float> > heuristic;
};

#endif // HEURISTIC_H
