#include "emptytokenpredicate.hpp"

EmptyTokenPredicate::~EmptyTokenPredicate()
{

}

bool EmptyTokenPredicate::execute(Token &t)
{
    m_result = false;
    t.accept(*this);
    return m_result;
}
