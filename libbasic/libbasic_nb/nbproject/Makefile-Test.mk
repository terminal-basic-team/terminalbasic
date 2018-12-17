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
CND_CONF=Test
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/511e4115/basic.o \
	${OBJECTDIR}/_ext/511e4115/basic_lexer.o \
	${OBJECTDIR}/_ext/511e4115/basic_value.o \
	${OBJECTDIR}/_ext/c3417bc2/e_sqrtf.o \
	${OBJECTDIR}/_ext/511e4115/test.o \
	${OBJECTDIR}/_ext/511e4115/tools.o


# C Compiler Flags
CFLAGS=-std=gnu99

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libbasic_nb

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libbasic_nb: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libbasic_nb ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/511e4115/basic.o: ../src/basic.c
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DINTERNAL_MATH=1 -I../include -I../../../libarduinoemulator/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/basic.o ../src/basic.c

${OBJECTDIR}/_ext/511e4115/basic_lexer.o: ../src/basic_lexer.c
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DINTERNAL_MATH=1 -I../include -I../../../libarduinoemulator/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/basic_lexer.o ../src/basic_lexer.c

${OBJECTDIR}/_ext/511e4115/basic_value.o: ../src/basic_value.c
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DINTERNAL_MATH=1 -I../include -I../../../libarduinoemulator/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/basic_value.o ../src/basic_value.c

${OBJECTDIR}/_ext/c3417bc2/e_sqrtf.o: ../src/math/e_sqrtf.c
	${MKDIR} -p ${OBJECTDIR}/_ext/c3417bc2
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DINTERNAL_MATH=1 -I../include -I../../../libarduinoemulator/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/c3417bc2/e_sqrtf.o ../src/math/e_sqrtf.c

${OBJECTDIR}/_ext/511e4115/test.o: ../src/test.c
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DINTERNAL_MATH=1 -I../include -I../../../libarduinoemulator/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/test.o ../src/test.c

${OBJECTDIR}/_ext/511e4115/tools.o: ../src/tools.c
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DINTERNAL_MATH=1 -I../include -I../../../libarduinoemulator/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/tools.o ../src/tools.c

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
