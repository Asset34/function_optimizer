#ifndef RBRACKETFACTORY_HPP
#define RBRACKETFACTORY_HPP

#include "tokenfactory.hpp"
#include "../Tokens/rbrackettoken.hpp"
#include "../Predicates/CharPredicates/rbracketpr.hpp"
#include "../../utils.hpp"

#include <QString>

class RBracketFactory : public TokenFactory
{
public:
    virtual ~RBracketFactory();
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    RBracketPr m_rbracketPr;
};

#endif // RBRACKETFACTORY_HPP
