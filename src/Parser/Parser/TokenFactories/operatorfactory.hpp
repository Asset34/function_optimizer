#ifndef OPERATORFACTORY_HPP
#define OPERATORFACTORY_HPP

#include "tokenfactory.hpp"
#include "../Tokens/binaryoptoken.hpp"
#include "../Tokens/unaryoptoken.hpp"
#include "../Predicates/CharPredicates/operatorpr.hpp"
#include "../Predicates/CharPredicates/lbracketpr.hpp"
#include "../tables.hpp"
#include "../../utils.hpp"

#include <QString>

class OperatorFactory : public TokenFactory
{
public:
    virtual ~OperatorFactory();
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    OperatorPr m_operatorPr;
    LBracketPr m_lbracketPr;

    bool checkUnaryOp(const Position &pos) const;
};

#endif // OPERATORFACTORY_HPP
