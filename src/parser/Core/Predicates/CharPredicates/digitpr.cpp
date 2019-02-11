#include "digitpr.hpp"

bool DigitPr::execute(QChar ch) const
{
    return ch.isDigit();
}
