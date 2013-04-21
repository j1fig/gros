#ifndef NODE_H
#define NODE_H

#include <cstdio>
#include <vector>

class Node
{
public:
    Node			(void);
    virtual ~Node	(void);

    short getType	(void);
    short getNumber	(void);
    float getX		(void);
    float getY		(void);
    float getZ		(void);

    void setType	(short type);
    void setNumber	(short number);
    void setX		(float x);
    void setY		(float y);
    void setZ		(float z);

    void addConnection              (short nodeNumber);
    std::vector<short> getConnections	();

    struct OrderByNumber
    {
        bool operator() (const Node& lhs,const Node& rhs)
        {
            return lhs._number>rhs._number;
        }
    };

private:

    // Node Type
    short _type;

    // Node number
    short _number;

    // Node spatial coordinates
    float _x;
    float _y;
    float _z;

    std::vector<short> _connections;
};

#endif // NODE_H
