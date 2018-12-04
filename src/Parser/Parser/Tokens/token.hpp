#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <QString>

class TokenVisitor;

class Token
{
public:
    Token(const QString &value);

    virtual ~Token();
    virtual void accept(TokenVisitor &visitor) = 0;

    const QString &getValue() const;

private:
    QString m_value;
};

#endif // TOKEN_HPP
