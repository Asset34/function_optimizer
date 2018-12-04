#include "disjunctionCharPr.hpp"

DisjunctionCharPr::~DisjunctionCharPr()
{
    QListIterator<CharPredicate*> it(m_predicates);
    while (it.hasNext()) {
        delete it.next();
    }

    m_predicates.clear();
}

bool DisjunctionCharPr::execute(QChar ch) const
{
    QListIterator<CharPredicate*> it(m_predicates);
    while (it.hasNext()) {
        if (it.next()->execute(ch)) {
            return true;
        }
    }

    return false;
}

void DisjunctionCharPr::add(CharPredicate *predicate)
{
    m_predicates.append(predicate);
}

void DisjunctionCharPr::remove(CharPredicate *predicate)
{
    m_predicates.removeOne(predicate);
}
