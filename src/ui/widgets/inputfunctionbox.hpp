#ifndef INPUTFUNCTIONBOX_HPP
#define INPUTFUNCTIONBOX_HPP

#include <QWidget>

#include <parser/Functions/function.hpp>
#include <parser/Parser/mathparser.hpp>

class QHBoxLayout;
class QLabel;
class QLineEdit;
class QPushButton;

class InputFunctionBox : public QWidget
{
    Q_OBJECT

public:
    explicit InputFunctionBox(QWidget *parent = nullptr);

private:
    QHBoxLayout *m_layout;
    QLineEdit *m_functionLineEdit;
    QPushButton *m_parsePushButton;

    MathParser m_parser;

private slots:
    void parse();

signals:
    void parsed(const Function &func);

};

#endif // INPUTFUNCTIONBOX_HPP
