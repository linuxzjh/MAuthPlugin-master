QT += core
QT -= gui

TARGET = SendEvent
CONFIG += console
TEMPLATE = app

INCLUDEPATH += \
    $$PWD/../../CTK-master/Libs/Core \
    $$PWD/../../CTK-master/Libs/PluginFramework \
    $$PWD/../../auth_plugin/makePlugin

LIBS += -L$$PWD/../../auth_plugin/makePlugin/Libs -lCTKCore -lCTKPluginFramework

HEADERS += \
    publisher.h \
    subscriber.h

SOURCES += \
    publisher.cpp \
    subscriber.cpp \
    main.cpp
