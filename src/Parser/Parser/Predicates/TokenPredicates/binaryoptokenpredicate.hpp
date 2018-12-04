#ifndef BINARYOOTOKENPREDICATE_HPP
#define BINARYOPTOKENPREDICATE_HPP

#include "emptytokenpredicate.hpp"

class BinaryOpTokenPredicate : public EmptyTokenPredicate
{
public:
    virtual void visit(BinaryOpToken *t);
};

#endif // BINARYOPTOKENPREDICATE_HPP
