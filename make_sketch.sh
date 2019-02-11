#!/bin/bash

set -e

VER=$(cat ./BASIC/version)
SKETCH=./sketch/terminal-basic-$VER
SRC_PATH=${SKETCH}/terminal-basic

SRC="	./libbasic/include/basic.h
	./libbasic/include/basic_config.h
	./libbasic/include/basic.hpp
	./BASIC/include/basic_common.hpp  \
	./BASIC/src/basic_common.cpp \
	./BASIC/include/config.hpp \
	./BASIC/include/config_arduino.hpp \
	./BASIC/include/basic_lexer.hpp  \
	./BASIC/src/basic_lexer.cpp  \
	./BASIC/include/version.h \
	./BASIC/include/basic_parser.hpp \
	./BASIC/src/basic_parser.cpp \
	./BASIC/include/basic_interpreter.hpp \
	./BASIC/src/basic_interpreter.cpp \
	./BASIC/src/basic_interpreter_matrix.cpp \
	./BASIC/include/basic_dataparser.hpp \
	./BASIC/src/basic_dataparser.cpp \
	./BASIC/include/basic_program.hpp \
	./BASIC/src/basic_program.cpp \
	./BASIC/include/basic_exteeprom.hpp \
	./BASIC/src/basic_exteeprom.cpp \
	./BASIC/include/basic_functionblock.hpp \
	./BASIC/include/basic_arduinoio.hpp \
	./BASIC/include/basic_math.hpp \
	./BASIC/src/basic_functionblock.cpp \
	./BASIC/src/basic_arduinoio.cpp \
	./BASIC/src/basic_math.cpp \
	./BASIC/include/basic_parser_value.hpp \
	./BASIC/src/basic_parser_value.cpp \
	./BASIC/include/basic_sdfs.hpp \
	./BASIC/include/basic_internalfuncs.hpp \
	./BASIC/src/basic_internalfuncs.cpp \
	./BASIC/include/basic_gfx.hpp \
	./BASIC/src/basic_gfx.cpp \
	./BASIC/src/basic_gfx_tvout.cpp \
	./BASIC/src/basic_gfx_utft.cpp \
	./BASIC/src/basic_gfx_serial.cpp \
	./BASIC/src/basic_sdfs.cpp \
	./BASIC/src/strings_en.hpp \
	./BASIC/src/strings_ru_cp866.hpp \
	../libarduinoext/include/ascii.hpp \
	../libarduinoext/include/vt100.hpp \
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
	../libarduinoext/src/liquidcrystalprint.cpp \
	../libarduinoext/src/seriallight.cpp"

COPY_FILES="README ChangeLog COPYING"

rm -rf $SKETCH
mkdir -p $SKETCH
mkdir -p $SRC_PATH
mkdir -p $SRC_PATH/sys

cp README.sketch ./sketch/README
cp ./BASIC/src/ucbasic_main.cpp "${SRC_PATH}/terminal-basic.ino"
cp ../libarduinoext/include/sys/cdefs.h "${SRC_PATH}/sys/"

for file in $SRC
do
	cp ${file} ${SRC_PATH}
done

for file in $COPY_FILES
do
	cp ${file} ${SKETCH}
done

cd ./sketch
tar -czvf ./terminal-basic-${VER}-arduino-sketch.tar.gz ./README ./terminal-basic-${VER} ../../tvoutex/TVoutEx ../../libsdcard/SDCard ../../libutft/UTFT ../../libps2uart/ps2uartKeyboard
