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
	${OBJECTDIR}/include/entry.o


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
LDLIBSOPTIONS=../arduinoext/dist/Arduino_uno/Arduino-Linux/libarduinoext.a ../libarduino/dist/Uno/libarduino.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/basic

${CND_DISTDIR}/${CND_CONF}/basic: ../arduinoext/dist/Arduino_uno/Arduino-Linux/libarduinoext.a

${CND_DISTDIR}/${CND_CONF}/basic: ../libarduino/dist/Uno/libarduino.a

${CND_DISTDIR}/${CND_CONF}/basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/basic ${OBJECTFILES} ${LDLIBSOPTIONS} -Wall -Wextra -Os -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p

${OBJECTDIR}/include/entry.o: include/entry.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_UNO -DF_CPU=16000000L -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/eightanaloginputs -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/EEPROM/src -Iinclude -I../arduinoext/include -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/entry.o include/entry.cpp

# Subprojects
.build-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Arduino_uno
	cd ../libarduino && ${MAKE}  -f Makefile CONF=Uno

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Arduino_uno clean
	cd ../libarduino && ${MAKE}  -f Makefile CONF=Uno clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc