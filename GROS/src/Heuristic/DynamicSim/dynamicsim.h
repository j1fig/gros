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
#include <tr1/memory>

#include "dynamicmodel.h"
#include "../../constants.h"
#include "../../Node/node.h"
#include "../../Entity/entity.h"

typedef std::tr1::shared_ptr<Entity> entityPtr;
typedef std::tr1::shared_ptr<Node> nodePtr;


class DynamicSim
{
public:
    DynamicSim();
    virtual ~DynamicSim();

    virtual void init              (std::vector<nodePtr> nodes,std::vector<entityPtr> entities);

    virtual float timeToNextNode   (char* entityId);

    virtual float nodeDistance	    (short node1, short node2);

    virtual short update          (float timeStep);

    virtual nodePtr findNode       (int number);

    virtual entityPtr findEntity   (char* id);

private:
    DynamicModel* dynamicModel;

    std::vector<nodePtr> nodes;
    std::vector<entityPtr> entities;

//    std::priority_queue<Node,std::vector<Node>,Node::OrderByNumber> _nodeQueue;
//    std::priority_queue<Entity,std::vector<Entity>,Entity::OrderByID> _entityQueue;
};

#endif // DYNAMICSIM_H
