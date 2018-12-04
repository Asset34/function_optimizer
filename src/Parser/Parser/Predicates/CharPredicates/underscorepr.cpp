#include "underscorepr.hpp"

UnderscorePr::~UnderscorePr()
{
}

bool UnderscorePr::execute(QChar ch) const
{
    return ch == '_';
}
