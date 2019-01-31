#include "parser.hpp"


Function Parser::parse(const QString &exp)
{
    QList<Token*> tokens = m_tokenizer.tokenize(exp);
    m_grammarScanner.Scann(tokens);
    tokens = m_rpnConverter.convert(tokens);
    ExpNode *expTree = m_astCreator.create(tokens);

    QVector<QString> variables = m_astCreator.getVariablesList().toVector();

    return Function(exp, std::unique_ptr<ExpNode>(expTree), variables);
}
