#include "letterpr.hpp"

bool LetterPr::execute(QChar ch) const
{
    return ch.isLetter();
}
