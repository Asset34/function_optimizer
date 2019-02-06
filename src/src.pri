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
        $$PWD/ui/boxes/functioninputbox.cpp \
        $$PWD/ui/widgets/optimizationalgorithmwidget.cpp \
        $$PWD/ui/widgets/optimizationresultwidget.cpp \
        $$PWD/ui/widgets/functionoptimizerwidget.cpp \
        $$PWD/algorithms/genetic_algorithm/geneticalgorithm.cpp \
        $$PWD/algorithms/genetic_algorithm/chromosome.cpp \
        $$PWD/algorithms/genetic_algorithm/population.cpp \
        $$PWD/algorithms/genetic_algorithm/fitnessfunction.cpp

HEADERS += \
        $$PWD/ui/mainwindow.hpp \
        $$PWD/utills/randomgenerator.hpp \
        $$PWD/ui/widgets/functiondrawer.hpp \
        $$PWD/ui/boxes/functioninputbox.hpp \
        $$PWD/ui/widgets/optimizationalgorithmwidget.hpp \
        $$PWD/ui/widgets/optimizationresultwidget.hpp \
        $$PWD/ui/widgets/functionoptimizerwidget.hpp \
        $$PWD/algorithms/optimizationalgorithm.hpp \
        $$PWD/algorithms/genetic_algorithm/geneticalgorithm.hpp \
        $$PWD/algorithms/genetic_algorithm/chromosome.hpp \
        $$PWD/algorithms/genetic_algorithm/population.hpp \
        $$PWD/algorithms/genetic_algorithm/fitnessfunction.hpp
