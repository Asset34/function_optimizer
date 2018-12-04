#ifndef NUMBERFACTORY_HPP
#define NUMBERFACTORY_HPP

#include "tokenfactory.hpp"
#include "../Tokens/numbertoken.hpp"
#include "../Predicates/CharPredicates/digitpr.hpp"
#include "../Predicates/CharPredicates/dotpr.hpp"
#include "../../utils.hpp"

#include <QString>

class NumberFactory : public TokenFactory
{
public:
    virtual ~NumberFactory();
    virtual bool check(const Position &pos) const;
    virtual Token *takeToken(Position &pos) const;

private:
    DigitPr m_digitPr;
    DotPr m_dotPr;
};

#endif // NUMBERFACTORY_HPP
