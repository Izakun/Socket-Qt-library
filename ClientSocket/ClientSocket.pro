QT       += core
QT       += network
QT       -= gui

TARGET = ClientSocket
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    client.cpp

HEADERS += \
    client.h
