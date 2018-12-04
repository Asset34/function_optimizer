#ifndef UNARYOPTOKENPREDICATE_HPP
#define UNARYOPTOKENPREDICATE_HPP

#include "emptytokenpredicate.hpp"

class UnaryOpTokenPredicate : public EmptyTokenPredicate
{
public:
    virtual void visit(UnaryOpToken *t);
};

#endif // UNARYOPTOKENPREDICATE_HPP
