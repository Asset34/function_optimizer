#include "token.hpp"

Token::Token(const QString &value)
    :m_value(value)
{
}

Token::~Token()
{
}

const QString &Token::getValue() const
{
    return m_value;
}
