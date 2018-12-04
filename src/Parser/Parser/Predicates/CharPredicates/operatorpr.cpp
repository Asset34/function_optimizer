#include "operatorpr.hpp"

OperatorPr::~OperatorPr()
{
}

bool OperatorPr::execute(QChar ch) const
{
    return ch == '+' ||
           ch == '-' ||
           ch == '*' ||
           ch == '/' ||
           ch == '^';
}
