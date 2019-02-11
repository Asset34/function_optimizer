#include "variabletokenpredicate.hpp"

void VariableTokenPredicate::visit(VariableToken *t)
{
    m_result = true;
}
