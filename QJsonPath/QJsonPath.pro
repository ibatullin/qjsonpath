TEMPLATE = lib
CONFIG += staticlib
QT = core gui qml
TARGET = qjsonpath

SOURCES += \
    JsonPath.cpp \
    PluginLoader.cpp \
    QJsonListModel.cpp \
    QJsonPath.cpp

HEADERS += \
    JsonPath.h \
    PluginLoader.h \
    QJsonListModel.h \
    QJsonPath.h
