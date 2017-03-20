#-------------------------------------------------
#
# Project created by QtCreator 2017-01-01T16:10:32
#
#-------------------------------------------------

QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YF
TEMPLATE = app
DESTDIR =..\MyDebug
SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    userdata.cpp \
    selectlayer.cpp \
    yfmysql.cpp \
    getdatathread.cpp \
    getspatialdata.cpp \
    qlinestringf.cpp \
#    sortandjsonconvert.cpp \
    yflayer.cpp \
    yfprojection.cpp \
    sortandjsonconvert.cpp \
    newlayer.cpp \
    getlayerrect.cpp \
    yfinsertdata.cpp


HEADERS  += mainwindow.h \
    logindlg.h \
    userdata.h \
    selectlayer.h \
    yfmysql.h \
    getdatathread.h \
    getspatialdata.h \
    qlinestringf.h \
#    sortandjsonconvert.h \
    yflayer.h \
    yfprojection.h \
    sortandjsonconvert.h \
    newlayer.h \
    getlayerrect.h \
    yfinsertdata.h


FORMS    += mainwindow.ui \
    logindlg.ui \
    selectlayer.ui \
    newlayer.ui






unix|win32: LIBS += -L$$PWD/../MyDebug/ -lyfku

INCLUDEPATH += $$PWD/../MyDebug
DEPENDPATH += $$PWD/../MyDebug
