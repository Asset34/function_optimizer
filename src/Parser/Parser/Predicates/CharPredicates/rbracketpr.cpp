#include "rbracketpr.hpp"

RBracketPr::~RBracketPr()
{
}

bool RBracketPr::execute(QChar ch) const
{
    return ch == ')';
}
