#-------------------------------------------------
#
# Project created by QtCreator 2018-01-16T18:37:46
#
#-------------------------------------------------
QT -= gui
QT += core

TARGET = auth_plugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH += \
    $$PWD/../../CTK-master/Libs/Core \
    $$PWD/../../CTK-master/Libs/PluginFramework


LIBS += -L$$PWD/Libs -lCTKCore -lCTKPluginFramework

RESOURCES += auth_plugin_manifest.qrc

SOURCES += \
        auth_plugin.cpp \
    authpluginservice.cpp \
    authpluginactivator.cpp

HEADERS += \
        auth_plugin.h \
    authpluginservice.h \
    authpluginactivator.h
