#include "inputfunctionbox.hpp"

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

InputFunctionBox::InputFunctionBox(QWidget *parent)
    : QWidget(parent)
{
    m_functionLineEdit = new QLineEdit;

    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Function:", m_functionLineEdit);

    setLayout(m_layout);
}

Function InputFunctionBox::getFunction()
{
    QString functionStr = m_functionLineEdit->text();
    Function function = m_parser.parse(functionStr);

    return function;
}
