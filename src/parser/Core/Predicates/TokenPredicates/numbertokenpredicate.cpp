#include "numbertokenpredicate.hpp"

void NumberTokenPredicate::visit(NumberToken *t)
{
    m_result = true;
}
