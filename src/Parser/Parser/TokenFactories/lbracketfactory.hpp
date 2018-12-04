#ifndef LBRACKETFACTORY_HPP
#define LBRACKETFACTORY_HPP

#include "tokenfactory.hpp"
#include "../Tokens/lbrackettoken.hpp"
#include "../Predicates/CharPredicates/lbracketpr.hpp"
#include "../../utils.hpp"

#include <QString>

class LBracketFactory : public TokenFactory
{
public:
    virtual ~LBracketFactory();
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    LBracketPr m_lbracketPr;
};

#endif // LBRACKETFACTORY_HPP
