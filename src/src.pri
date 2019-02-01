QT += core gui widgets datavisualization

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

include(parser/parser.pri)
include(parameterized_algorithm_qt/parameterized_algorithm_qt.pri)

SOURCES += \
        $$PWD/main.cpp \
        $$PWD/ui/mainwindow.cpp \
        $$PWD/utills/randomgenerator.cpp \
        $$PWD/ui/widgets/functiondrawer.cpp \
        $$PWD/ui/boxes/functioninputbox.cpp

HEADERS += \
        $$PWD/ui/mainwindow.hpp \
        $$PWD/utills/randomgenerator.hpp \
        $$PWD/ui/widgets/functiondrawer.hpp \
        $$PWD/algorithms/optimizationalgorithm.hpp \
        $$PWD/ui/boxes/functioninputbox.hpp
