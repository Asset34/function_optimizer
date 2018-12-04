#ifndef LETTERPR_HPP
#define LETTERPR_HPP

#include "charpredicate.hpp"

class LetterPr : public CharPredicate
{
public:
    virtual ~LetterPr();
    virtual bool execute(QChar ch) const;
};

#endif // LETTERPR_HPP
