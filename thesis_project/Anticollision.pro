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
    modules/serialhelper.cpp \
    modules/gpsmodule.cpp \
    modules/wirelessmodule.cpp \
    modules/safemodel.cpp \
    modules/speedmodule.cpp

HEADERS  += mainwindow.h \
    modules/serialhelper.h \
    frontEnd/mainwindow.h \
    modules/gpsmodule.h \
    modules/wirelessmodule.h \
    modules/safemodel.h \
    modules/speedmodule.h

OTHER_FILES += \
    frontEnd/radar/main.qml \
    frontEnd/radar/radar/Radar.qml
