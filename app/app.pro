#-------------------------------------------------
#
# Project created by QtCreator 2019-02-21T16:50:37
#
#-------------------------------------------------

QT       += core gui
QT       += network gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
        mainwindow.cpp \
    sec.cpp \
    cards.cpp \
    plyrs.cpp \
    lucky.cpp \
    mserver.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    sec.h \
    cards.h \
    cards.h \
    plyrs.h \
    lucky.h \
    mserver.h \
    mythread.h

FORMS    += mainwindow.ui \
    sec.ui

RESOURCES += \
    img.qrc \
    r.qrc

DISTFILES +=
