#include "tokenizer.hpp"

#include <Utility/position.hpp>

#include <Core/TokenFactories/funcseparatorfactory.hpp>
#include <Core/TokenFactories/identifierfactory.hpp>
#include <Core/TokenFactories/lbracketfactory.hpp>
#include <Core/TokenFactories/lbracketfactory.hpp>
#include <Core/TokenFactories/numberfactory.hpp>
#include <Core/TokenFactories/operatorfactory.hpp>
#include <Core/TokenFactories/rbracketfactory.hpp>

Tokenizer::Tokenizer()
{
    m_tokenFactories.append(new NumberFactory       );
    m_tokenFactories.append(new IdentifierFactory   );
    m_tokenFactories.append(new OperatorFactory     );
    m_tokenFactories.append(new FuncSeparatorFactory);
    m_tokenFactories.append(new LBracketFactory     );
    m_tokenFactories.append(new RBracketFactory     );
}

Tokenizer::~Tokenizer()
{
    QListIterator<TokenFactory*> it(m_tokenFactories);
    while (it.hasNext()) {
        delete it.next();
    }

    m_tokenFactories.clear();
}

QList<Token*> Tokenizer::tokenize(const QString &exp) const
{
    QString processedExp(exp);

    // Preprocessing
    preprocess(processedExp);

    // Tokenization
    QList<Token*> tokens;
    Position pos(processedExp);

    QListIterator<TokenFactory*> it(m_tokenFactories);
    TokenFactory *currentFactory = nullptr;

    while (!pos.isEnd()) {
        it.toFront();

        while (it.hasNext()) {
            currentFactory = it.next();
            if (currentFactory->check(pos)) {
                tokens.append(currentFactory->takeToken(pos));
            }
        }
    }

    return tokens;
}

void Tokenizer::preprocess(QString &exp) const
{
    exp.replace(" ", "");
}
