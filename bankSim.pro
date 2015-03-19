TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    simulation.cpp \
    streetsim.cpp \
    custsim.cpp

HEADERS += \
    simulation.h \
    streetsim.h \
    twList.h \
    twNode.h \
    custsim.h

