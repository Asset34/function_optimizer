#include "emptytokenvisitor.hpp"

void EmptyTokenVisitor::visit(NumberToken        *t){}
void EmptyTokenVisitor::visit(VariableToken      *t){}
void EmptyTokenVisitor::visit(FunctionNameToken  *t){}
void EmptyTokenVisitor::visit(LBracketToken      *t){}
void EmptyTokenVisitor::visit(RBracketToken      *t){}
void EmptyTokenVisitor::visit(FuncSeparatorToken *t){}
void EmptyTokenVisitor::visit(UnaryOpToken       *t){}
void EmptyTokenVisitor::visit(BinaryOpToken      *t){}
