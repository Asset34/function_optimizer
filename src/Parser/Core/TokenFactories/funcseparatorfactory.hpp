#ifndef FuncSeparatorFACTORY_HPP
#define FuncSeparatorFACTORY_HPP

#include "tokenfactory.hpp"

#include <Core/Predicates/CharPredicates/semicolonpr.hpp>

class FuncSeparatorFactory : public TokenFactory
{
public:
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    SemicolonPr m_semicolonPr;

};

#endif // FuncSeparatorFACTORY_HPP
