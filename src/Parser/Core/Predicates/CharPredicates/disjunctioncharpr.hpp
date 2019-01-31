#ifndef DISJUNCTIONCHARPR_HPP
#define DISJUNCTIONCHARPR_HPP

#include "charpredicate.hpp"

#include <QList>

class DisjunctionCharPr : public CharPredicate
{
public:
    virtual ~DisjunctionCharPr();
    virtual bool execute(QChar ch) const;

    void add(CharPredicate *predicate);
    void remove(CharPredicate *predicate);

private:
    QList<CharPredicate*> m_predicates;

};

#endif // DISJUNCTIONCHARPRPr_HPP
