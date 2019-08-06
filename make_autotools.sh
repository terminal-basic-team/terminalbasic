#!/bin/bash

#set -e
set -x

VER=$(cat ./BASIC/version)
SKETCH=./autotools/terminalbasic-$VER
SRC_PATH=${SKETCH}/terminalbasic

rm -rf $SRC_PATH

SRC="	./libbasic/include/basic.h
	./libbasic/src/basic.c
	./libbasic/include/tools.h
	./libbasic/src/tools.c
	./libbasic/include/config.h
	./libbasic/include/_tokens_en.h
	./libbasic/include/_tokens_fr.h
	./libbasic/include/_tokens_ru.h
	./libbasic/include/basic_value.h \
	./libbasic/src/basic_value.c \
	./libbasic/include/basic_lexer.h \
	./libbasic/src/basic_lexer.c \
	./libbasic/src/basic_lexer_en.c \
	./libbasic/src/basic_lexer_fr.c \
	./libbasic/src/basic_lexer_ru.c \
	./libbasic/include/_tokens_en.h \
	./libbasic/include/_tokens_fr.h \
	./libbasic/include/_tokens_ru.h \
	./BASIC/include/basic.hpp  \
	./BASIC/src/basic.cpp \
	./BASIC/include/basic_lexer.hpp  \
	./BASIC/src/basic_lexer.cpp  \
	./BASIC/include/config.hpp \
	./BASIC/include/version.h \
	./BASIC/src/basic.cpp \
	./BASIC/include/basic_interpreter.hpp \
	./BASIC/include/basic_program.hpp \
	./BASIC/include/basic_parser.hpp \
	./BASIC/src/basic_parser.cpp \
	./BASIC/include/basic_dataparser.hpp \
	./BASIC/src/basic_dataparser.cpp \
	./BASIC/src/basic_interpreter.cpp \
	./BASIC/src/basic_interpreter_matrix.cpp \
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
	./BASIC/include/basic_sdfs.hpp \
	./BASIC/include/basic_internalfuncs.hpp \
	./BASIC/src/basic_internalfuncs.cpp \
	./BASIC/include/basic_gfx.hpp \
	./BASIC/src/basic_gfx.cpp \
	./BASIC/src/tvoutprint.cpp \
	./BASIC/include/tvoutprint.hpp \
	./BASIC/src/basic_gfx_tvout.cpp \
	./BASIC/src/basic_gfx_utft.cpp \
	./BASIC/src/basic_gfx_serial.cpp \
	./BASIC/src/basic_parser_value.cpp \
	./BASIC/src/basic_sdfs.cpp \
	./BASIC/src/ucbasic_main.cpp \
	./BASIC/src/strings_en.hpp \
	./BASIC/src/strings_fr.hpp \
	./BASIC/src/strings_ru.hpp \
	../libarduinoext/include/vt100.hpp \
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
	../libarduinoext/include/seriallight.hpp \
	../libarduinoext/src/seriallight.cpp \
	../libarduinoext/include/ascii.hpp"

COPY_FILES="README README.pc ChangeLog COPYING configure.ac Makefile.am \
	BASIC/include/config.hpp BASIC/include/config_linux.hpp"

rm -rf $SKETCH
mkdir -p $SKETCH
mkdir -p $SRC_PATH

cp ./Makefile.am.terminal-basic "${SRC_PATH}/Makefile.am"
rsync -r ../libarduinoemulator/include/ ${SRC_PATH}
rsync -r ../libarduinoemulator/src/ ${SRC_PATH}

cp ../tvoutex/TVoutEx/src/*.cpp ${SRC_PATH}
cp ../tvoutex/TVoutEx/src/*.h ${SRC_PATH}
cp ../tvoutex/TVoutEx/src/*.hpp ${SRC_PATH}
cp ../tvoutex/livbtvoutex/*.cpp ${SRC_PATH}
mkdir ${SRC_PATH}/spec
cp ../tvoutex/TVoutEx/src/spec/* ${SRC_PATH}/spec
mkdir ${SRC_PATH}/utility
cp ../tvoutex/TVoutEx/src/utility/*.h ${SRC_PATH}/utility/
cp ../tvoutex/TVoutEx/src/utility/*.hpp ${SRC_PATH}/utility/
cp ../tvoutex/TVoutEx/src/utility/*.cpp ${SRC_PATH}

for file in $SRC
do
	cp ${file} ${SRC_PATH}
done

for file in $COPY_FILES
do
	cp ${file} ${SKETCH}
done

cd $SKETCH
autoreconf
automake --add-missing
autoreconf
./configure
make dist

