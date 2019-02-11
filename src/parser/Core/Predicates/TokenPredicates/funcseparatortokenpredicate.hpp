#ifndef FUNCSEPARATORTOKENPREDICATE_HPP
#define FUNCSEPARATORTOKENPREDICATE_HPP

#include "emptytokenpredicate.hpp"

class FuncSeparatorTokenPredicate : public EmptyTokenPredicate
{
public:
    virtual void visit(FuncSeparatorToken *t);

};

#endif // FUNCSEPARATORTOKENPREDICATE_HPP
