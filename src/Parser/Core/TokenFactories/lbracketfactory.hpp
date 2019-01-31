#ifndef LBRACKETFACTORY_HPP
#define LBRACKETFACTORY_HPP

#include "tokenfactory.hpp"

#include <Core/Tokens/lbrackettoken.hpp>
#include <Core/Predicates/CharPredicates/lbracketpr.hpp>

class LBracketFactory : public TokenFactory
{
public:
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    LBracketPr m_lbracketPr;

};

#endif // LBRACKETFACTORY_HPP
