#ifndef RBRACKETPR_HPP
#define RBRACKETPR_HPP

#include "charpredicate.hpp"

class RBracketPr : public CharPredicate
{
public:
    virtual bool execute(QChar ch) const;

};

#endif // RBRACKETPR_HPP
