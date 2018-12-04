#ifndef RBRACKETtTOKENPREDICATE_HPP
#define RBRACKETTOKENPREDICATE_HPP

#include "emptytokenpredicate.hpp"

class RBracketTokenPredicate : public EmptyTokenPredicate
{
public:
    virtual void visit(RBracketToken *t);
};

#endif // RBRACKETTOKENPREDICATE_HPP
