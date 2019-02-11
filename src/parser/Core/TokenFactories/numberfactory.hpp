#ifndef NUMBERFACTORY_HPP
#define NUMBERFACTORY_HPP

#include "tokenfactory.hpp"

#include <Core/Predicates/CharPredicates/digitpr.hpp>
#include <Core/Predicates/CharPredicates/dotpr.hpp>

class NumberFactory : public TokenFactory
{
public:
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    DigitPr m_digitPr;
    DotPr m_dotPr;

};

#endif // NUMBERFACTORY_HPP
