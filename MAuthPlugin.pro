TEMPLATE = subdirs

SUBDIRS += $$PWD/makePlugin/auth_plugin.pro \
           $$PWD/app/app.pro \
           $$PWD/eventProcess/eventProcess.pro

CONFIG += ordered
