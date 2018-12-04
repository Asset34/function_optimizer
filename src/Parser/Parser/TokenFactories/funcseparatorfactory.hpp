#ifndef FuncSeparatorFACTORY_HPP
#define FuncSeparatorFACTORY_HPP

#include "tokenfactory.hpp"
#include "../Tokens/funcseparatortoken.hpp"
#include "../Predicates/CharPredicates/semicolonpr.hpp"
#include "../../utils.hpp"

#include <QString>

class FuncSeparatorFactory : public TokenFactory
{
public:
    virtual ~FuncSeparatorFactory();
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    SemicolonPr m_semicolonPr;
};

#endif // FuncSeparatorFACTORY_HPP
