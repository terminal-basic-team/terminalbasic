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
CND_CONF=Arduino_UNO
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
	${OBJECTDIR}/src/basic_exteeprom.o \
	${OBJECTDIR}/src/basic_functionblock.o \
	${OBJECTDIR}/src/basic_gfx.o \
	${OBJECTDIR}/src/basic_gfx_tvout.o \
	${OBJECTDIR}/src/basic_gfx_utft.o \
	${OBJECTDIR}/src/basic_internalfuncs.o \
	${OBJECTDIR}/src/basic_interpreter.o \
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
CCFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega328p -ffunction-sections -fdata-sections -flto -fno-rtti -mcall-prologues
CXXFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega328p -ffunction-sections -fdata-sections -flto -fno-rtti -mcall-prologues

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../libarduinoext/dist/Arduino_uno/Arduino-Linux/liblibarduinoext.a ../../libarduino/dist/Uno/libarduino.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/terminal-basic

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libarduinoext/dist/Arduino_uno/Arduino-Linux/liblibarduinoext.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ../../libarduino/dist/Uno/libarduino.a

${CND_DISTDIR}/${CND_CONF}/terminal-basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/terminal-basic ${OBJECTFILES} ${LDLIBSOPTIONS} -Wall -Wextra -Os -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p

${OBJECTDIR}/src/basic.o: src/basic.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic.o src/basic.cpp

${OBJECTDIR}/src/basic_arduinoio.o: src/basic_arduinoio.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_arduinoio.o src/basic_arduinoio.cpp

${OBJECTDIR}/src/basic_exteeprom.o: src/basic_exteeprom.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_exteeprom.o src/basic_exteeprom.cpp

${OBJECTDIR}/src/basic_functionblock.o: src/basic_functionblock.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_functionblock.o src/basic_functionblock.cpp

${OBJECTDIR}/src/basic_gfx.o: src/basic_gfx.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx.o src/basic_gfx.cpp

${OBJECTDIR}/src/basic_gfx_tvout.o: src/basic_gfx_tvout.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_tvout.o src/basic_gfx_tvout.cpp

${OBJECTDIR}/src/basic_gfx_utft.o: src/basic_gfx_utft.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_utft.o src/basic_gfx_utft.cpp

${OBJECTDIR}/src/basic_internalfuncs.o: src/basic_internalfuncs.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_internalfuncs.o src/basic_internalfuncs.cpp

${OBJECTDIR}/src/basic_interpreter.o: src/basic_interpreter.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter.o src/basic_interpreter.cpp

${OBJECTDIR}/src/basic_lexer.o: src/basic_lexer.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_lexer.o src/basic_lexer.cpp

${OBJECTDIR}/src/basic_math.o: src/basic_math.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_math.o src/basic_math.cpp

${OBJECTDIR}/src/basic_parser.o: src/basic_parser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser.o src/basic_parser.cpp

${OBJECTDIR}/src/basic_parser_value.o: src/basic_parser_value.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value.o src/basic_parser_value.cpp

${OBJECTDIR}/src/basic_program.o: src/basic_program.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_program.o src/basic_program.cpp

${OBJECTDIR}/src/basic_sdfs.o: src/basic_sdfs.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_sdfs.o src/basic_sdfs.cpp

${OBJECTDIR}/src/ucbasic_main.o: src/ucbasic_main.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ucbasic_main.o src/ucbasic_main.cpp

# Subprojects
.build-subprojects:
	cd ../../libarduinoext && ${MAKE}  -f Makefile CONF=Arduino_uno
	cd ../../libarduino && ${MAKE}  -f Makefile CONF=Uno

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/TableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/TableTest.o: tests/TableTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -I. -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TableTest.o tests/TableTest.cpp


${OBJECTDIR}/src/basic_nomain.o: ${OBJECTDIR}/src/basic.o src/basic.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_nomain.o src/basic.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_arduinoio_nomain.o src/basic_arduinoio.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_arduinoio.o ${OBJECTDIR}/src/basic_arduinoio_nomain.o;\
	fi

${OBJECTDIR}/src/basic_exteeprom_nomain.o: ${OBJECTDIR}/src/basic_exteeprom.o src/basic_exteeprom.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_exteeprom.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_exteeprom_nomain.o src/basic_exteeprom.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_functionblock_nomain.o src/basic_functionblock.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_nomain.o src/basic_gfx.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_gfx.o ${OBJECTDIR}/src/basic_gfx_nomain.o;\
	fi

${OBJECTDIR}/src/basic_gfx_tvout_nomain.o: ${OBJECTDIR}/src/basic_gfx_tvout.o src/basic_gfx_tvout.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_gfx_tvout.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_tvout_nomain.o src/basic_gfx_tvout.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_utft_nomain.o src/basic_gfx_utft.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_internalfuncs_nomain.o src/basic_internalfuncs.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_nomain.o src/basic_interpreter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/basic_interpreter.o ${OBJECTDIR}/src/basic_interpreter_nomain.o;\
	fi

${OBJECTDIR}/src/basic_lexer_nomain.o: ${OBJECTDIR}/src/basic_lexer.o src/basic_lexer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic_lexer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_lexer_nomain.o src/basic_lexer.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_math_nomain.o src/basic_math.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_nomain.o src/basic_parser.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value_nomain.o src/basic_parser_value.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_program_nomain.o src/basic_program.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_sdfs_nomain.o src/basic_sdfs.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10803 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/Wire/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/libraries/TVoutfonts -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/PS2Keyboard -Iinclude -I../../libarduinoext/include -I../TVoutEx -I../../libsdcard/SDCard -include Arduino.h -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ucbasic_main_nomain.o src/ucbasic_main.cpp;\
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
	cd ../../libarduinoext && ${MAKE}  -f Makefile CONF=Arduino_uno clean
	cd ../../libarduino && ${MAKE}  -f Makefile CONF=Uno clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
