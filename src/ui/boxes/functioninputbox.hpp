#ifndef FUNCTIONINPUTBOX_HPP
#define FUNCTIONINPUTBOX_HPP

#include <QComboBox>

#include <parser/parser.hpp>
#include <parser/function.hpp>

class FunctionInputBox : public QComboBox
{
    Q_OBJECT

public:
    explicit FunctionInputBox(QWidget *parent = nullptr);

    QString getExpression() const;
    void setExpression(const QString &expression);

    void addExpression(const QString &expression);
    Function parseExpression();

private:
    Parser m_parser;

};

#endif // FUNCTIONINPUTBOX_HPP
