#ifndef HEURISTIC_H
#define HEURISTIC_H

#include <vector>
#include <map>
#include <iostream>
#include "../Node/node.h"

// Forward declarations
class DynamicSim;
class Utils;


class Heuristic
{
public:
    Heuristic();
    virtual ~Heuristic();

    friend class GROS;

private:
    struct Vertex
    {
        float dist;
        float pred;
        char vertex;
    };

    void init();
    void init(std::vector<Node> nodes);

    void constructGraph				(void);
    std::map<char,float> Dijkstra	(char node);

    float getOptimisticCost			(short node1, short node2);

    DynamicSim* _dynamicSim;


    std::vector<Node> _nodes;
    std::map< char, std::map<char,float> > _graph;

    std::map< char, std::map<char,float> > _heuristic;
};

#endif // HEURISTIC_H
