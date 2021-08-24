#运行程序需要的环境配置：
#1.Windows10系统
#2.安装access数据库
#3.配置系统DNS的access驱动
#4.使用MSVC2017编译器，即需要安装VS2017（其他的没有尝试过）
#5.UTF-8编码器，注意不是system

QT       += core gui
QT       += sql
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fire
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        accessdb.cpp \
        secondwin.cpp

HEADERS += \
        mainwindow.h \
        accessdb.h \
        secondwin.h

FORMS += \
        mainwindow.ui \
        secondwin.ui


RESOURCES += \
    logo.qrc
