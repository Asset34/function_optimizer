#ifndef SEMICOLONPR_HPP
#define SEMICOLONPR_HPP

#include "charpredicate.hpp"

class SemicolonPr : public CharPredicate
{
public:
    virtual ~SemicolonPr();
    virtual bool execute(QChar ch) const;
};

#endif // SEMICOLONPR_HPP
