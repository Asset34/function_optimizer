#ifndef NUMBERLEAF_HPP
#define NUMBERLEAF_HPP

#include "../expnode.hpp"

class NumberLeaf : public ExpNode
{
public:
    NumberLeaf(double value);

    virtual ~NumberLeaf();
    virtual double evaluate(const Values &values) const;

private:
    double m_value;
};

#endif // NUMBERLEAF_HPP
