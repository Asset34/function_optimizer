#include "compareprioritytokenpredicate.hpp"

ComparePriorityTokenPredicate::~ComparePriorityTokenPredicate()
{
}

bool ComparePriorityTokenPredicate::execute(Token &t1, Token &t2)
{
    // Get priority of t1
    int priority1;
    t1.accept(*this);
    priority1 = m_value;

    // Get priority of t2
    int priority2;
    t2.accept(*this);
    priority2 = m_value;

    // Compare
    if (priority1 <= priority2) {
        return true;
    }
    else {
        return false;
    }
}

void ComparePriorityTokenPredicate::visit(LBracketToken *t)
{
    setPriority(0);
}

void ComparePriorityTokenPredicate::visit(RBracketToken *t)
{
    setPriority(0);
}

void ComparePriorityTokenPredicate::visit(UnaryOpToken *t)
{
    QChar op = t->getValue()[0];
    setPriority(Tables::unaryOpPriorityTable[op]);
}

void ComparePriorityTokenPredicate::visit(BinaryOpToken *t)
{
    QChar op = t->getValue()[0];
    setPriority(Tables::binaryOpPriorityTable[op]);
}

void ComparePriorityTokenPredicate::setPriority(int priority)
{
    m_value = priority;
}
