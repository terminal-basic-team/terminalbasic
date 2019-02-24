#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=avr-gcc
CCC=avr-g++
CXX=avr-g++
FC=gfortran
AS=avr-as

# Macros
CND_PLATFORM=Arduino-1.8.6-Linux
CND_DLIB_EXT=so
CND_CONF=Arduino_UNO
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/basic_arduinoio.o \
	${OBJECTDIR}/src/basic_common.o \
	${OBJECTDIR}/src/basic_dataparser.o \
	${OBJECTDIR}/src/basic_exteeprom.o \
	${OBJECTDIR}/src/basic_functionblock.o \
	${OBJECTDIR}/src/basic_gfx.o \
	${OBJECTDIR}/src/basic_gfx_serial.o \
	${OBJECTDIR}/src/basic_gfx_tvout.o \
	${OBJECTDIR}/src/basic_gfx_utft.o \
	${OBJECTDIR}/src/basic_internalfuncs.o \
	${OBJECTDIR}/src/basic_interpreter.o \
	${OBJECTDIR}/src/basic_interpreter_matrix.o \
	${OBJECTDIR}/src/basic_lexer.o \
	${OBJECTDIR}/src/basic_math.o \
	${OBJECTDIR}/src/basic_parser.o \
	${OBJECTDIR}/src/basic_parser_value.o \
	${OBJECTDIR}/src/basic_program.o \
	${OBJECTDIR}/src/basic_sdfs.o \
	${OBJECTDIR}/src/ucbasic_main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega328p -ffunction-sections -fdata-sections -flto -fno-rtti -mcall-prologues
CXXFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega328p -ffunction-sections -fdata-sections -flto -fno-rtti -mcall-prologues

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../libsdcard/libsdcard/dist/Arduino_UNO/Arduino-1.8.6-Linux/liblibsdcard.a ../../libarduinoext/dist/Arduino_uno/Arduino-1.8.6-Linux/liblibarduinoext.a ../../libarduino/dist/Arduino_UNO/libarduino.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/terminal-basic

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libsdcard/libsdcard/dist/Arduino_UNO/Arduino-1.8.6-Linux/liblibsdcard.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libarduinoext/dist/Arduino_uno/Arduino-1.8.6-Linux/liblibarduinoext.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libarduino/dist/Arduino_UNO/libarduino.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/terminal-basic ${OBJECTFILES} ${LDLIBSOPTIONS} -Wall -Wextra -Os -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p

${OBJECTDIR}/src/basic_arduinoio.o: src/basic_arduinoio.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_arduinoio.o src/basic_arduinoio.cpp

${OBJECTDIR}/src/basic_common.o: src/basic_common.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_common.o src/basic_common.cpp

${OBJECTDIR}/src/basic_dataparser.o: src/basic_dataparser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_dataparser.o src/basic_dataparser.cpp

${OBJECTDIR}/src/basic_exteeprom.o: src/basic_exteeprom.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_exteeprom.o src/basic_exteeprom.cpp

${OBJECTDIR}/src/basic_functionblock.o: src/basic_functionblock.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_functionblock.o src/basic_functionblock.cpp

${OBJECTDIR}/src/basic_gfx.o: src/basic_gfx.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx.o src/basic_gfx.cpp

${OBJECTDIR}/src/basic_gfx_serial.o: src/basic_gfx_serial.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_serial.o src/basic_gfx_serial.cpp

${OBJECTDIR}/src/basic_gfx_tvout.o: src/basic_gfx_tvout.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_tvout.o src/basic_gfx_tvout.cpp

${OBJECTDIR}/src/basic_gfx_utft.o: src/basic_gfx_utft.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_utft.o src/basic_gfx_utft.cpp

${OBJECTDIR}/src/basic_internalfuncs.o: src/basic_internalfuncs.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_internalfuncs.o src/basic_internalfuncs.cpp

${OBJECTDIR}/src/basic_interpreter.o: src/basic_interpreter.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter.o src/basic_interpreter.cpp

${OBJECTDIR}/src/basic_interpreter_matrix.o: src/basic_interpreter_matrix.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_matrix.o src/basic_interpreter_matrix.cpp

${OBJECTDIR}/src/basic_lexer.o: src/basic_lexer.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_lexer.o src/basic_lexer.cpp

${OBJECTDIR}/src/basic_math.o: src/basic_math.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_math.o src/basic_math.cpp

${OBJECTDIR}/src/basic_parser.o: src/basic_parser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser.o src/basic_parser.cpp

${OBJECTDIR}/src/basic_parser_value.o: src/basic_parser_value.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value.o src/basic_parser_value.cpp

${OBJECTDIR}/src/basic_program.o: src/basic_program.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_program.o src/basic_program.cpp

${OBJECTDIR}/src/basic_sdfs.o: src/basic_sdfs.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_sdfs.o src/basic_sdfs.cpp

${OBJECTDIR}/src/ucbasic_main.o: src/ucbasic_main.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/LiquidCrystal/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard/src -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ucbasic_main.o src/ucbasic_main.cpp

# Subprojects
.build-subprojects:
	cd ../../libsdcard/libsdcard && ${MAKE}  -f Makefile CONF=Arduino_UNO
	cd ../../libarduinoext && ${MAKE}  -f Makefile CONF=Arduino_uno
	cd ../../libarduino && ${MAKE}  -f Makefile CONF=Arduino_UNO
	cd ../libbasic/libbasic_nb && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../../libsdcard/libsdcard && ${MAKE}  -f Makefile CONF=Arduino_UNO clean
	cd ../../libarduinoext && ${MAKE}  -f Makefile CONF=Arduino_uno clean
	cd ../../libarduino && ${MAKE}  -f Makefile CONF=Arduino_UNO clean
	cd ../libbasic/libbasic_nb && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
