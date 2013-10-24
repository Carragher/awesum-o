#-------------------------------------------------
#
# Project created by QtCreator 2013-10-22T00:22:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = towwaTesting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    tile.cpp \
    world.cpp \
    entity.cpp \
    enemy.cpp

HEADERS  += mainwindow.h\
    tile.h \
    world.h \
    entity.h \
    enemy.h

FORMS    += mainwindow.ui

RESOURCES += \
    images/images.qrc

QMAKE_CXXFLAGS += -std=c++0x
