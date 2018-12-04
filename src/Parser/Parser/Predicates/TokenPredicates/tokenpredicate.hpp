#ifndef TOKENPREDICATE_HPP
#define TOKENPREDICATE_HPP

#include "../../emptytokenvisitor.hpp"

class TokenPredicate : public EmptyTokenVisitor
{
public:
    virtual ~TokenPredicate();
    virtual bool execute(Token &t) = 0;
};

#endif // TOKENPREDICATE_HPP
