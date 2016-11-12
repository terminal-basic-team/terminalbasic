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
	${OBJECTDIR}/_ext/38f13fd/arduino_logger.o \
	${OBJECTDIR}/include/bcopy.o \
	${OBJECTDIR}/src/cps_mosprotocol.o \
	${OBJECTDIR}/src/cps_mosprotocol_arduino.o \
	${OBJECTDIR}/src/protocol.o \
	${OBJECTDIR}/src/protocol_arduino.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/newsimpletest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`pkg-config --cflags posixcpp` 
CXXFLAGS=`pkg-config --cflags posixcpp` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libarduinoext.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libarduinoext.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libarduinoext.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libarduinoext.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libarduinoext.a

${OBJECTDIR}/_ext/38f13fd/arduino_logger.o: ../arduinoext/src/arduino_logger.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/38f13fd
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/38f13fd/arduino_logger.o ../arduinoext/src/arduino_logger.cpp

${OBJECTDIR}/include/bcopy.o: include/bcopy.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/bcopy.o include/bcopy.cpp

${OBJECTDIR}/src/cps_mosprotocol.o: src/cps_mosprotocol.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cps_mosprotocol.o src/cps_mosprotocol.cpp

${OBJECTDIR}/src/cps_mosprotocol_arduino.o: src/cps_mosprotocol_arduino.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cps_mosprotocol_arduino.o src/cps_mosprotocol_arduino.cpp

${OBJECTDIR}/src/protocol.o: src/protocol.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/protocol.o src/protocol.cpp

${OBJECTDIR}/src/protocol_arduino.o: src/protocol_arduino.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/protocol_arduino.o src/protocol_arduino.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:
	cd ../libarduinoemulator && ${MAKE}  -f Makefile CONF=Debug

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   ../libarduinoemulator/dist/Debug/GNU-Linux/liblibarduinoemulator.a `pkg-config --libs posixcpp`   


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/_ext/38f13fd/arduino_logger_nomain.o: ${OBJECTDIR}/_ext/38f13fd/arduino_logger.o ../arduinoext/src/arduino_logger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/38f13fd
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/38f13fd/arduino_logger.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/38f13fd/arduino_logger_nomain.o ../arduinoext/src/arduino_logger.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/38f13fd/arduino_logger.o ${OBJECTDIR}/_ext/38f13fd/arduino_logger_nomain.o;\
	fi

${OBJECTDIR}/include/bcopy_nomain.o: ${OBJECTDIR}/include/bcopy.o include/bcopy.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/bcopy.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/bcopy_nomain.o include/bcopy.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/bcopy.o ${OBJECTDIR}/include/bcopy_nomain.o;\
	fi

${OBJECTDIR}/src/cps_mosprotocol_nomain.o: ${OBJECTDIR}/src/cps_mosprotocol.o src/cps_mosprotocol.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/cps_mosprotocol.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cps_mosprotocol_nomain.o src/cps_mosprotocol.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/cps_mosprotocol.o ${OBJECTDIR}/src/cps_mosprotocol_nomain.o;\
	fi

${OBJECTDIR}/src/cps_mosprotocol_arduino_nomain.o: ${OBJECTDIR}/src/cps_mosprotocol_arduino.o src/cps_mosprotocol_arduino.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/cps_mosprotocol_arduino.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cps_mosprotocol_arduino_nomain.o src/cps_mosprotocol_arduino.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/cps_mosprotocol_arduino.o ${OBJECTDIR}/src/cps_mosprotocol_arduino_nomain.o;\
	fi

${OBJECTDIR}/src/protocol_nomain.o: ${OBJECTDIR}/src/protocol.o src/protocol.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/protocol.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/protocol_nomain.o src/protocol.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/protocol.o ${OBJECTDIR}/src/protocol_nomain.o;\
	fi

${OBJECTDIR}/src/protocol_arduino_nomain.o: ${OBJECTDIR}/src/protocol_arduino.o src/protocol_arduino.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/protocol_arduino.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -I../libarduinoemulator/include -I/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/protocol_arduino_nomain.o src/protocol_arduino.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/protocol_arduino.o ${OBJECTDIR}/src/protocol_arduino_nomain.o;\
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

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
