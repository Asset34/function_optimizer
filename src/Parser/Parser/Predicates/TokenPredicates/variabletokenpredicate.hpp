#ifndef VARIABLETOKENPREDICATE_HPP
#define VARIABLETOKENPREDICATE_HPP

#include "emptytokenpredicate.hpp"

class VariableTokenPredicate : public EmptyTokenPredicate
{
public:
    virtual void visit(VariableToken *t);
};

#endif // VARIABLETOKENPREDICATE_HPP
