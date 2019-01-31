#include "unaryoptokenpredicate.hpp"

void UnaryOpTokenPredicate::visit(UnaryOpToken *t)
{
    m_result = true;
}
