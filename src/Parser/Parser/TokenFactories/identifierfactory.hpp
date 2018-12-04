#ifndef IDENTIFIERFACTORY_HPP
#define IDENTIFIERFACTORY_HPP

#include "tokenfactory.hpp"
#include "../Tokens/variabletoken.hpp"
#include "../Tokens/functionnametoken.hpp"
#include "../Predicates/CharPredicates/letterpr.hpp"
#include "../Predicates/CharPredicates/underscorepr.hpp"
#include "../Predicates/CharPredicates/digitpr.hpp"
#include "../Predicates/CharPredicates/disjunctioncharpr.hpp"
#include "../../utils.hpp"
#include "../tables.hpp"

#include <QString>

class IdentifierFactory : public TokenFactory
{
public:
    IdentifierFactory();

    virtual ~IdentifierFactory();
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    DisjunctionCharPr m_beginIdentifierPr;
    DisjunctionCharPr m_identifierPr;

    bool functionCheck(const QString &strToken) const;
};

#endif // IDENTIFIERFACTORY_HPP
