#include "letterpr.hpp"

LetterPr::~LetterPr()
{
}

bool LetterPr::execute(QChar ch) const
{
    return ch.isLetter();
}
