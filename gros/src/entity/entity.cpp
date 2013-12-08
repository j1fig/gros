#include "entity.h"
#include "../utils/utils.h"
#include <cstring>

Entity::Entity(const char *id)
{
    memset(this->_id,0,MAX_ENTITY_STRING_SIZE);
    Utils::charCopy(this->_id,id,MAX_ENTITY_STRING_SIZE);

    // State init
    this->_command = 0;
    this->_inTransit = false;

    // Dynamic Info Init
    memset(&this->_state,0,sizeof(this->_state));

    // Route info init
    this->_percentNode = 0;
    this->_targetNode = -1;
    this->_originNode = -1;
    this->_destinationNode = -1;
}

Entity::~Entity()
{
}

float Entity::getPercentNode(void)
{
    return this->_percentNode;
}

State_t Entity::getState()
{
    return this->_state;
}

short Entity::getCommand(void)
{
    return this->_command;
}

short Entity::getOriginNode(void)
{
    return this->_originNode;
}

short Entity::getDestinationNode(void)
{
    return this->_destinationNode;
}

short Entity::getTargetNode(void)
{
    return this->_targetNode;
}

std::vector<short> Entity::getRoute(void)
{
    return this->_route;
}

bool Entity::inTransit()
{
    return this->_inTransit;
}

char* Entity::getID(void)
{
    return this->_id;
}


void Entity::setCommand(short command)
{
    this->_command = command;
}

void Entity::setDestinationNode(short node)
{
    this->_destinationNode = node;
}

void Entity::setInTransit(bool inTransit)
{
    this->_inTransit = inTransit;
}

void Entity::setOriginNode(short node)
{
    this->_originNode = node;
}

void Entity::setPercentNode(float percent)
{
    this->_percentNode = percent;
}

void Entity::setState(State_t state)
{
    memcpy(&this->_state,&state,sizeof(this->_state));
}

void Entity::setRoute(std::vector<short> route)
{
    this->_route = route;
}


void Entity::setTargetNode(short node)
{
    this->_targetNode = node;
}
