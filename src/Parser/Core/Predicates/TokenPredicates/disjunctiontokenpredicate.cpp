#include "disjunctiontokenpredicate.hpp"

DisjunctionTokenPredicate::~DisjunctionTokenPredicate()
{
    QListIterator<TokenPredicate*> it(m_predicates);
    while (it.hasNext()) {
        delete it.next();
    }

    m_predicates.clear();
}

void DisjunctionTokenPredicate::add(TokenPredicate *predicate)
{
    m_predicates.append(predicate);
}

void DisjunctionTokenPredicate::remove(TokenPredicate *predicate)
{
    m_predicates.removeOne(predicate);
}

bool DisjunctionTokenPredicate::execute(Token &t)
{
    QListIterator<TokenPredicate*> it(m_predicates);
    while (it.hasNext()) {
        if (it.next()->execute(t)) {
            return true;
        }
    }

    return false;
}
