#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <QString>
#include <QList>

#include <Core/Tokens/token.hpp>
#include <Core/TokenFactories/tokenfactory.hpp>

class Tokenizer
{
public:
    Tokenizer();
    ~Tokenizer();

    QList<Token*> tokenize(const QString &exp) const;

private:
    void preprocess(QString &exp) const;

    QList<TokenFactory*> m_tokenFactories;
};

#endif // TOKENIZER_HPP
