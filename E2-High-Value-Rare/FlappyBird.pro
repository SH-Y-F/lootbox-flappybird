#-------------------------------------------------
#
# Project created by QtCreator 2014-03-11T16:19:41
#
#-------------------------------------------------

QT       += core gui
QT      += multimedia

VERSION = 1.1.1

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlappyBird
TEMPLATE = app
#        RC_ICONS = bird.ico
#	这句在windows下编译时解除注释，让exe文件带上图标

SOURCES += main.cpp\
    choujiang.cpp \
    forminstruction.cpp \
    formmenu.cpp \
        mainwindow.cpp \
    Module/bird/bird.cpp \
    Module/ground/ground.cpp \
    Module/pipe/pipe.cpp \
    Module/scoreboard/scoreboard.cpp \
    Module/fbnumLCD/fbnumlcd.cpp \
    Module/redyboard/redyboard.cpp \
    pingfen.cpp \
    shuoming.cpp

HEADERS  += mainwindow.h \
    Module/bird/bird.h \
    Module/ground/ground.h \
    Module/pipe/pipe.h \
    Module/scoreboard/scoreboard.h \
    Module/fbnumLCD/fbnumlcd.h \
    Module/redyboard/redyboard.h \
    choujiang.h \
    forminstruction.h \
    formmenu.h \
    pingfen.h \
    shuoming.h

FORMS    += \
    choujiang.ui \
    forminstruction.ui \
    formmenu.ui \
    pingfen.ui \
    shuoming.ui

RESOURCES += \
    flappy.qrc

DISTFILES += \
    Images/A82.png \
    Images/A83.png \
    Images/CJ1.png \
    Images/CJ10.png \
    Images/CJ11.png \
    Images/CJ12.png \
    Images/CJ13.png \
    Images/CJ14.png \
    Images/CJ15.png \
    Images/CJ16.png \
    Images/CJ17.png \
    Images/CJ18.png \
    Images/CJ19.png \
    Images/CJ2.png \
    Images/CJ20.png \
    Images/CJ21.png \
    Images/CJ22.png \
    Images/CJ23.png \
    Images/CJ24.png \
    Images/CJ25.png \
    Images/CJ26.png \
    Images/CJ27.png \
    Images/CJ28.png \
    Images/CJ29.png \
    Images/CJ3.png \
    Images/CJ30.png \
    Images/CJ31.png \
    Images/CJ32.png \
    Images/CJ33.png \
    Images/CJ34.png \
    Images/CJ35.png \
    Images/CJ36.png \
    Images/CJ37.png \
    Images/CJ38.png \
    Images/CJ39.png \
    Images/CJ4.png \
    Images/CJ40.png \
    Images/CJ41.png \
    Images/CJ42.png \
    Images/CJ43.png \
    Images/CJ44.png \
    Images/CJ45.png \
    Images/CJ46.png \
    Images/CJ47.png \
    Images/CJ48.png \
    Images/CJ49.png \
    Images/CJ5.png \
    Images/CJ50.png \
    Images/CJ6.png \
    Images/CJ7.png \
    Images/CJ8.png \
    Images/CJ9.png
