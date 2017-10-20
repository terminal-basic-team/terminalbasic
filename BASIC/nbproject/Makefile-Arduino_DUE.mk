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
CC=arm-none-eabi-gcc
CCC=arm-none-eabi-g++
CXX=arm-none-eabi-g++
FC=gfortran
AS=arm-none-eabi-as

# Macros
CND_PLATFORM=Arduino_ARM-Linux
CND_DLIB_EXT=so
CND_CONF=Arduino_DUE
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
CFLAGS=-Os -mthumb -mcpu=cortex-m3 -MMD --param max-inline-insns-single=500 -nostdlib -fdata-sections -ffunction-sections -std=gnu11 -Wextra

# CC Compiler Flags
CCFLAGS=-Os -mthumb -mcpu=cortex-m3 -MMD -fno-exceptions -fno-rtti --param max-inline-insns-single=500 -fno-threadsafe-statics -nostdlib -fdata-sections -ffunction-sections -std=gnu++11 -Wextra
CXXFLAGS=-Os -mthumb -mcpu=cortex-m3 -MMD -fno-exceptions -fno-rtti --param max-inline-insns-single=500 -fno-threadsafe-statics -nostdlib -fdata-sections -ffunction-sections -std=gnu++11 -Wextra

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../libarduinodue/dist/Debug/Arduino_ARM-Linux/liblibarduinodue.a -lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/basic

${CND_DISTDIR}/${CND_CONF}/basic: ../../libarduinodue/dist/Debug/Arduino_ARM-Linux/liblibarduinodue.a

${CND_DISTDIR}/${CND_CONF}/basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	arm-none-eabi-gcc -o ${CND_DISTDIR}/${CND_CONF}/basic ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/basic.o: src/basic.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic.o src/basic.cpp

${OBJECTDIR}/src/basic_arduinoio.o: src/basic_arduinoio.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_arduinoio.o src/basic_arduinoio.cpp

${OBJECTDIR}/src/basic_exteeprom.o: src/basic_exteeprom.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_exteeprom.o src/basic_exteeprom.cpp

${OBJECTDIR}/src/basic_functionblock.o: src/basic_functionblock.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_functionblock.o src/basic_functionblock.cpp

${OBJECTDIR}/src/basic_gfx.o: src/basic_gfx.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx.o src/basic_gfx.cpp

${OBJECTDIR}/src/basic_gfx_tvout.o: src/basic_gfx_tvout.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_tvout.o src/basic_gfx_tvout.cpp

${OBJECTDIR}/src/basic_gfx_utft.o: src/basic_gfx_utft.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_utft.o src/basic_gfx_utft.cpp

${OBJECTDIR}/src/basic_internalfuncs.o: src/basic_internalfuncs.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_internalfuncs.o src/basic_internalfuncs.cpp

${OBJECTDIR}/src/basic_interpreter.o: src/basic_interpreter.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter.o src/basic_interpreter.cpp

${OBJECTDIR}/src/basic_lexer.o: src/basic_lexer.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_lexer.o src/basic_lexer.cpp

${OBJECTDIR}/src/basic_math.o: src/basic_math.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_math.o src/basic_math.cpp

${OBJECTDIR}/src/basic_parser.o: src/basic_parser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser.o src/basic_parser.cpp

${OBJECTDIR}/src/basic_parser_value.o: src/basic_parser_value.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value.o src/basic_parser_value.cpp

${OBJECTDIR}/src/basic_program.o: src/basic_program.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_program.o src/basic_program.cpp

${OBJECTDIR}/src/basic_sdfs.o: src/basic_sdfs.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_sdfs.o src/basic_sdfs.cpp

${OBJECTDIR}/src/ucbasic_main.o: src/ucbasic_main.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ucbasic_main.o src/ucbasic_main.cpp

# Subprojects
.build-subprojects:
	cd ../../libarduinodue && ${MAKE}  -f Makefile CONF=Debug

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/TableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/TableTest.o: tests/TableTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TableTest.o tests/TableTest.cpp


${OBJECTDIR}/src/basic_nomain.o: ${OBJECTDIR}/src/basic.o src/basic.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/basic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_nomain.o src/basic.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_arduinoio_nomain.o src/basic_arduinoio.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_exteeprom_nomain.o src/basic_exteeprom.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_functionblock_nomain.o src/basic_functionblock.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_nomain.o src/basic_gfx.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_tvout_nomain.o src/basic_gfx_tvout.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_utft_nomain.o src/basic_gfx_utft.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_internalfuncs_nomain.o src/basic_internalfuncs.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_nomain.o src/basic_interpreter.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_lexer_nomain.o src/basic_lexer.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_math_nomain.o src/basic_math.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_nomain.o src/basic_parser.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_parser_value_nomain.o src/basic_parser_value.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_program_nomain.o src/basic_program.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_sdfs_nomain.o src/basic_sdfs.cpp;\
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
	    $(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ucbasic_main_nomain.o src/ucbasic_main.cpp;\
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
	cd ../../libarduinodue && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
