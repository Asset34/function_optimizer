#include "functioninputbox.hpp"

FunctionInputBox::FunctionInputBox(QWidget *parent)
    : QComboBox(parent)
{
    setEditable(true);
}

QString FunctionInputBox::getExpression() const
{
    return currentText();
}

void FunctionInputBox::setExpression(const QString &expression)
{
    setCurrentText(expression);
}

void FunctionInputBox::addExpression(const QString &expression)
{
    addItem(expression);
}

Function FunctionInputBox::parseExpression()
{
    return m_parser.parse(currentText());
}
