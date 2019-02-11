#include "operatorfactory.hpp"

#include <Core/Tokens/binaryoptoken.hpp>
#include <Core/Tokens/unaryoptoken.hpp>

#include <Core/tables.hpp>
#include <Utility/utils.hpp>

#include <QString>

bool OperatorFactory::check(const Position &pos) const
{
    return Utils::check(pos, m_operatorPr);
}

Token *OperatorFactory::takeToken(Position &pos) const
{
    if (check(pos)) {
        Position start(pos);

        pos++;

        QString strToken = Position::makeString(start, pos);

        if (checkUnaryOp(start)) {
            return new UnaryOpToken(strToken);
        }
        else {
            return new BinaryOpToken(strToken);
        }
    }
    else {
        throw std::logic_error("Cannot take the token\n-->Position:" + pos.getNumber());
    }
}

bool OperatorFactory::checkUnaryOp(const Position &pos) const
{
    Position prevPos(pos - 1);

    if (prevPos.isBegin()) {
        return true;
    }

    if (Utils::check(prevPos, m_lbracketPr) &&
        Tables::unaryOpPriorityTable.contains(pos.getChar())) {
        return true;
    }
    else {
        return false;
    }
}
