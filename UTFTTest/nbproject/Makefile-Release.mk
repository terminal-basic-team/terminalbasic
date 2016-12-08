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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
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
CCFLAGS=-O3 -march=pentium3 -mfpmath=sse
CXXFLAGS=-O3 -march=pentium3 -mfpmath=sse

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../arduinoext/dist/Release/GNU-Linux/libarduinoext.a ../libarduinoemulator/dist/Release/GNU-Linux/liblibarduinoemulator.a ../../posixcpp/posixcpp/dist/Release_static/GNU-Linux/libposixcpp.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/basic

${CND_DISTDIR}/${CND_CONF}/basic: ../arduinoext/dist/Release/GNU-Linux/libarduinoext.a

${CND_DISTDIR}/${CND_CONF}/basic: ../libarduinoemulator/dist/Release/GNU-Linux/liblibarduinoemulator.a

${CND_DISTDIR}/${CND_CONF}/basic: ../../posixcpp/posixcpp/dist/Release_static/GNU-Linux/libposixcpp.a

${CND_DISTDIR}/${CND_CONF}/basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/basic ${OBJECTFILES} ${LDLIBSOPTIONS} -static

${OBJECTDIR}/include/entry.o: include/entry.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -s -I../arduino -Isrc -I../include -I../arduinoext/include -I../libarduinoemulator/include -Iinclude -I../../posixcpp/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/entry.o include/entry.cpp

# Subprojects
.build-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Release
	cd ../libarduinoemulator && ${MAKE}  -f Makefile CONF=Release
	cd ../../posixcpp/posixcpp && ${MAKE}  -f Makefile CONF=Release_static

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Release clean
	cd ../libarduinoemulator && ${MAKE}  -f Makefile CONF=Release clean
	cd ../../posixcpp/posixcpp && ${MAKE}  -f Makefile CONF=Release_static clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
