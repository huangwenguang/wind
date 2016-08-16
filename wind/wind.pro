
QT += core
QT -= gui
QT       += sql
QT       += network

CONFIG += c++11
//DEFINES += QT_NO_DEBUG_OUTPUT
TARGET = wind
CONFIG += console
CONFIG -= app_bundle
PRECOMPILED_HEADER =
TEMPLATE = app
PRECOMPILED_HEADER =
SOURCES += main.cpp \
    qRedis.cpp \
    qReader.cpp \
    qReadisExample.cpp \
    qUntil.cpp \
    qJsonParsing.cpp \
    qJsonObject.cpp \
    qDbManager.cpp \
    qRedisConfig.cpp \
    qNetWork.cpp \
    qReachability.cpp \
    qGlobals.cpp

HEADERS += \
    qRedis.h \
    qReader.h \
    qReadisExample.h \
    qUntil.h \
    qJsonParsing.h \
    qJsonObject.h \
    qConfig.h \
    qDbManager.h \
    qRedisConfig.h \
    qNetWork.h \
    qReachability.h \
    qGlobals.h

