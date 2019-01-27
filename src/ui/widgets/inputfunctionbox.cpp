#include "inputfunctionbox.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


InputFunctionBox::InputFunctionBox(QWidget *parent)
    : QWidget(parent)
{
    // Create widgets
    m_functionLineEdit = new QLineEdit;
    m_parsePushButton = new QPushButton("Parse");

    // Create layout
    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_functionLineEdit);
    m_layout->addWidget(m_parsePushButton);

    // Create widget
    setLayout(m_layout);

    // Create connections
    connect(m_parsePushButton, &QPushButton::clicked, this, &InputFunctionBox::parse);
}

Function InputFunctionBox::getFunction() const
{
    return m_function;
}

void InputFunctionBox::parse()
{
    m_function = m_parser.parse(m_functionLineEdit->text());

    emit parsed();
}
