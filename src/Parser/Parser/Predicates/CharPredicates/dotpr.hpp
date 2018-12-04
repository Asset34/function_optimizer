#ifndef DOTPR_HPP
#define DOTPR_HPP

#include "charpredicate.hpp"

class DotPr : public CharPredicate
{
public:
    virtual ~DotPr();
    virtual bool execute(QChar ch) const;
};

#endif // DOTPR_HPP
