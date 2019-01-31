#include "lbracketfactory.hpp"

#include <Utility//utils.hpp>

#include <QString>

bool LBracketFactory::check(const Position &pos) const
{
    return Utils::check(pos, m_lbracketPr);
}

Token *LBracketFactory::takeToken(Position &pos) const
{
    if (check(pos)) {
        Position start(pos);

        pos++;

        QString strToken = Position::makeString(start, pos);
        return new LBracketToken(strToken);
    }
    else {
        throw std::logic_error("Cannot take the token\n-->Position:" + pos.getNumber());
    }
}
