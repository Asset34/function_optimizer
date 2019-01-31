#ifndef OPERATORFACTORY_HPP
#define OPERATORFACTORY_HPP

#include "tokenfactory.hpp"

#include <Core/Predicates/CharPredicates/operatorpr.hpp>
#include <Core/Predicates/CharPredicates/lbracketpr.hpp>

class OperatorFactory : public TokenFactory
{
public:
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    bool checkUnaryOp(const Position &pos) const;

    OperatorPr m_operatorPr;
    LBracketPr m_lbracketPr;

};

#endif // OPERATORFACTORY_HPP
