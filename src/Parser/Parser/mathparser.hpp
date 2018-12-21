#ifndef MATHPARSER_HPP
#define MATHPARSER_HPP

#include "Handlers/mathtokenizer.hpp"
#include "Handlers/mathgrammarscanner.hpp"
#include "Handlers/mathrpnconverter.hpp"
#include "Handlers/mathastcreator.hpp"
#include "../Functions/function.hpp"

#include <QString>

class MathParser
{
public:
    Function parse(const QString &exp);

private:
    /* Handlers */
    MathTokenizer      m_mathTokenizer;
    MathGrammarScanner m_mathGrammarScanner;
    MathRPNConverter   m_mathRpnConverter;
    MathASTCreator     m_mathAstCreator;
};

#endif // MATHPARSER_HPP
