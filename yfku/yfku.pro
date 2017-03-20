#-------------------------------------------------
#
# Project created by QtCreator 2017-01-05T14:46:25
#
#-------------------------------------------------

QT       += widgets

TARGET = yfku
TEMPLATE = lib

DEFINES += YFKU_LIBRARY

SOURCES += yfku.cpp

HEADERS += yfku.h\
        yfku_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR=..\MyDebug
