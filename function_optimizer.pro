#-------------------------------------------------
#
# Project created by QtCreator 2018-12-04T14:56:04
#
#-------------------------------------------------

QT       += core gui datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = function_optimizer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/ui/mainwindow.cpp \
    src/Parser/utils.cpp \
    src/Parser/Entities/position.cpp \
    src/Parser/Functions/function.cpp \
    src/Parser/Parser/emptytokenvisitor.cpp \
    src/Parser/Parser/mathparser.cpp \
    src/Parser/Parser/tables.cpp \
    src/Parser/Parser/tokenvisitor.cpp \
    src/Parser/Parser/ExpTree/values.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/ExpLeafes/numberleaf.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/ExpLeafes/variableleaf.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/FunctionNodes/lognode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/binaryoperationnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/divisionnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/minusnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/multynode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/plusnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/powernode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/absnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/cosnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/ctgnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/exponentnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/lnnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sinnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sqrtnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/tgnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/unaryminusnode.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/unaryoperationnode.cpp \
    src/Parser/Parser/Handlers/mathastcreator.cpp \
    src/Parser/Parser/Handlers/mathgrammarscanner.cpp \
    src/Parser/Parser/Handlers/mathrpnconverter.cpp \
    src/Parser/Parser/Handlers/mathtokenizer.cpp \
    src/Parser/Parser/Predicates/CharPredicates/charpredicate.cpp \
    src/Parser/Parser/Predicates/CharPredicates/commapr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/digitpr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/disjunctioncharpr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/dotpr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/lbracketpr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/letterpr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/operatorpr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/rbracketpr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/semicolonpr.cpp \
    src/Parser/Parser/Predicates/CharPredicates/underscorepr.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/binaryoptokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/compareprioritytokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/disjunctiontokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/emptytokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/funcseparatortokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/functionnametokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/lbrackettokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/numbertokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/rbrackettokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/tokencomparepredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/tokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/unaryoptokenpredicate.cpp \
    src/Parser/Parser/Predicates/TokenPredicates/variabletokenpredicate.cpp \
    src/Parser/Parser/TokenFactories/funcseparatorfactory.cpp \
    src/Parser/Parser/TokenFactories/identifierfactory.cpp \
    src/Parser/Parser/TokenFactories/lbracketfactory.cpp \
    src/Parser/Parser/TokenFactories/numberfactory.cpp \
    src/Parser/Parser/TokenFactories/operatorfactory.cpp \
    src/Parser/Parser/TokenFactories/rbracketfactory.cpp \
    src/Parser/Parser/TokenFactories/tokenfactory.cpp \
    src/Parser/Parser/Tokens/binaryoptoken.cpp \
    src/Parser/Parser/Tokens/funcseparatortoken.cpp \
    src/Parser/Parser/Tokens/functionnametoken.cpp \
    src/Parser/Parser/Tokens/lbrackettoken.cpp \
    src/Parser/Parser/Tokens/numbertoken.cpp \
    src/Parser/Parser/Tokens/rbrackettoken.cpp \
    src/Parser/Parser/Tokens/token.cpp \
    src/Parser/Parser/Tokens/unaryoptoken.cpp \
    src/Parser/Parser/Tokens/variabletoken.cpp \
    src/Parser/Entities/vector.cpp \
    src/Parser/Parser/ExpTree/ExpNodes/expnode.cpp \
    src/algorithms/geneticalgorithm.cpp \
    src/utills/randomgenerator.cpp \
    src/ui/functiondrawer.cpp \
    src/ui/widgets/vectorlistwidget.cpp

HEADERS += \
        src/ui/mainwindow.hpp \
    src/Parser/utils.hpp \
    src/Parser/Entities/position.hpp \
    src/Parser/Functions/function.hpp \
    src/Parser/Parser/emptytokenvisitor.hpp \
    src/Parser/Parser/mathparser.hpp \
    src/Parser/Parser/tables.hpp \
    src/Parser/Parser/tokenvisitor.hpp \
    src/Parser/Parser/ExpTree/values.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/ExpLeafes/numberleaf.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/ExpLeafes/variableleaf.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/FunctionNodes/lognode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/binaryoperationnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/divisionnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/minusnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/multynode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/plusnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/powernode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/absnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/cosnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/ctgnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/exponentnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/lnnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sinnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sqrtnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/tgnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/unaryminusnode.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/unaryoperationnode.hpp \
    src/Parser/Parser/Handlers/mathastcreator.hpp \
    src/Parser/Parser/Handlers/mathgrammarscanner.hpp \
    src/Parser/Parser/Handlers/mathrpnconverter.hpp \
    src/Parser/Parser/Handlers/mathtokenizer.hpp \
    src/Parser/Parser/Predicates/CharPredicates/charpredicate.hpp \
    src/Parser/Parser/Predicates/CharPredicates/commapr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/digitpr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/disjunctioncharpr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/dotpr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/lbracketpr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/letterpr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/operatorpr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/rbracketpr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/semicolonpr.hpp \
    src/Parser/Parser/Predicates/CharPredicates/underscorepr.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/binaryoptokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/compareprioritytokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/disjunctiontokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/emptytokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/funcseparatortokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/functionnametokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/lbrackettokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/numbertokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/rbrackettokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/tokencomparepredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/tokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/unaryoptokenpredicate.hpp \
    src/Parser/Parser/Predicates/TokenPredicates/variabletokenpredicate.hpp \
    src/Parser/Parser/TokenFactories/funcseparatorfactory.hpp \
    src/Parser/Parser/TokenFactories/identifierfactory.hpp \
    src/Parser/Parser/TokenFactories/lbracketfactory.hpp \
    src/Parser/Parser/TokenFactories/numberfactory.hpp \
    src/Parser/Parser/TokenFactories/operatorfactory.hpp \
    src/Parser/Parser/TokenFactories/rbracketfactory.hpp \
    src/Parser/Parser/TokenFactories/tokenfactory.hpp \
    src/Parser/Parser/Tokens/binaryoptoken.hpp \
    src/Parser/Parser/Tokens/funcseparatortoken.hpp \
    src/Parser/Parser/Tokens/functionnametoken.hpp \
    src/Parser/Parser/Tokens/lbrackettoken.hpp \
    src/Parser/Parser/Tokens/numbertoken.hpp \
    src/Parser/Parser/Tokens/rbrackettoken.hpp \
    src/Parser/Parser/Tokens/token.hpp \
    src/Parser/Parser/Tokens/unaryoptoken.hpp \
    src/Parser/Parser/Tokens/variabletoken.hpp \
    src/Parser/Entities/vector.hpp \
    src/Parser/Parser/ExpTree/ExpNodes/expnode.hpp \
    src/algorithms/optimizealgorithm.hpp \
    src/algorithms/geneticalgorithm.hpp \
    src/utills/randomgenerator.hpp \
    src/ui/functiondrawer.hpp \
    src/ui/widgets/vectorlistwidget.hpp

INCLUDEPATH += $$PWD/src

RESOURCES += \
    items.qrc
