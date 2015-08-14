TEMPLATE = lib
CONFIG += staticlib
QT = core gui qml
TARGET = qjsonpath

SOURCES += \
    jsonpath.cpp \
    pluginloader.cpp \
    qjsonlistmodel.cpp \
    qjsonpath.cpp

HEADERS += \
    jsonpath.h \
    pluginloader.h \
    qjsonlistmodel.h \
    qjsonpath.h
