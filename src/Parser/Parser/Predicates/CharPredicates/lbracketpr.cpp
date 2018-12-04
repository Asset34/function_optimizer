#include "lbracketpr.hpp"

LBracketPr::~LBracketPr()
{
}

bool LBracketPr::execute(QChar ch) const
{
    return ch == '(';
}
