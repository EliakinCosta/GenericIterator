QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = IteratorMegaPowerExample
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    aluno.cpp \
    iiterator.cpp \
    iteratorsuperpower.cpp

HEADERS += \
    aluno.h \
    iiterator.h \
    iteratorsuperpower.h
