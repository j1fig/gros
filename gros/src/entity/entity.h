#ifndef ENTITY_H
#define ENTITY_H

#define MAX_ENTITY_STRING_SIZE 10

#include <boost/smart_ptr.hpp>
#include <vector>
#include <cstring>
#include "../constants.h"

class Utils;

using namespace std;

class Entity
{
public:
    typedef boost::shared_ptr<Entity> Ptr;

    Entity				(const char* id);
    virtual ~Entity		();

    void setOriginNode		(short node);
    void setDestinationNode	(short node);
    void setPercentNode		(float percent);
    void setState           (State_t state);
    void setCommand			(short command);
    void setTargetNode		(short node);
    void setRoute			(std::vector<short> route);
    void setInTransit		(bool inTransit);

    short getOriginNode		(void);
    short getDestinationNode(void);
    float getPercentNode	(void);
    State_t getState        (void);
    short getCommand		(void);
    short getTargetNode		(void);
    std::vector<short> getRoute	(void);
    bool inTransit		(void);
    char* getID	(void);

    struct OrderByID
    {
        bool operator() (const Entity& lhs,const Entity& rhs)
        {
            return (strcmp(lhs._id,rhs._id)>0);
        }
    };

private:
    char _id[MAX_ENTITY_STRING_SIZE];

    short _originNode;
    short _destinationNode;
    float _percentNode;

    State_t _state;

    short _command;

    short _targetNode;

    std::vector<short> _route;

    bool _inTransit;

};

#endif // ENTITY_H
