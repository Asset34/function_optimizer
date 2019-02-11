#include "token.hpp"

Token::Token(const QString &value)
    :m_value(value)
{
}

const QString &Token::getValue() const
{
    return m_value;
}
