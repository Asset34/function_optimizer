#include "numberfactory.hpp"

#include <Core/Tokens/numbertoken.hpp>
#include <Utility/utils.hpp>

#include <QString>

bool NumberFactory::check(const Position &pos) const
{
    return Utils::check(pos, m_digitPr);
}

Token *NumberFactory::takeToken(Position &pos) const
{
    if (check(pos)) {
        Position start(pos);

        // Main part of the number
        Utils::moveWhile(pos, m_digitPr);

        // Fraction part of the number
        Utils::moveWhile(pos, m_dotPr);
        Utils::moveWhile(pos, m_digitPr);

        QString strToken = Position::makeString(start, pos);
        return new NumberToken(strToken);
    }
    else {
        throw std::logic_error("Cannot take the token\n-->Position:" + pos.getNumber());
    }
}
