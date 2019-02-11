#ifndef EMPTYTOKENPREDICATE_HPP
#define EMPTYTOKENPREDICATE_HPP

#include "tokenpredicate.hpp"

class EmptyTokenPredicate : public TokenPredicate
{
public:
    virtual bool execute(Token &t);

protected:
    bool m_result;

};

#endif // EMPTYTOKENPREDICATE_HPP
