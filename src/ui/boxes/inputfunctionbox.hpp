#ifndef INPUTFUNCTIONBOX_HPP
#define INPUTFUNCTIONBOX_HPP

#include <QWidget>

#include <parser/Functions/function.hpp>
#include <parser/Parser/mathparser.hpp>

class QFormLayout;
class QLabel;
class QLineEdit;

class InputFunctionBox : public QWidget
{
    Q_OBJECT

public:
    explicit InputFunctionBox(QWidget *parent = nullptr);

    Function getFunction();

private:
    QFormLayout *m_layout;
    QLineEdit *m_functionLineEdit;

    MathParser m_parser;

};

#endif // INPUTFUNCTIONBOX_HPP
