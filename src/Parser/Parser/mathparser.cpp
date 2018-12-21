#include "mathparser.hpp"

Function MathParser::parse(const QString &exp)
{
    // Handle
    QList<Token*> tokens = m_mathTokenizer.tokenize(exp);
    m_mathGrammarScanner.Scann(tokens);
    tokens = m_mathRpnConverter.convert(tokens);
    ExpNode *expTree = m_mathAstCreator.create(tokens);

    QVector<QString> variables = m_mathAstCreator.getVariablesList().toVector();

    return Function(exp, expTree, variables);
}
