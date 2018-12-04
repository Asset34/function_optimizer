#include "lbrackettokenpredicate.hpp"

void LBracketTokenPredicate::visit(LBracketToken *t)
{
    m_result = true;
}
