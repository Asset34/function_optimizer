#include "digitpr.hpp"

DigitPr::~DigitPr()
{
}

bool DigitPr::execute(QChar ch) const
{
    return ch.isDigit();
}
