#-------------------------------------------------
#
# Project created by QtCreator 2013-10-22T00:22:19
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = towwaTesting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    tile.cpp \
    world.cpp \
    entity.cpp \
    enemy.cpp \
    highscore.cpp \
    command.cpp \
    enemygui.cpp \
    storage.cpp \
    bullet.cpp \
    bulletgui.cpp \
    awesumeclient.cpp \
    awesumserver.cpp \
    helpform.cpp

HEADERS  += mainwindow.h\
    tile.h \
    world.h \
    entity.h \
    enemy.h \
    highscore.h \
    command.h \
    enemygui.h \
    storage.h \
    bullet.h \
    bulletgui.h \
    awesumeclient.h \
    awesumserver.h \
    helpform.h

FORMS    += mainwindow.ui \
    awesumeclient.ui \
    awesumserver.ui \
    helpform.ui

RESOURCES += \
    images/images.qrc

QMAKE_CXXFLAGS += -std=c++0x
