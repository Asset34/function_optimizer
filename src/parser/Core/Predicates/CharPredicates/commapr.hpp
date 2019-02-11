#ifndef COMMAPR_HPP
#define COMMAPR_HPP

#include "charpredicate.hpp"

class CommaPr : public CharPredicate
{
public:
    virtual bool execute(char ch) const;

};

#endif // COMMAPR_HPP
