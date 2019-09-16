#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T07:51:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DefeatDragonsGameFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameboard.cpp \
    instructions.cpp \
    quitwidget.cpp \
    winwidget.cpp \
    losewidget.cpp

HEADERS  += mainwindow.h \
    gameboard.h \
    instructions.h \
    quitwidget.h \
    winwidget.h \
    losewidget.h

FORMS    += mainwindow.ui
