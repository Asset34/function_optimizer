#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <QString>

class TokenVisitor;

class Token
{
public:
    explicit Token(const QString &value);
    virtual ~Token() = default;

    const QString &getValue() const;

    virtual void accept(TokenVisitor &visitor) = 0;

private:
    QString m_value;

};

#endif // TOKEN_HPP
