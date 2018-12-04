#ifndef UNDERSCOREPR_HPP
#define UNDERSCOREPR_HPP

#include "charpredicate.hpp"

class UnderscorePr : public CharPredicate
{
public:
    virtual ~UnderscorePr();
    virtual bool execute(QChar ch) const;
};

#endif // UNDERSCOREPR_HPP
