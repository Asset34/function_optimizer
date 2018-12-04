#include "funcseparatortokenpredicate.hpp"

void FuncSeparatorTokenPredicate::visit(FuncSeparatorToken *t)
{
    m_result = true;
}
