#include "rbrackettokenpredicate.hpp"

void RBracketTokenPredicate::visit(RBracketToken *t)
{
    m_result = true;
}
