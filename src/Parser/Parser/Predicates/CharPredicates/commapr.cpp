#include "commapr.hpp"

CommaPr::~CommaPr()
{
}

bool CommaPr::execute(char ch) const
{
    return ch == ',';
}
