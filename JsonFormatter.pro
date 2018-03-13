QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JsonFormatter
TEMPLATE = app
CONFIG += c++20

QMAKE_CXXFLAGS += -std=gnu++1z

SOURCES += \
        main.cpp \
        main_window.cpp

HEADERS += \
        main_window.hpp \
        utils/json.hpp
