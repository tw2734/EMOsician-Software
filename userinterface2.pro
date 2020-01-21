#-------------------------------------------------
#
# Project created by QtCreator 2019-04-20T14:59:36
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = userinterface2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        mainwindow.cpp \
    standarddialog.cpp \
    professionaldialog.cpp \
    advancedvdialog.cpp \
    pcm_to_wav.cpp \
    ../accompany.cpp \
    ../chord.cpp \
    ../connect.cpp \
    ../Module2.cpp \
    ../Module4.cpp \
    ../split.cpp \
    ../testfile.cpp \
    ../track.cpp \
    ../track_to_midi.cpp

HEADERS += \
        mainwindow.h \
    standarddialog.h \
    professionaldialog.h \
    advancedvdialog.h \
    variable.h \
    pcm_to_wav.h \
    ../accompany.h \
    ../chord.h \
    ../musicinterpreter.h \
    ../split.h \
    ../testfile.h \
    ../track.h \
    ../trackcombine.h \
    ../trackdata.h \
    ../track_to_midi.h

FORMS += \
        mainwindow.ui \
    standarddialog.ui \
    professionaldialog.ui \
    advancedvdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    resource2.qrc \
    resource3.qrc

DISTFILES += \
    ../log.txt \
    ../canon.wav \
    ../canonbaocun.wav \
    ../log.txt
