TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=gnu11
QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp \
    ../../libbasic/src/basic.c \
    ../../libbasic/src/basic_lexer.c \
    ../../libbasic/src/basic_value.c \
    ../../libbasic/src/tools.c \
    ../../libbasic/src/basic_lexer_ru.c \
    ../../libbasic/src/basic_lexer_en.c \
    ../../libbasic/src/basic_lexer_fr.c \
    ../../libbasic/src/basic_parser.c \
    ../../BASIC/src/basic_lexer.cpp

INCLUDEPATH += ../../libbasic/include \
    ../../../libarduinoemulator/include \
    ../../../libarduinoext/include \
    ../../BASIC/include \

HEADERS += \
    ../../libbasic/include/tools.h \
    ../../libbasic/include/basic.h \
    ../../libbasic/include/HAL.h \
    ../../libbasic/include/config.h \
    ../../BASIC/include/basic_lexer.hpp \
    ../../BASIC/include/config.hpp \
    ../../BASIC/include/basic.hpp
