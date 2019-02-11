#ifndef NUMBERTOKENPREDICATE_HPP
#define NUMBERTOKENPREDICATE_HPP

#include "emptytokenpredicate.hpp"

class NumberTokenPredicate : public EmptyTokenPredicate
{
public:
    virtual void visit(NumberToken *t);

};

#endif // NUMBERTOKENPREDICATE_HPP
