#-------------------------------------------------
#
# Project created by QtCreator 2017-04-04T01:46:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1to50
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    game.cpp

HEADERS  += window.h \
    game.h

FORMS    += window.ui

CONFIG += mobility
MOBILITY = 

