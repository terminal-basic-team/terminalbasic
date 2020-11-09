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
	./libbasic/include/basic_config.h
	./libbasic/include/HAL.h
	./libbasic/src/HAL.c
	./libbasic/include/HAL_config.h
	./libbasic/include/_tokens_en.h
	./libbasic/include/_tokens_fr.h
	./libbasic/include/_tokens_ru.h
	./libbasic/include/basic_value.h
	./libbasic/src/basic_value.c
	./libbasic/include/basic_lexer.h
	./libbasic/src/basic_lexer.c
	./libbasic/src/basic_lexer_en.c
	./libbasic/src/basic_lexer_fr.c
	./libbasic/src/basic_lexer_ru.c
	./libbasic/include/basic_parser.h
	./libbasic/src/basic_parser.c
	./libbasic/include/_tokens_en.h
	./libbasic/include/_tokens_fr.h
	./libbasic/include/_tokens_ru.h
	./BASIC/include/basic.hpp
	./BASIC/include/basic_lexer.hpp
	./BASIC/src/basic_lexerw.cpp
	./BASIC/include/basic_config.hpp
	./BASIC/include/config_linux.hpp
	./BASIC/include/version.h
	./BASIC/src/basic.cpp
	./BASIC/include/HAL_pc.h
	./BASIC/include/_HAL_pc.h
	./BASIC/src/HAL_pc.c
	./BASIC/src/HAL_posix.c
	./BASIC/src/HAL_mingw32.c
	./BASIC/include/HALProxyStream.hpp
	./BASIC/src/HALProxyStream.cpp
	./BASIC/include/basic_interpreter.hpp
	./BASIC/include/basic_program.hpp
	./BASIC/include/basic_parser.hpp
	./BASIC/src/basic_parserw.cpp
	./BASIC/include/basic_dataparser.hpp
	./BASIC/src/basic_dataparser.cpp
	./BASIC/src/basic_interpreterw.cpp
	./BASIC/src/basic_interpreter_matrix.cpp
	./BASIC/src/basic_program.cpp
	./BASIC/include/basic_exteeprom.hpp
	./BASIC/src/basic_exteeprom.cpp
	./BASIC/include/basic_functionblock.hpp
	./BASIC/include/basic_math.hpp
	./BASIC/src/basic_functionblock.cpp
	./BASIC/src/basic_math.cpp
	./BASIC/include/basic_parser_value.hpp
	./BASIC/include/basic_extmemfs.hpp
	./BASIC/include/basic_internalfuncs.hpp
	./BASIC/src/basic_internalfuncs.cpp
	./BASIC/include/basic_gfx.hpp
	./BASIC/src/basic_gfx.cpp
	./BASIC/src/tvoutprint.cpp
	./BASIC/include/tvoutprint.hpp
	./BASIC/src/basic_gfx_tvout.cpp
	./BASIC/src/basic_gfx_utft.cpp
	./BASIC/src/basic_gfx_serial.cpp
	./BASIC/src/basic_parser_value.cpp
	./BASIC/src/basic_extmemfs.cpp
	./BASIC/src/ucbasic_main.cpp
	./BASIC/src/strings_en.hpp
	./BASIC/src/strings_fr.hpp
	./BASIC/src/strings_ru.hpp
	../libarduinoext/include/vt100.hpp
	../libarduinoext/include/matrix.hpp
	../libarduinoext/include/types.hpp
	../libarduinoext/include/i2ceeprom.hpp
	../libarduinoext/include/arduino_logger.hpp
	../libarduinoext/include/arduinoext.hpp
	../libarduinoext/include/helper.hpp
	../libarduinoext/include/math.hpp
	../libarduinoext/include/bytearray.hpp
	../libarduinoext/src/bytearray.cpp
	../libarduinoext/src/vt100.cpp
	../libarduinoext/include/seriallight.hpp
	../libarduinoext/src/seriallight.cpp
	../libarduinoext/include/ascii.hpp"

COPY_FILES="ChangeLog COPYING configure.ac Makefile.am"

rm -rf $SKETCH
mkdir -p $SKETCH
mkdir -p $SRC_PATH

cp ./Makefile.am.terminal-basic "${SRC_PATH}/Makefile.am"
rsync -r ../libarduinoemulator/include/ ${SRC_PATH}
cp ../libarduinoemulator/src/Print.cpp ${SRC_PATH}
cp ../libarduinoemulator/src/Stream.cpp ${SRC_PATH}
cp ../libarduinoemulator/src/arduino.cpp ${SRC_PATH}

#cp ../libtvoutex/TVoutEx/src/*.cpp ${SRC_PATH}
#cp ../libtvoutex/TVoutEx/src/*.h ${SRC_PATH}
#cp ../libtvoutex/TVoutEx/src/*.hpp ${SRC_PATH}
#cp ../libtvoutex/netbenas/*.cpp ${SRC_PATH}
#mkdir ${SRC_PATH}/spec
#cp ../libtvoutex/TVoutEx/src/spec/* ${SRC_PATH}/spec
#mkdir ${SRC_PATH}/utility
#cp ../libtvoutex/TVoutEx/src/utility/*.h ${SRC_PATH}/utility/
#cp ../libtvoutex/TVoutEx/src/utility/*.hpp ${SRC_PATH}/utility/
#cp ../libtvoutex/TVoutEx/src/utility/*.cpp ${SRC_PATH}

for file in $SRC
do
	cp ${file} ${SRC_PATH}
done

for file in $COPY_FILES
do
	cp ${file} ${SKETCH}
done
cp README.md ${SKETCH}/README

cd $SKETCH
autoreconf
automake --add-missing
autoreconf
./configure
make dist

