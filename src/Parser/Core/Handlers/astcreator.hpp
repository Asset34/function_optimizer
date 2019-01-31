#ifndef ASTCREATOR_HPP
#define ASTCREATOR_HPP

#include <Core/emptytokenvisitor.hpp>
#include <Core/ExpTree/ExpNodes/expnode.hpp>

#include <QString>
#include <QList>
#include <QStack>

class NumberToken;
class VariableToken;
class FunctionNameToken;
class LBracketToken;
class RBracketToken;
class FuncSeparatorToken;
class UnaryOpToken;
class BinaryOpToken;

class AstCreator : public EmptyTokenVisitor
{
public:
    ExpNode *create(const QList<Token*> tokens);
    const QList<QString> &getVariablesList() const;

    virtual ~AstCreator();
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

#endif // ASTCREATOR_HPP
