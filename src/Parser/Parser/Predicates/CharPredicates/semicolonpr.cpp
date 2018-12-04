#include "semicolonpr.hpp"

SemicolonPr::~SemicolonPr()
{
}

bool SemicolonPr::execute(QChar ch) const
{
    return ch == ';';
}
