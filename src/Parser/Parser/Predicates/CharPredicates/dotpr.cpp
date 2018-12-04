#include "dotpr.hpp"

DotPr::~DotPr()
{
}

bool DotPr::execute(QChar ch) const
{
    return ch == '.';
}
