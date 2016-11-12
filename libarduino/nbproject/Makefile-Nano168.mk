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
CND_CONF=Nano168
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/f54da836/CDC.o \
	${OBJECTDIR}/_ext/f54da836/HardwareSerial.o \
	${OBJECTDIR}/_ext/f54da836/HardwareSerial0.o \
	${OBJECTDIR}/_ext/f54da836/HardwareSerial1.o \
	${OBJECTDIR}/_ext/f54da836/HardwareSerial2.o \
	${OBJECTDIR}/_ext/f54da836/HardwareSerial3.o \
	${OBJECTDIR}/_ext/f54da836/IPAddress.o \
	${OBJECTDIR}/_ext/f54da836/PluggableUSB.o \
	${OBJECTDIR}/_ext/f54da836/Print.o \
	${OBJECTDIR}/_ext/f54da836/Stream.o \
	${OBJECTDIR}/_ext/f54da836/Tone.o \
	${OBJECTDIR}/_ext/f54da836/USBCore.o \
	${OBJECTDIR}/_ext/f54da836/WInterrupts.o \
	${OBJECTDIR}/_ext/f54da836/WMath.o \
	${OBJECTDIR}/_ext/f54da836/WString.o \
	${OBJECTDIR}/_ext/f54da836/abi.o \
	${OBJECTDIR}/_ext/f54da836/hooks.o \
	${OBJECTDIR}/_ext/f54da836/main.o \
	${OBJECTDIR}/_ext/f54da836/new.o \
	${OBJECTDIR}/_ext/f54da836/wiring.o \
	${OBJECTDIR}/_ext/f54da836/wiring_analog.o \
	${OBJECTDIR}/_ext/f54da836/wiring_digital.o \
	${OBJECTDIR}/_ext/f54da836/wiring_pulse.o \
	${OBJECTDIR}/_ext/f54da836/wiring_shift.o \
	${OBJECTDIR}/_ext/d883fa1d/SoftwareSerial.o \
	${OBJECTDIR}/_wiring_pulse.o


# C Compiler Flags
CFLAGS=-Os -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega168

# CC Compiler Flags
CCFLAGS=-Os -Wextra -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega168 -fno-rtti
CXXFLAGS=-Os -Wextra -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega168 -fno-rtti

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/libarduino.a

${CND_DISTDIR}/${CND_CONF}/libarduino.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/libarduino.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/libarduino.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/libarduino.a

${OBJECTDIR}/_ext/f54da836/CDC.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/CDC.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/CDC.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/CDC.cpp

${OBJECTDIR}/_ext/f54da836/HardwareSerial.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/HardwareSerial.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial.cpp

${OBJECTDIR}/_ext/f54da836/HardwareSerial0.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial0.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/HardwareSerial0.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial0.cpp

${OBJECTDIR}/_ext/f54da836/HardwareSerial1.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial1.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/HardwareSerial1.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial1.cpp

${OBJECTDIR}/_ext/f54da836/HardwareSerial2.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial2.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/HardwareSerial2.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial2.cpp

${OBJECTDIR}/_ext/f54da836/HardwareSerial3.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial3.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/HardwareSerial3.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial3.cpp

${OBJECTDIR}/_ext/f54da836/IPAddress.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/IPAddress.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/IPAddress.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/IPAddress.cpp

${OBJECTDIR}/_ext/f54da836/PluggableUSB.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/PluggableUSB.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/PluggableUSB.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/PluggableUSB.cpp

${OBJECTDIR}/_ext/f54da836/Print.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Print.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/Print.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Print.cpp

${OBJECTDIR}/_ext/f54da836/Stream.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Stream.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/Stream.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Stream.cpp

${OBJECTDIR}/_ext/f54da836/Tone.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Tone.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/Tone.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Tone.cpp

${OBJECTDIR}/_ext/f54da836/USBCore.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/USBCore.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/USBCore.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/USBCore.cpp

${OBJECTDIR}/_ext/f54da836/WInterrupts.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WInterrupts.c nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/WInterrupts.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WInterrupts.c

${OBJECTDIR}/_ext/f54da836/WMath.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WMath.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/WMath.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WMath.cpp

${OBJECTDIR}/_ext/f54da836/WString.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WString.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/WString.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WString.cpp

${OBJECTDIR}/_ext/f54da836/abi.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/abi.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/abi.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/abi.cpp

${OBJECTDIR}/_ext/f54da836/hooks.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/hooks.c nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/hooks.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/hooks.c

${OBJECTDIR}/_ext/f54da836/main.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/main.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/main.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/main.cpp

${OBJECTDIR}/_ext/f54da836/new.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/new.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/new.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/new.cpp

${OBJECTDIR}/_ext/f54da836/wiring.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring.c nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/wiring.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring.c

${OBJECTDIR}/_ext/f54da836/wiring_analog.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring_analog.c nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/wiring_analog.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring_analog.c

${OBJECTDIR}/_ext/f54da836/wiring_digital.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring_digital.c nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/wiring_digital.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring_digital.c

${OBJECTDIR}/_ext/f54da836/wiring_pulse.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring_pulse.c nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/wiring_pulse.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring_pulse.c

${OBJECTDIR}/_ext/f54da836/wiring_shift.o: /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring_shift.c nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/f54da836
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f54da836/wiring_shift.o /opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/wiring_shift.c

${OBJECTDIR}/_ext/d883fa1d/SoftwareSerial.o: /opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src/SoftwareSerial.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/_ext/d883fa1d
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -I/opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d883fa1d/SoftwareSerial.o /opt/arduino-1.6.12/hardware/arduino/avr/libraries/SoftwareSerial/src/SoftwareSerial.cpp

${OBJECTDIR}/_wiring_pulse.o: _wiring_pulse.S nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DARDUINO=10612 -DARDUINO_ARCH_AVR -DARDUINO_AVR_NANO -DF_CPU=16000000L -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs -x assembler-with-cpp -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_wiring_pulse.o _wiring_pulse.S

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
