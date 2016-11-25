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
CND_CONF=Arduino_nano328
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/include/basic_functionblock.o \
	${OBJECTDIR}/include/basic_math.o \
	${OBJECTDIR}/src/basic_interpreter_program.o \
	${OBJECTDIR}/src/basic_parser_value.o \
	${OBJECTDIR}/src/interpreter.o \
	${OBJECTDIR}/src/lexer.o \
	${OBJECTDIR}/src/parser.o \
	${OBJECTDIR}/src/ucbasic_main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega328p -ffunction-sections -fdata-sections -flto
CXXFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega328p -ffunction-sections -fdata-sections -flto

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../arduinoext/dist/Arduino_nano328/Arduino-Linux/libarduinoext.a ../libarduino/dist/Nano328/libarduino.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/basic

${CND_DISTDIR}/${CND_CONF}/basic: ../arduinoext/dist/Arduino_nano328/Arduino-Linux/libarduinoext.a

${CND_DISTDIR}/${CND_CONF}/basic: ../libarduino/dist/Nano328/libarduino.a

${CND_DISTDIR}/${CND_CONF}/basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/basic ${OBJECTFILES} ${LDLIBSOPTIONS} -Wall -Wextra -Os -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -Wl,-Map,${CND_DISTDIR}/${CND_CONF}/basic.map

${OBJECTDIR}/include/basic_functionblock.o: include/basic_functionblock.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -Iinclude -I../arduinoext/include -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/basic_functionblock.o include/basic_functionblock.cpp

${OBJECTDIR}/include/basic_math.o: include/basic_math.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -Iinclude -I../arduinoext/include -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/basic_math.o include/basic_math.cpp

${OBJECTDIR}/src/basic_interpreter_program.o: src/basic_interpreter_program.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -Iinclude -I../arduinoext/include -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_program.o src/basic_interpreter_program.cpp

${OBJECTDIR}/src/basic_parser_value.o: src/basic_parser_value.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -Iinclude -I../arduinoext/include -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value.o src/basic_parser_value.cpp

${OBJECTDIR}/src/interpreter.o: src/interpreter.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -Iinclude -I../arduinoext/include -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/interpreter.o src/interpreter.cpp

${OBJECTDIR}/src/lexer.o: src/lexer.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -Iinclude -I../arduinoext/include -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/lexer.o src/lexer.cpp

${OBJECTDIR}/src/parser.o: src/parser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -Iinclude -I../arduinoext/include -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/parser.o src/parser.cpp

${OBJECTDIR}/src/ucbasic_main.o: src/ucbasic_main.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -DNDEBUG -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -Iinclude -I../arduinoext/include -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ucbasic_main.o src/ucbasic_main.cpp

# Subprojects
.build-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Arduino_nano328
	cd ../libarduino && ${MAKE}  -f Makefile CONF=Nano328

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Arduino_nano328 clean
	cd ../libarduino && ${MAKE}  -f Makefile CONF=Nano328 clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
