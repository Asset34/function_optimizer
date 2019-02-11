#ifndef TABLES_HPP
#define TABLES_HPP

#include "ExpTree/ExpNodes/expnode.hpp"

#include <functional>

#include <QMap>
#include <QString>
#include <QVector>

namespace Tables {

typedef std::function<ExpNode*(ExpNode*, ExpNode*)> BinaryOp;
typedef std::function<ExpNode*(ExpNode*)          > UnaryOp;
typedef std::function<ExpNode*(QVector<ExpNode*>) > FuncOp;

/* Priority tables */
extern QMap<QChar, int> binaryOpPriorityTable;
extern QMap<QChar, int> unaryOpPriorityTable;

/* Arguments number tables */
extern QMap<QString, int> functionArgNumberTable;

/* Expression nodes tables */
extern QMap<QChar  , BinaryOp> binaryOpNodesTable;
extern QMap<QChar  , UnaryOp > unaryOpNodesTable;
extern QMap<QString, FuncOp  > functionNodesTable;
} // Tables

#endif // TABLES_HPP
