#ifndef TABLES_HPP
#define TABLES_HPP

#include "ExpTree/ExpNodes/expnode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/unaryminusnode.hpp"
#include "ExpTree/ExpNodes/BinaryOperationsNodes/plusnode.hpp"
#include "ExpTree/ExpNodes/BinaryOperationsNodes/minusnode.hpp"
#include "ExpTree/ExpNodes/BinaryOperationsNodes/multynode.hpp"
#include "ExpTree/ExpNodes/BinaryOperationsNodes/divisionnode.hpp"
#include "ExpTree/ExpNodes/BinaryOperationsNodes/powernode.hpp"
#include "ExpTree/ExpNodes/BinaryOperationsNodes/FunctionNodes/lognode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sinnode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/cosnode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/tgnode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/ctgnode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sqrtnode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/lnnode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/exponentnode.hpp"
#include "ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/absnode.hpp"

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
