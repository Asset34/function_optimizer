#include "identifierfactory.hpp"

IdentifierFactory::IdentifierFactory()
{
    m_beginIdentifierPr.add(new UnderscorePr);
    m_beginIdentifierPr.add(new LetterPr);

    m_identifierPr.add(new UnderscorePr);
    m_identifierPr.add(new LetterPr);
    m_identifierPr.add(new DigitPr);
}

IdentifierFactory::~IdentifierFactory()
{
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
