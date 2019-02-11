#ifndef LBRACKETTOKENPREDICATE_HPP
#define LBRACKETTOKENPREDICATE_HPP

#include "emptytokenpredicate.hpp"

class LBracketTokenPredicate : public EmptyTokenPredicate
{
public:
    virtual void visit(LBracketToken *t);

};

#endif // LBRACKETTOKENPREDICATE_HPP
