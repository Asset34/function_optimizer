#include "rbracketfactory.hpp"

RBracketFactory::~RBracketFactory()
{
}

bool RBracketFactory::check(const Position &pos) const
{
    return Utils::check(pos, m_rbracketPr);
}

Token *RBracketFactory::takeToken(Position &pos) const
{
    if (check(pos)) {
        Position start(pos);

        pos++;

        QString strToken = Position::makeString(start, pos);
        return new RBracketToken(strToken);
    }
    else {
        throw std::logic_error("Cannot take the token\n-->Position:" + pos.getNumber());
    }
}
