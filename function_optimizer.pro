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
    src/parser/utils.cpp \
    src/parser/Entities/position.cpp \
    src/parser/Functions/function.cpp \
    src/parser/Parser/emptytokenvisitor.cpp \
    src/parser/Parser/mathparser.cpp \
    src/parser/Parser/tables.cpp \
    src/parser/Parser/tokenvisitor.cpp \
    src/parser/Parser/ExpTree/values.cpp \
    src/parser/Parser/ExpTree/ExpNodes/ExpLeafes/numberleaf.cpp \
    src/parser/Parser/ExpTree/ExpNodes/ExpLeafes/variableleaf.cpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/FunctionNodes/lognode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/binaryoperationnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/divisionnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/minusnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/multynode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/plusnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/powernode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/absnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/cosnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/ctgnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/exponentnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/lnnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sinnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sqrtnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/tgnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/unaryminusnode.cpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/unaryoperationnode.cpp \
    src/parser/Parser/Handlers/mathastcreator.cpp \
    src/parser/Parser/Handlers/mathgrammarscanner.cpp \
    src/parser/Parser/Handlers/mathrpnconverter.cpp \
    src/parser/Parser/Handlers/mathtokenizer.cpp \
    src/parser/Parser/Predicates/CharPredicates/charpredicate.cpp \
    src/parser/Parser/Predicates/CharPredicates/commapr.cpp \
    src/parser/Parser/Predicates/CharPredicates/digitpr.cpp \
    src/parser/Parser/Predicates/CharPredicates/disjunctioncharpr.cpp \
    src/parser/Parser/Predicates/CharPredicates/dotpr.cpp \
    src/parser/Parser/Predicates/CharPredicates/lbracketpr.cpp \
    src/parser/Parser/Predicates/CharPredicates/letterpr.cpp \
    src/parser/Parser/Predicates/CharPredicates/operatorpr.cpp \
    src/parser/Parser/Predicates/CharPredicates/rbracketpr.cpp \
    src/parser/Parser/Predicates/CharPredicates/semicolonpr.cpp \
    src/parser/Parser/Predicates/CharPredicates/underscorepr.cpp \
    src/parser/Parser/Predicates/TokenPredicates/binaryoptokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/compareprioritytokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/disjunctiontokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/emptytokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/funcseparatortokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/functionnametokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/lbrackettokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/numbertokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/rbrackettokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/tokencomparepredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/tokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/unaryoptokenpredicate.cpp \
    src/parser/Parser/Predicates/TokenPredicates/variabletokenpredicate.cpp \
    src/parser/Parser/TokenFactories/funcseparatorfactory.cpp \
    src/parser/Parser/TokenFactories/identifierfactory.cpp \
    src/parser/Parser/TokenFactories/lbracketfactory.cpp \
    src/parser/Parser/TokenFactories/numberfactory.cpp \
    src/parser/Parser/TokenFactories/operatorfactory.cpp \
    src/parser/Parser/TokenFactories/rbracketfactory.cpp \
    src/parser/Parser/TokenFactories/tokenfactory.cpp \
    src/parser/Parser/Tokens/binaryoptoken.cpp \
    src/parser/Parser/Tokens/funcseparatortoken.cpp \
    src/parser/Parser/Tokens/functionnametoken.cpp \
    src/parser/Parser/Tokens/lbrackettoken.cpp \
    src/parser/Parser/Tokens/numbertoken.cpp \
    src/parser/Parser/Tokens/rbrackettoken.cpp \
    src/parser/Parser/Tokens/token.cpp \
    src/parser/Parser/Tokens/unaryoptoken.cpp \
    src/parser/Parser/Tokens/variabletoken.cpp \
    src/parser/Entities/vector.cpp \
    src/parser/Parser/ExpTree/ExpNodes/expnode.cpp \
    src/algorithms/geneticalgorithm.cpp \
    src/utills/randomgenerator.cpp \
    src/ui/functiondrawer.cpp \
    src/ui/widgets/vectorlistwidget.cpp \
    src/ui/algorithm_widgets/geneticalgorithmwidget.cpp \
    src/ui/algorithm_widgets/algorithmwidget.cpp \
    src/ui/widgets/intervalbox.cpp \
    src/ui/widgets/intervallistbox.cpp \
    src/ui/widgets/inputfunctionbox.cpp

HEADERS += \
        src/ui/mainwindow.hpp \
    src/parser/utils.hpp \
    src/parser/Entities/position.hpp \
    src/parser/Functions/function.hpp \
    src/parser/Parser/emptytokenvisitor.hpp \
    src/parser/Parser/mathparser.hpp \
    src/parser/Parser/tables.hpp \
    src/parser/Parser/tokenvisitor.hpp \
    src/parser/Parser/ExpTree/values.hpp \
    src/parser/Parser/ExpTree/ExpNodes/ExpLeafes/numberleaf.hpp \
    src/parser/Parser/ExpTree/ExpNodes/ExpLeafes/variableleaf.hpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/FunctionNodes/lognode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/binaryoperationnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/divisionnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/minusnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/multynode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/plusnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/BinaryOperationsNodes/powernode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/absnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/cosnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/ctgnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/exponentnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/lnnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sinnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/sqrtnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/FunctionNodes/tgnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/unaryminusnode.hpp \
    src/parser/Parser/ExpTree/ExpNodes/UnaryOperationsNodes/unaryoperationnode.hpp \
    src/parser/Parser/Handlers/mathastcreator.hpp \
    src/parser/Parser/Handlers/mathgrammarscanner.hpp \
    src/parser/Parser/Handlers/mathrpnconverter.hpp \
    src/parser/Parser/Handlers/mathtokenizer.hpp \
    src/parser/Parser/Predicates/CharPredicates/charpredicate.hpp \
    src/parser/Parser/Predicates/CharPredicates/commapr.hpp \
    src/parser/Parser/Predicates/CharPredicates/digitpr.hpp \
    src/parser/Parser/Predicates/CharPredicates/disjunctioncharpr.hpp \
    src/parser/Parser/Predicates/CharPredicates/dotpr.hpp \
    src/parser/Parser/Predicates/CharPredicates/lbracketpr.hpp \
    src/parser/Parser/Predicates/CharPredicates/letterpr.hpp \
    src/parser/Parser/Predicates/CharPredicates/operatorpr.hpp \
    src/parser/Parser/Predicates/CharPredicates/rbracketpr.hpp \
    src/parser/Parser/Predicates/CharPredicates/semicolonpr.hpp \
    src/parser/Parser/Predicates/CharPredicates/underscorepr.hpp \
    src/parser/Parser/Predicates/TokenPredicates/binaryoptokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/compareprioritytokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/disjunctiontokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/emptytokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/funcseparatortokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/functionnametokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/lbrackettokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/numbertokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/rbrackettokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/tokencomparepredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/tokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/unaryoptokenpredicate.hpp \
    src/parser/Parser/Predicates/TokenPredicates/variabletokenpredicate.hpp \
    src/parser/Parser/TokenFactories/funcseparatorfactory.hpp \
    src/parser/Parser/TokenFactories/identifierfactory.hpp \
    src/parser/Parser/TokenFactories/lbracketfactory.hpp \
    src/parser/Parser/TokenFactories/numberfactory.hpp \
    src/parser/Parser/TokenFactories/operatorfactory.hpp \
    src/parser/Parser/TokenFactories/rbracketfactory.hpp \
    src/parser/Parser/TokenFactories/tokenfactory.hpp \
    src/parser/Parser/Tokens/binaryoptoken.hpp \
    src/parser/Parser/Tokens/funcseparatortoken.hpp \
    src/parser/Parser/Tokens/functionnametoken.hpp \
    src/parser/Parser/Tokens/lbrackettoken.hpp \
    src/parser/Parser/Tokens/numbertoken.hpp \
    src/parser/Parser/Tokens/rbrackettoken.hpp \
    src/parser/Parser/Tokens/token.hpp \
    src/parser/Parser/Tokens/unaryoptoken.hpp \
    src/parser/Parser/Tokens/variabletoken.hpp \
    src/parser/Entities/vector.hpp \
    src/parser/Parser/ExpTree/ExpNodes/expnode.hpp \
    src/algorithms/optimizealgorithm.hpp \
    src/algorithms/geneticalgorithm.hpp \
    src/utills/randomgenerator.hpp \
    src/ui/functiondrawer.hpp \
    src/ui/widgets/vectorlistwidget.hpp \
    src/ui/algorithm_widgets/algorithmwidget.hpp \
    src/ui/algorithm_widgets/geneticalgorithmwidget.hpp \
    src/ui/widgets/intervalbox.hpp \
    src/ui/widgets/intervallistbox.hpp \
    src/ui/widgets/inputfunctionbox.hpp

INCLUDEPATH += $$PWD/src

RESOURCES += \
    items.qrc
