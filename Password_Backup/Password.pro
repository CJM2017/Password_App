#-------------------------------------------------
#
# Project created by QtCreator 2016-04-26T17:00:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Password
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    page_1.cpp \
    password.cpp \
    page_2.cpp

HEADERS  += mainwindow.h \
    page_1.h \
    password.h \
    page_2.h

FORMS    += mainwindow.ui \
    page_1.ui \
    page_2.ui

DISTFILES += \
    LOCK.jpg

RESOURCES += \
    resources.qrc
