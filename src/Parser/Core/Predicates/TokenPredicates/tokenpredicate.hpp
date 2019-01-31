#ifndef TOKENPREDICATE_HPP
#define TOKENPREDICATE_HPP

#include <Core/emptytokenvisitor.hpp>

class TokenPredicate : public EmptyTokenVisitor
{
public:
    virtual ~TokenPredicate() = default;
    virtual bool execute(Token &t) = 0;

};

#endif // TOKENPREDICATE_HPP
