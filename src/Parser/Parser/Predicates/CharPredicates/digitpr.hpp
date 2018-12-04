#ifndef DIGITPR_HPP
#define DIGITPR_HPP

#include "charpredicate.hpp"

class DigitPr : public CharPredicate
{
public:
    virtual ~DigitPr();
    virtual bool execute(QChar ch) const;
};

#endif // DIGITPR_HPP
