QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    Hangman.cpp \
    scenes/Canvas/Canvas.cpp \
    scenes/Game/Game.cpp \
    scenes/GameFinish/GameFinish.cpp \
    scenes/Help/Help.cpp \
    scenes/Menu/Menu.cpp  \
    scenes/Scores/Scores.cpp

HEADERS += \
    Hangman.h \
    scenes/Canvas/Canvas.h \
    include/nlohmann/json.hpp \
    scenes/Game/Game.h \
    scenes/GameFinish/GameFinish.h \
    scenes/Help/Help.h \
    scenes/Menu/Menu.h  \
    scenes/Scores/Scores.h

FORMS += \
    Hangman.ui \
    scenes/Canvas/Canvas.ui \
    scenes/Game/Game.ui \
    scenes/GameFinish/GameFinish.ui \
    scenes/Help/Help.ui \
    scenes/Menu/Menu.ui \
    scenes/Scores/Scores.ui

TRANSLATIONS += \
    Hangman_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
