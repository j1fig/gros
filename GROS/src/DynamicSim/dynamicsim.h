///////////////////////////////////////////////////////////
//  DynamicSim.h
//  Implementation of the Class DynamicManager
//  Created on:      21-April-2012 14:34:36
//  Original author: joao.figueiredo
///////////////////////////////////////////////////////////

#ifndef DYNAMICSIM_H
#define DYNAMICSIM_H

#include <vector>
#include <queue>

#include "dynamicmodel.h"
#include "../constants.h"
#include "../Node/node.h"
#include "../Entity/entity.h"

class DynamicSim: protected DynamicModel
{
public:
    DynamicSim();
    virtual ~DynamicSim	();

    virtual void init               ();
    virtual void init               (std::vector<Node> nodes,std::vector<Entity> entities);

    virtual float timeToNextNode     (char* entityId);

    virtual float nodeDistance	(short node1, short node2);

    virtual short update        (float timeStep);

    virtual std::vector<Node> getNodes       (void);

    virtual std::vector<Entity> getEntities  (void);

    virtual Node findNode       (int number);

    virtual Entity findEntity   (char* id);

private:

    std::vector<Node> _nodes;
//    std::priority_queue<Node,std::vector<Node>,Node::OrderByNumber> _nodeQueue;

    std::vector<Entity> _entities;
//    std::priority_queue<Entity,std::vector<Entity>,Entity::OrderByID> _entityQueue;
};

#endif // DYNAMICSIM_H
