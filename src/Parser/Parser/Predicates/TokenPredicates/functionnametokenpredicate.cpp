#include "functionnametokenpredicate.hpp"

void FunctionNameTokenPredicate::visit(FunctionNameToken *t)
{
    m_result = true;
}
