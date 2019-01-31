QT += core gui widgets datavisualization

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

include(parser/parser.pri)

SOURCES += \
        $$PWD/main.cpp \
        $$PWD/ui/mainwindow.cpp \
        $$PWD/utills/randomgenerator.cpp \
        $$PWD/ui/widgets/functiondrawer.cpp

HEADERS += \
        $$PWD/ui/mainwindow.hpp \
        $$PWD/utills/randomgenerator.hpp \
        $$PWD/ui/widgets/functiondrawer.hpp \
        $$PWD/algorithms/optimizationalgorithm.hpp

RESOURCES += \
    items.qrc
