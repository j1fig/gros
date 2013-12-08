#include "node.h"

Node::Node()
{
    this->_number = -1;
    this->_type = -1;
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;

}

Node::~Node()
{
}

short Node::getType()
{
    return this->_type;
}

short Node::getNumber()
{
    return this->_number;
}

float Node::getX(void)
{
    return this->_x;
}

float Node::getY(void)
{
    return this->_y;
}

float Node::getZ(void)
{
    return this->_z;
}

void Node::setType(short type)
{
    this->_type = type;
}

void Node::setNumber(short number)
{
    this->_number = number;
}

void Node::setX(float x)
{
    this->_x = x;
}

void Node::setY(float y)
{
    this->_y = y;
}

void Node::setZ(float z)
{
    this->_z = z;
}

std::vector<short> Node::getConnections()
{
    return this->_connections;
}

void Node::addConnection(short nodeNumber)
{
    this->_connections.push_back(nodeNumber);
}
