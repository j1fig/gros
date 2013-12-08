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
#include <boost/shared_ptr.hpp>


#include "dynamicmodel.h"
#include "../../constants.h"
#include "../../node/node.h"
#include "../../entity/entity.h"


class DynamicSim
{
public:
    DynamicSim();
    virtual ~DynamicSim();

    virtual void init              (std::vector<Node::Ptr> nodes,std::vector<Entity::Ptr> entities);

    virtual float timeToNextNode   (char* entityId);

    virtual float nodeDistance	    (short node1, short node2);

    virtual short update          (float timeStep);

    virtual Node::Ptr findNode       (int number);

    virtual Entity::Ptr findEntity   (char* id);

private:
    boost::shared_ptr<DynamicModel> dynamicModel;

    std::vector<Node::Ptr> nodes;
    std::vector<Entity::Ptr> entities;

//    std::priority_queue<Node,std::vector<Node>,Node::OrderByNumber> _nodeQueue;
//    std::priority_queue<Entity,std::vector<Entity>,Entity::OrderByID> _entityQueue;
};

#endif // DYNAMICSIM_H
