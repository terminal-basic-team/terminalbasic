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
	${OBJECTDIR}/include/entry.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega2560 -ffunction-sections -fdata-sections -flto -fno-rtti
CXXFLAGS=-Os -Wextra -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -MMD -mmcu=atmega2560 -ffunction-sections -fdata-sections -flto -fno-rtti

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../arduinoext/dist/Arduino_mega2560/Arduino-Linux/libarduinoext.a ../libarduino/dist/Mega_2560/libarduino.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/basic

${CND_DISTDIR}/${CND_CONF}/basic: ../arduinoext/dist/Arduino_mega2560/Arduino-Linux/libarduinoext.a

${CND_DISTDIR}/${CND_CONF}/basic: ../libarduino/dist/Mega_2560/libarduino.a

${CND_DISTDIR}/${CND_CONF}/basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/basic ${OBJECTFILES} ${LDLIBSOPTIONS} -Os -Wall -Wextra -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega2560

${OBJECTDIR}/include/entry.o: include/entry.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10607 -DARDUINO_ARCH_AVR -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DUSEUTFT -I${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino -I${ARDUINO_PATH}/hardware/arduino/avr/variants/mega -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SoftwareSerial/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/EEPROM/src -I${ARDUINO_PATH}/hardware/arduino/avr/libraries/SPI/src -I${ARDUINO_PATH}/libraries/SD/src -I${ARDUINO_PATH}/libraries/UTFT -Iinclude -I../arduinoext/include -include Arduino.h -include Arduino.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/entry.o include/entry.cpp

# Subprojects
.build-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Arduino_mega2560
	cd ../libarduino && ${MAKE}  -f Makefile CONF=Mega_2560

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Arduino_mega2560 clean
	cd ../libarduino && ${MAKE}  -f Makefile CONF=Mega_2560 clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
