#ifndef PARSER_HPP
#define PARSER_HPP

#include <Core/Handlers/tokenizer.hpp>
#include <Core/Handlers/grammarscanner.hpp>
#include <Core/Handlers/rpnconverter.hpp>
#include <Core/Handlers/astcreator.hpp>

#include "function.hpp"

#include <QString>

class Parser
{
public:
    Function parse(const QString &exp);

private:
    Tokenizer      m_tokenizer;
    GrammarScanner m_grammarScanner;
    RpnConverter   m_rpnConverter;
    AstCreator     m_astCreator;

};

#endif // PARSER_HPP
