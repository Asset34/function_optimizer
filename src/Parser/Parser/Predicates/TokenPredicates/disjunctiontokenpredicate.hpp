#ifndef DISJUNCTIONTOKENPREDICATE_HPP
#define DISJUNCTIONTOKENPREDICATE_HPP

#include "tokenpredicate.hpp"

#include <QList>

class DisjunctionTokenPredicate : public TokenPredicate
{
public:
    virtual ~DisjunctionTokenPredicate();
    virtual bool execute(Token &t);

    void add(TokenPredicate *predicate);
    void remove(TokenPredicate *predicate);

private:
    QList<TokenPredicate*> m_predicates;
};

#endif // DISJUNCTIONTOKENPREDICATE_HPP
