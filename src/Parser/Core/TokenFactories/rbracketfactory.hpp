#ifndef RBRACKETFACTORY_HPP
#define RBRACKETFACTORY_HPP

#include "tokenfactory.hpp"

#include <Core/Predicates/CharPredicates/rbracketpr.hpp>

class RBracketFactory : public TokenFactory
{
public:
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    RBracketPr m_rbracketPr;

};

#endif // RBRACKETFACTORY_HPP
