#!/bin/bash

VER=$(cat ./BASIC/version)
SKETCH=./sketch/terminal-basic

SRC="./BASIC/include/basic.hpp ./BASIC/include/basic_lexer.hpp ./BASIC/src/basic_lexer.cpp \
./BASIC/include/config_arduino.hpp ./BASIC/include/version.h \
./BASIC/include/basic_parser.hpp ./BASIC/include/basic_interpreter.hpp ./BASIC/include/basic_program.hpp \
./BASIC/src/basic_parser.cpp ./BASIC/src/basic_interpreter.cpp ./BASIC/src/basic_interpreter_program.cpp \
./BASIC/include/basic_functionblock.hpp ./BASIC/include/basic_arduinoio.hpp ./BASIC/include/basic_math.hpp \
./BASIC/src/basic_functionblock.cpp ./BASIC/src/basic_arduinoio.cpp ./BASIC/src/basic_math.cpp \
./BASIC/include/basic_parser_value.hpp ./BASIC/include/basic_sdfs.hpp \
./BASIC/include/basic_internalfuncs.hpp ./BASIC/src/basic_internalfuncs.cpp \
./BASIC/src/basic_parser_value.cpp ./BASIC/src/basic_sdfs.cpp \
../libarduinoext/include/arduino_logger.hpp ../libarduinoext/include/cps.hpp ../libarduinoext/include/helper.hpp \
../libarduinoext/include/math.hpp ../libarduinoext/include/bytearray.hpp ../libarduinoext/src/bytearray.cpp \
../libarduinoext/include/ascii.hpp README"

rm -rf $SKETCH
mkdir -p $SKETCH

cp ./BASIC/src/ucbasic_main.cpp "${SKETCH}/terminal-basic.ino"
for file in $SRC
do
	cp ${file} ${SKETCH}
done

cd ./sketch
tar -czvf ./terminal-basic-${VER}-src.tar.gz ./terminal-basic
