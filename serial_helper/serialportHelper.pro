#-------------------------------------------------
#
# Project created by QtCreator 2011-11-06T21:37:41
#
#-------------------------------------------------

QT       += core gui

TARGET = serialHelper
TEMPLATE = app

include(SerialModule/qextserialport.pri)

SOURCES += main.cpp\
        dialog.cpp\
        hled.cpp

HEADERS  += dialog.h \
            hled.h

FORMS    += dialog.ui
