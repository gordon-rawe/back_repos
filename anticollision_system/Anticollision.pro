#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T21:48:15
#
#-------------------------------------------------

QT       += core gui declarative

TARGET = Anticollision
TEMPLATE = app

include(POSIX/qextserialport.pri)

SOURCES += main.cpp \
    mainwindow.cpp \
    modules/globalpositionmodule.cpp \
    modules/zigbeemodule.cpp \
    configurecontroller.cpp \
    mapModule/mywidget.cpp \
    mapModule/maplayer.cpp

HEADERS  += mainwindow.h \
    modules/globalpositionmodule.h \
    modules/zigbeemodule.h \
    configurecontroller.h \
    mapModule/mywidget.h \
    mapModule/maplayer.h

FORMS += \
    mapModule/mywidget.ui

INCLUDEPATH += ./mapModule/header \
    ./mapModule

OTHER_FILES += ./ui/view.qml

LIBS += /usr/local/lib/mitab/libmitab.so \
        /usr/local/lib/mitab/libmitab.so.1 \
        /usr/local/lib/mitab/libmitab.so.1.0.1
