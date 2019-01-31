#ifndef FUNCTIONNAMETOKENPREDICATE_HPP
#define FUNCTIONNAMETOKENPREDICATE_HPP

#include "emptytokenpredicate.hpp"

class FunctionNameTokenPredicate : public EmptyTokenPredicate
{
public:
    virtual void visit(FunctionNameToken *t);

};

#endif // FUNCTIONNAMETOKENPREDICATE_HPP
