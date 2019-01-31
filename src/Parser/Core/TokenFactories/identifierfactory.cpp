#include "identifierfactory.hpp"

#include <Core/Tokens/variabletoken.hpp>
#include <Core/Tokens/functionnametoken.hpp>
#include <Core/Predicates/CharPredicates/letterpr.hpp>
#include <Core/Predicates/CharPredicates/underscorepr.hpp>
#include <Core/Predicates/CharPredicates/digitpr.hpp>
#include <Core/Predicates/CharPredicates/disjunctioncharpr.hpp>

#include <Utility/utils.hpp>
#include <Core/tables.hpp>

#include <QString>

IdentifierFactory::IdentifierFactory()
{
    m_beginIdentifierPr.add(new UnderscorePr);
    m_beginIdentifierPr.add(new LetterPr);

    m_identifierPr.add(new UnderscorePr);
    m_identifierPr.add(new LetterPr);
    m_identifierPr.add(new DigitPr);
}

bool IdentifierFactory::check(const Position &pos) const
{
    return Utils::check(pos, m_beginIdentifierPr);
}

Token *IdentifierFactory::takeToken(Position &pos) const
{
    if (check(pos)) {
        Position start(pos);

        Utils::moveWhile(pos, m_identifierPr);

        QString strToken = Position::makeString(start, pos);

        // Specificate identificator
        if (functionCheck(strToken)) {
            return new FunctionNameToken(strToken);
        }
        else {
            return new VariableToken(strToken);
        }
    }
    else {
        throw std::logic_error("Cannot take the token\n-->Position:" + pos.getNumber());
    }
}

bool IdentifierFactory::functionCheck(const QString &strToken) const
{
    return Tables::functionArgNumberTable.contains(strToken);
}
