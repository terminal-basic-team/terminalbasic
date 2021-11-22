#!/bin/bash

set -e

VER=$(cat ./BASIC/version)
SKETCH=./sketch/terminal-basic-$VER
SRC_PATH=${SKETCH}/terminal-basic

SRC="	./libbasic/include/basic.h \
	./libbasic/include/basic_lexer.h \
	./libbasic/include/basic_parser.h \
	./libbasic/include/basic_value.h \
	./libbasic/include/basic_config.h \
	./libbasic/include/_basic_config.h \
	./libbasic/include/HAL.h \
	./libbasic/include/HAL_config.h \
	./libbasic/include/tools.h \
	./libbasic/include/_tokens_en.h \
	./libbasic/include/_tokens_fr.h \
	./libbasic/include/_tokens_ru.h \
	./libbasic/src/basic.c \
	./libbasic/src/HAL.c \
	./libbasic/src/tools.c \
	./libbasic/src/basic_lexer_en.c \
	./libbasic/src/basic_lexer_fr.c \
	./libbasic/src/basic_lexer_ru.c \
	./libbasic/src/basic_value.c \
	./libbasic/src/basic_lexer.c \
	./libbasic/src/basic_parser.c \
	./BASIC/include/HALProxyStream.hpp \
	./BASIC/include/basic.hpp \
	./BASIC/include/basic_arduinoio.hpp \
	./BASIC/include/basic_dataparser.hpp \
	./BASIC/include/basic_interpreter.hpp \
	./BASIC/include/basic_lexer.hpp  \
	./BASIC/include/basic_parser.hpp \
	./BASIC/include/basic_program.hpp \
	./BASIC/include/basic_config.hpp \
	./BASIC/include/config_arduino.hpp \
	./BASIC/include/HAL_arduino.h \
	./BASIC/src/HALProxyStream.cpp \
	./BASIC/src/basic_lexerw.cpp  \
	./BASIC/include/version.h \
	./BASIC/src/basic_parserw.cpp \
	./BASIC/src/basic_interpreterw.cpp \
	./BASIC/src/basic_interpreter_matrix.cpp \
	./BASIC/src/basic_dataparser.cpp \
	./BASIC/src/basic_program.cpp \
	./BASIC/include/basic_exteeprom.hpp \
	./BASIC/src/basic_exteeprom.cpp \
	./BASIC/include/basic_functionblock.hpp \
	./BASIC/include/basic_math.hpp \
	./BASIC/src/basic_functionblock.cpp \
	./BASIC/src/basic_arduinoio.cpp \
	./BASIC/src/basic_math.cpp \
	./BASIC/include/basic_parser_value.hpp \
	./BASIC/src/basic_parser_value.cpp \
	./BASIC/include/basic_extmemfs.hpp \
	./BASIC/src/basic_extmemfs.cpp \
	./BASIC/include/basic_internalfuncs.hpp \
	./BASIC/src/basic_internalfuncs.cpp \
	./BASIC/include/basic_gfx.hpp \
	./BASIC/src/tvoutprint.cpp \
	./BASIC/include/tvoutprint.hpp \
	./BASIC/src/HAL_arduino.cpp \
	./BASIC/include/HAL_avr8.h \
	./BASIC/src/HAL_avr8.cpp \
	./BASIC/src/HAL_esp8266.cpp \
	./BASIC/include/HAL_esp32.h \
	./BASIC/src/HAL_esp32.cpp \
	./BASIC/src/HAL_esp32_odroidgo.cpp \
	./BASIC/src/HAL_sam.cpp \
	./BASIC/src/basic_gfx.cpp \
	./BASIC/src/basic_gfx_tvout.cpp \
	./BASIC/src/basic_gfx_utft.cpp \
	./BASIC/src/basic_gfx_serial.cpp \
	./BASIC/src/strings_en.hpp \
	./BASIC/src/strings_fr.hpp \
	./BASIC/src/strings_ru.hpp \
	../libarduinoext/include/ascii.hpp \
	../libarduinoext/include/vt100.hpp \
	../libarduinoext/include/buffered_terminal.hpp \
	../libarduinoext/include/gfxterm.hpp \
	../libarduinoext/include/liquidcrystalprint.hpp \
	../libarduinoext/include/seriallight.hpp \
	../libarduinoext/include/matrix.hpp \
	../libarduinoext/include/types.hpp \
	../libarduinoext/include/i2ceeprom.hpp \
	../libarduinoext/include/arduino_logger.hpp \
	../libarduinoext/include/arduinoext.hpp \
	../libarduinoext/include/helper.hpp \
	../libarduinoext/include/math.hpp \
	../libarduinoext/include/bytearray.hpp \
	../libarduinoext/src/bytearray.cpp \
	../libarduinoext/src/vt100.cpp \
	../libarduinoext/src/buffered_terminal.cpp \
	../libarduinoext/src/liquidcrystalprint.cpp \
	../libarduinoext/src/seriallight.cpp"

COPY_FILES="README.md ChangeLog COPYING"

rm -rf $SKETCH
mkdir -p $SKETCH
mkdir -p $SRC_PATH
mkdir -p $SRC_PATH/sys
mkdir -p $SRC_PATH/avr

cp README.sketch ./sketch/README
cp ./BASIC/src/ucbasic_main.cpp "${SRC_PATH}/terminal-basic.ino"
cp ../libarduinoext/include/sys/cdefs.h "${SRC_PATH}/sys/"
cp ./pgmspace.h "${SRC_PATH}/avr/"

for file in $SRC
do
	cp ${file} ${SRC_PATH}
done

for file in $COPY_FILES
do
	cp ${file} ${SKETCH}
done

cd ./sketch
tar -czvf ./terminal-basic-${VER}-arduino-sketch.tar.gz ./README ./terminal-basic-${VER} ../../libtvoutex/TVoutEx ../../libsdcard/SDCard ../../libutft/UTFT ../../libps2uart/ps2uartKeyboard ../../libps2kbddup/ps2kbd
