#-------------------------------------------------
#
# Project created by QtCreator 2015-11-10T15:31:11
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Silent
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classical.cpp \
    echelle.cpp \
    qcustomplot.cpp \
    pclassical.cpp \
    threed.cpp \
    pthreed.cpp \
    frame3d.cpp \
    frameechelle.cpp \
    vphg.cpp \
    fibre.cpp \
    framecl.cpp \
    tsi.cpp \
    warning1.cpp \
    notes.cpp

HEADERS  += mainwindow.h \
    classical.h \
    echelle.h \
    qcustomplot.h \
    pclassical.h \
    threed.h \
    pthreed.h \
    frame3d.h \
    frameechelle.h \
    vphg.h \
    fibre.h \
    framecl.h \
    tsi.h \
    warning1.h \
    notes.h

FORMS    += mainwindow.ui \
    classical.ui \
    echelle.ui \
    pclassical.ui \
    threed.ui \
    pthreed.ui \
    frame3d.ui \
    frameechelle.ui \
    vphg.ui \
    fibre.ui \
    framecl.ui \
    tsi.ui \
    warning1.ui \
    notes.ui

RESOURCES += \
    silentresources.qrc
