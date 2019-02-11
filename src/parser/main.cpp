#include <QDebug>

#include "parser.hpp"

int main(int argc, char **argv)
{
    Parser parser;
    Function function = parser.parse("x^2 + 1");

    for (int i = 0; i < 10; i++) {
        Vector v(1, v);
        qDebug() << i << function(v);
    }

    return 0;
}
