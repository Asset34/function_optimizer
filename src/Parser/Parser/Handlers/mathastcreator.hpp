#ifndef MATHASTCREATOR_HPP
#define MATHASTCREATOR_HPP

#include "../emptytokenvisitor.hpp"
#include "../Tokens/binaryoptoken.hpp"
#include "../Tokens/funcseparatortoken.hpp"
#include "../Tokens/functionnametoken.hpp"
#include "../Tokens/lbrackettoken.hpp"
#include "../Tokens/numbertoken.hpp"
#include "../Tokens/rbrackettoken.hpp"
#include "../Tokens/unaryoptoken.hpp"
#include "../Tokens/variabletoken.hpp"
#include "../ExpTree/ExpNodes/expnode.hpp"
#include "../ExpTree/ExpNodes/ExpLeafes/numberleaf.hpp"
#include "../ExpTree/ExpNodes/ExpLeafes/variableleaf.hpp"
#include "../tables.hpp"

#include <QString>
#include <QList>
#include <QVector>
#include <QStack>

class MathASTCreator : public EmptyTokenVisitor
{
public:
    ExpNode *create(const QList<Token*> tokens);
    const QList<QString> &getVariablesList() const;

    virtual ~MathASTCreator();
    virtual void visit(NumberToken        *t);
    virtual void visit(VariableToken      *t);
    virtual void visit(FunctionNameToken  *t);
    virtual void visit(UnaryOpToken       *t);
    virtual void visit(BinaryOpToken      *t);

private:
    void reset();

    QList<QString> m_variables;
    QStack<ExpNode*> m_expTree;
};

#endif // MATHASTCREATOR_HPP
