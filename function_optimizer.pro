QT       += core gui widgets datavisualization

TARGET = function_optimizer
TEMPLATE = app

INCLUDEPATH += $$PWD/src

include(src/parser/parser.pri)

SOURCES += \
        src/main.cpp \
        src/ui/mainwindow.cpp \
        src/utills/randomgenerator.cpp \
        src/ui/widgets/functiondrawer.cpp

HEADERS += \
        src/ui/mainwindow.hpp \
        src/utills/randomgenerator.hpp \
        src/ui/widgets/functiondrawer.hpp \
        src/algorithms/optimizationalgorithm.hpp

RESOURCES += \
    items.qrc

#SUBDIRS += src/parser
