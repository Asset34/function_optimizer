#ifndef LBRACKETPR_HPP
#define LBRACKETPR_HPP

#include "charpredicate.hpp"

class LBracketPr : public CharPredicate
{
public:
    virtual ~LBracketPr();
    virtual bool execute(QChar ch) const;
};

#endif // LBRACKETPR_HPP
