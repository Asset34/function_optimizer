#include "funcseparatorfactory.hpp"

FuncSeparatorFactory::~FuncSeparatorFactory()
{
}

bool FuncSeparatorFactory::check(const Position &pos) const
{
    return Utils::check(pos, m_semicolonPr);
}

Token *FuncSeparatorFactory::takeToken(Position &pos) const
{
    if (check(pos)) {
        Position start(pos);

        pos++;

        QString strToken = Position::makeString(start, pos);
        return new FuncSeparatorToken(strToken);
    }
    else {
        throw std::logic_error("Cannot take the token\n-->Position:" + pos.getNumber());
    }
}
