#include "tables.hpp"

namespace Tables {

/* Priority tables */
QMap<QChar, int> binaryOpPriorityTable =
{
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3}
};
QMap<QChar, int> unaryOpPriorityTable =
{
    {'+', 4},
    {'-', 4}
};

/* Arguments number tables */
QMap<QString, int> functionArgNumberTable =
{
    {"sin"    , 1},
    {"cos"    , 1},
    {"tg"     , 1},
    {"ctg"    , 1},
    {"arcsin" , 1},
    {"arccos" , 1},
    {"arctg"  , 1},
    {"arcctg" , 1},
    {"ln"     , 1},
    {"exp"    , 1},
    {"sqrt"   , 1},
    {"abs"    , 1},
    {"sign"   , 1},
    {"log"    , 2}
};

/* Expression nodes tables */
QMap<QChar, BinaryOp> binaryOpNodesTable =
{
    {'+', [](ExpNode *op1, ExpNode *op2){return new PlusNode    (op1, op2);}},
    {'-', [](ExpNode *op1, ExpNode *op2){return new MinusNode   (op1, op2);}},
    {'*', [](ExpNode *op1, ExpNode *op2){return new MultyNode   (op1, op2);}},
    {'/', [](ExpNode *op1, ExpNode *op2){return new DivisionNode(op1, op2);}},
    {'^', [](ExpNode *op1, ExpNode *op2){return new PowerNode   (op1, op2);}}
};

QMap<QChar, UnaryOp> unaryOpNodesTable =
{
    {'+', [](ExpNode *op){return nullptr;               }},
    {'-', [](ExpNode *op){return new UnaryMinusNode(op);}}
};

QMap<QString, FuncOp> functionNodesTable =
{
    {"sin"  ,[](QVector<ExpNode*> args){return new SinNode     (args[0]);}         },
    {"cos"  ,[](QVector<ExpNode*> args){return new CosNode     (args[0]);}         },
    {"tg"   ,[](QVector<ExpNode*> args){return new TgNode      (args[0]);}         },
    {"ctg"  ,[](QVector<ExpNode*> args){return new CtgNode     (args[0]);}         },
    {"ln"   ,[](QVector<ExpNode*> args){return new LnNode      (args[0]);}         },
    {"exp"  ,[](QVector<ExpNode*> args){return new ExponentNode(args[0]);}         },
    {"sqrt" ,[](QVector<ExpNode*> args){return new SqrtNode    (args[0]);}         },
    {"log"  ,[](QVector<ExpNode*> args){return new LogNode     (args[0], args[1]);}}
};

} // Tables
