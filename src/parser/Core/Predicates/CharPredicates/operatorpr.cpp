#include "operatorpr.hpp"

bool OperatorPr::execute(QChar ch) const
{
    return ch == '+' ||
           ch == '-' ||
           ch == '*' ||
           ch == '/' ||
           ch == '^';
}
