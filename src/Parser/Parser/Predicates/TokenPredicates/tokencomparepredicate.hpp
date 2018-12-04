#ifndef TOKENCOMPAREPREDICATE_HPP
#define TOKENCOMPAREPREDICATE_HPP

#include "../../emptytokenvisitor.hpp"

class TokenComparePredicate : public EmptyTokenVisitor
{
public:
    virtual ~TokenComparePredicate();
    virtual bool execute(Token &t1, Token &t2) = 0;
};

#endif // TOKENCOMPAREPREDICATE_HPP
