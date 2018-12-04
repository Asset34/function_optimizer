#ifndef COMMAPR_HPP
#define COMMAPR_HPP

#include "charpredicate.hpp"

class CommaPr : public CharPredicate
{
public:
    virtual ~CommaPr();

    virtual bool execute(char ch) const;

private:

protected:
};

#endif // COMMAPR_HPP
