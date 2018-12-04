#ifndef MATHTOKENIZER_HPP
#define MATHTOKENIZER_HPP

#include "../../Entities/position.hpp"
#include "../TokenFactories/funcseparatorfactory.hpp"
#include "../TokenFactories/identifierfactory.hpp"
#include "../TokenFactories/lbracketfactory.hpp"
#include "../TokenFactories/lbracketfactory.hpp"
#include "../TokenFactories/numberfactory.hpp"
#include "../TokenFactories/operatorfactory.hpp"
#include "../TokenFactories/rbracketfactory.hpp"

#include <QString>
#include <QList>

class MathTokenizer
{
public:
    MathTokenizer();
    ~MathTokenizer();

    QList<Token*> tokenize(const QString &exp) const;

private:
    void preprocess(QString &exp) const;

    QList<TokenFactory*> m_tokenFactories;
};

#endif // MATHTOKENIZER_HPP
