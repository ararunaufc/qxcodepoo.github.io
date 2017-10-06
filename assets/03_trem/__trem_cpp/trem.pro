TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    locomotiva.cpp \
    passageiro.cpp \
    vagao.cpp \
    trem.cpp

HEADERS += \
    locomotiva.h \
    passageiro.h \
    vagao.h \
    trem.h

