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
CND_PLATFORM=Arduino-Linux
CND_DLIB_EXT=so
CND_CONF=Arduino_mega2560
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/basic.o \
	${OBJECTDIR}/src/basic_arduinoio.o \
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

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/TableTest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega2560 -ffunction-sections -fdata-sections -flto -fno-rtti -mcall-prologues
CXXFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega2560 -ffunction-sections -fdata-sections -flto -fno-rtti -mcall-prologues

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../libutft/dist/Arduino_mega2560/Arduino-Linux/liblibutft.a ../../tvoutex/livbtvoutex/dist/Arduino_MEGA2560/Arduino-Linux/liblivbtvoutex.a ../../libarduinoext/dist/Arduino_mega2560/Arduino-1.8.6-Linux/liblibarduinoext.a ../../libsdcard/libsdcard/dist/Arduino_MEGA2560/Arduino-1.8.6-Linux/liblibsdcard.a ../../libarduino/dist/Mega_2560/libarduino.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/terminal-basic

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libutft/dist/Arduino_mega2560/Arduino-Linux/liblibutft.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../tvoutex/livbtvoutex/dist/Arduino_MEGA2560/Arduino-Linux/liblivbtvoutex.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libarduinoext/dist/Arduino_mega2560/Arduino-1.8.6-Linux/liblibarduinoext.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libsdcard/libsdcard/dist/Arduino_MEGA2560/Arduino-1.8.6-Linux/liblibsdcard.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libarduino/dist/Mega_2560/libarduino.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/terminal-basic ${OBJECTFILES} ${LDLIBSOPTIONS} -Os -Wall -Wextra -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega2560

${OBJECTDIR}/src/basic.o: src/basic.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic.o src/basic.cpp

${OBJECTDIR}/src/basic_arduinoio.o: src/basic_arduinoio.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_arduinoio.o src/basic_arduinoio.cpp

${OBJECTDIR}/src/basic_dataparser.o: src/basic_dataparser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_dataparser.o src/basic_dataparser.cpp

${OBJECTDIR}/src/basic_exteeprom.o: src/basic_exteeprom.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_exteeprom.o src/basic_exteeprom.cpp

${OBJECTDIR}/src/basic_functionblock.o: src/basic_functionblock.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_functionblock.o src/basic_functionblock.cpp

${OBJECTDIR}/src/basic_gfx.o: src/basic_gfx.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx.o src/basic_gfx.cpp

${OBJECTDIR}/src/basic_gfx_serial.o: src/basic_gfx_serial.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_serial.o src/basic_gfx_serial.cpp

${OBJECTDIR}/src/basic_gfx_tvout.o: src/basic_gfx_tvout.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_tvout.o src/basic_gfx_tvout.cpp

${OBJECTDIR}/src/basic_gfx_utft.o: src/basic_gfx_utft.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_utft.o src/basic_gfx_utft.cpp

${OBJECTDIR}/src/basic_internalfuncs.o: src/basic_internalfuncs.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_internalfuncs.o src/basic_internalfuncs.cpp

${OBJECTDIR}/src/basic_interpreter.o: src/basic_interpreter.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter.o src/basic_interpreter.cpp

${OBJECTDIR}/src/basic_interpreter_matrix.o: src/basic_interpreter_matrix.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_matrix.o src/basic_interpreter_matrix.cpp

${OBJECTDIR}/src/basic_lexer.o: src/basic_lexer.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_lexer.o src/basic_lexer.cpp

${OBJECTDIR}/src/basic_math.o: src/basic_math.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_math.o src/basic_math.cpp

${OBJECTDIR}/src/basic_parser.o: src/basic_parser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser.o src/basic_parser.cpp

${OBJECTDIR}/src/basic_parser_value.o: src/basic_parser_value.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value.o src/basic_parser_value.cpp

${OBJECTDIR}/src/basic_program.o: src/basic_program.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_program.o src/basic_program.cpp

${OBJECTDIR}/src/basic_sdfs.o: src/basic_sdfs.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_sdfs.o src/basic_sdfs.cpp

${OBJECTDIR}/src/ucbasic_main.o: src/ucbasic_main.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ucbasic_main.o src/ucbasic_main.cpp

# Subprojects
.build-subprojects:
	cd ../../libutft && ${MAKE}  -f Makefile CONF=Arduino_mega2560
	cd ../../tvoutex/livbtvoutex && ${MAKE}  -f Makefile CONF=Arduino_MEGA2560
	cd ../../libarduinoext && ${MAKE}  -f Makefile CONF=Arduino_mega2560
	cd ../../libsdcard/libsdcard && ${MAKE}  -f Makefile CONF=Arduino_MEGA2560
	cd ../../libarduino && ${MAKE}  -f Makefile CONF=Mega_2560

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/TableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/TableTest.o: tests/TableTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -I. -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TableTest.o tests/TableTest.cpp


${OBJECTDIR}/src/basic_nomain.o: ${OBJECTDIR}/src/basic.o src/basic.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_nomain.o src/basic.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic.o ${OBJECTDIR}/src/basic_nomain.o;\
	fi

${OBJECTDIR}/src/basic_arduinoio_nomain.o: ${OBJECTDIR}/src/basic_arduinoio.o src/basic_arduinoio.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_arduinoio.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_arduinoio_nomain.o src/basic_arduinoio.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_arduinoio.o ${OBJECTDIR}/src/basic_arduinoio_nomain.o;\
	fi

${OBJECTDIR}/src/basic_dataparser_nomain.o: ${OBJECTDIR}/src/basic_dataparser.o src/basic_dataparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_dataparser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_dataparser_nomain.o src/basic_dataparser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_dataparser.o ${OBJECTDIR}/src/basic_dataparser_nomain.o;\
	fi

${OBJECTDIR}/src/basic_exteeprom_nomain.o: ${OBJECTDIR}/src/basic_exteeprom.o src/basic_exteeprom.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_exteeprom.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_exteeprom_nomain.o src/basic_exteeprom.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_exteeprom.o ${OBJECTDIR}/src/basic_exteeprom_nomain.o;\
	fi

${OBJECTDIR}/src/basic_functionblock_nomain.o: ${OBJECTDIR}/src/basic_functionblock.o src/basic_functionblock.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_functionblock.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_functionblock_nomain.o src/basic_functionblock.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_functionblock.o ${OBJECTDIR}/src/basic_functionblock_nomain.o;\
	fi

${OBJECTDIR}/src/basic_gfx_nomain.o: ${OBJECTDIR}/src/basic_gfx.o src/basic_gfx.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_gfx.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_nomain.o src/basic_gfx.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_gfx.o ${OBJECTDIR}/src/basic_gfx_nomain.o;\
	fi

${OBJECTDIR}/src/basic_gfx_serial_nomain.o: ${OBJECTDIR}/src/basic_gfx_serial.o src/basic_gfx_serial.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_gfx_serial.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_serial_nomain.o src/basic_gfx_serial.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_gfx_serial.o ${OBJECTDIR}/src/basic_gfx_serial_nomain.o;\
	fi

${OBJECTDIR}/src/basic_gfx_tvout_nomain.o: ${OBJECTDIR}/src/basic_gfx_tvout.o src/basic_gfx_tvout.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_gfx_tvout.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_tvout_nomain.o src/basic_gfx_tvout.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_gfx_tvout.o ${OBJECTDIR}/src/basic_gfx_tvout_nomain.o;\
	fi

${OBJECTDIR}/src/basic_gfx_utft_nomain.o: ${OBJECTDIR}/src/basic_gfx_utft.o src/basic_gfx_utft.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_gfx_utft.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_utft_nomain.o src/basic_gfx_utft.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_gfx_utft.o ${OBJECTDIR}/src/basic_gfx_utft_nomain.o;\
	fi

${OBJECTDIR}/src/basic_internalfuncs_nomain.o: ${OBJECTDIR}/src/basic_internalfuncs.o src/basic_internalfuncs.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_internalfuncs.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_internalfuncs_nomain.o src/basic_internalfuncs.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_internalfuncs.o ${OBJECTDIR}/src/basic_internalfuncs_nomain.o;\
	fi

${OBJECTDIR}/src/basic_interpreter_nomain.o: ${OBJECTDIR}/src/basic_interpreter.o src/basic_interpreter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_interpreter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_nomain.o src/basic_interpreter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_interpreter.o ${OBJECTDIR}/src/basic_interpreter_nomain.o;\
	fi

${OBJECTDIR}/src/basic_interpreter_matrix_nomain.o: ${OBJECTDIR}/src/basic_interpreter_matrix.o src/basic_interpreter_matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_interpreter_matrix.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_matrix_nomain.o src/basic_interpreter_matrix.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_interpreter_matrix.o ${OBJECTDIR}/src/basic_interpreter_matrix_nomain.o;\
	fi

${OBJECTDIR}/src/basic_lexer_nomain.o: ${OBJECTDIR}/src/basic_lexer.o src/basic_lexer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_lexer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_lexer_nomain.o src/basic_lexer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_lexer.o ${OBJECTDIR}/src/basic_lexer_nomain.o;\
	fi

${OBJECTDIR}/src/basic_math_nomain.o: ${OBJECTDIR}/src/basic_math.o src/basic_math.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_math.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_math_nomain.o src/basic_math.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_math.o ${OBJECTDIR}/src/basic_math_nomain.o;\
	fi

${OBJECTDIR}/src/basic_parser_nomain.o: ${OBJECTDIR}/src/basic_parser.o src/basic_parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_parser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_nomain.o src/basic_parser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_parser.o ${OBJECTDIR}/src/basic_parser_nomain.o;\
	fi

${OBJECTDIR}/src/basic_parser_value_nomain.o: ${OBJECTDIR}/src/basic_parser_value.o src/basic_parser_value.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_parser_value.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value_nomain.o src/basic_parser_value.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_parser_value.o ${OBJECTDIR}/src/basic_parser_value_nomain.o;\
	fi

${OBJECTDIR}/src/basic_program_nomain.o: ${OBJECTDIR}/src/basic_program.o src/basic_program.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_program.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_program_nomain.o src/basic_program.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_program.o ${OBJECTDIR}/src/basic_program_nomain.o;\
	fi

${OBJECTDIR}/src/basic_sdfs_nomain.o: ${OBJECTDIR}/src/basic_sdfs.o src/basic_sdfs.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_sdfs.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_sdfs_nomain.o src/basic_sdfs.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_sdfs.o ${OBJECTDIR}/src/basic_sdfs_nomain.o;\
	fi

${OBJECTDIR}/src/ucbasic_main_nomain.o: ${OBJECTDIR}/src/ucbasic_main.o src/ucbasic_main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ucbasic_main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DNDEBUG -D__AVR_ATmega2560__ -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/TVout -I${ARDUINO_PATH}/libraries/PS2Keyboard -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/libraries/SD/src -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../UTFT/include -I../../libsdcard/SDCard/src -I../../libutft/UTFT -I../../tvoutex/TVoutEx -I../libbasic/include -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ucbasic_main_nomain.o src/ucbasic_main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ucbasic_main.o ${OBJECTDIR}/src/ucbasic_main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../../libutft && ${MAKE}  -f Makefile CONF=Arduino_mega2560 clean
	cd ../../tvoutex/livbtvoutex && ${MAKE}  -f Makefile CONF=Arduino_MEGA2560 clean
	cd ../../libarduinoext && ${MAKE}  -f Makefile CONF=Arduino_mega2560 clean
	cd ../../libsdcard/libsdcard && ${MAKE}  -f Makefile CONF=Arduino_MEGA2560 clean
	cd ../../libarduino && ${MAKE}  -f Makefile CONF=Mega_2560 clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
