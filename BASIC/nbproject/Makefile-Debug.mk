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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/basic_interpreter_program.o \
	${OBJECTDIR}/src/basic_parser_value.o \
	${OBJECTDIR}/src/interpreter.o \
	${OBJECTDIR}/src/lexer.o \
	${OBJECTDIR}/src/parser.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../arduinoext/dist/Debug/GNU-Linux/libarduinoext.a ../libarduinoemulator/dist/Debug/GNU-Linux/liblibarduinoemulator.a -Wl,-rpath,'../../posixcpp/posixcpp/../lib/Debug_dynamic' -L../../posixcpp/posixcpp/../lib/Debug_dynamic -lposixcpp

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/basic

${CND_DISTDIR}/${CND_CONF}/basic: ../arduinoext/dist/Debug/GNU-Linux/libarduinoext.a

${CND_DISTDIR}/${CND_CONF}/basic: ../libarduinoemulator/dist/Debug/GNU-Linux/liblibarduinoemulator.a

${CND_DISTDIR}/${CND_CONF}/basic: ../../posixcpp/posixcpp/../lib/Debug_dynamic/libposixcpp.so

${CND_DISTDIR}/${CND_CONF}/basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/basic ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I../arduino -Isrc -I../include -I../arduinoext/include -I../libarduinoemulator/include -Iinclude -I../../posixcpp/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/basic_interpreter_program.o: src/basic_interpreter_program.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I../arduino -Isrc -I../include -I../arduinoext/include -I../libarduinoemulator/include -Iinclude -I../../posixcpp/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_program.o src/basic_interpreter_program.cpp

${OBJECTDIR}/src/basic_parser_value.o: src/basic_parser_value.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I../arduino -Isrc -I../include -I../arduinoext/include -I../libarduinoemulator/include -Iinclude -I../../posixcpp/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value.o src/basic_parser_value.cpp

${OBJECTDIR}/src/interpreter.o: src/interpreter.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I../arduino -Isrc -I../include -I../arduinoext/include -I../libarduinoemulator/include -Iinclude -I../../posixcpp/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/interpreter.o src/interpreter.cpp

${OBJECTDIR}/src/lexer.o: src/lexer.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I../arduino -Isrc -I../include -I../arduinoext/include -I../libarduinoemulator/include -Iinclude -I../../posixcpp/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/lexer.o src/lexer.cpp

${OBJECTDIR}/src/parser.o: src/parser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I../arduino -Isrc -I../include -I../arduinoext/include -I../libarduinoemulator/include -Iinclude -I../../posixcpp/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/parser.o src/parser.cpp

# Subprojects
.build-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Debug
	cd ../libarduinoemulator && ${MAKE}  -f Makefile CONF=Debug
	cd ../../posixcpp/posixcpp && ${MAKE}  -f Makefile CONF=Debug_dynamic

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/libposixcpp.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/basic

# Subprojects
.clean-subprojects:
	cd ../arduinoext && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../libarduinoemulator && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../posixcpp/posixcpp && ${MAKE}  -f Makefile CONF=Debug_dynamic clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
