#ifndef EXPNODE_HPP
#define EXPNODE_HPP

#include "../values.hpp"

class ExpNode
{
public:
    virtual ~ExpNode();
    virtual double evaluate(const Values &values) const = 0;
};

#endif // EXPNODE_HPP
