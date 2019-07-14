#-------------------------------------------------
#
# Project created by QtCreator 2017-10-04T13:23:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zorkGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    bandage.cpp \
    fightwindow.cpp \
    grenade.cpp \
    humanoid.cpp \
    inventory.cpp \
    knife.cpp \
    lmg.cpp \
    loot.cpp \
    main.cpp \
    mainwindow.cpp \
    medkit.cpp \
    monster.cpp \
    pistol.cpp \
    player.cpp \
    rifle.cpp \
    roomlayout.cpp \
    shotgun.cpp \
    smg.cpp \
    sniper.cpp \
    zombie.cpp \
    Parser.cpp \
    basestats.cpp

HEADERS += \
    bandage.h \
    fightwindow.h \
    grenade.h \
    humanoid.h \
    inventory.h \
    knife.h \
    lmg.h \
    loot.h \
    mainwindow.h \
    medkit.h \
    monster.h \
    pistol.h \
    player.h \
    rifle.h \
    Room.h \
    roomlayout.h \
    shotgun.h \
    smg.h \
    sniper.h \
    zombie.h \
    Parser.h \
    basestats.h

FORMS += \
    mainwindow.ui \
    fightwindow.ui \
    fightwindow.ui \
    mainwindow.ui

SUBDIRS += \
    zorkGUI.pro

DISTFILES += \
    zorkGUI.pro.user

RESOURCES += \
    images.qrc
