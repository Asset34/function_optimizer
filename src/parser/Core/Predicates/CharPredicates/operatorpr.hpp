#ifndef OPERATORPR_HPP
#define OPERATORPR_HPP

#include "charpredicate.hpp"

class OperatorPr : public CharPredicate
{
public:
    virtual bool execute(QChar ch) const;

};

#endif // OPERATORPR_HPP
