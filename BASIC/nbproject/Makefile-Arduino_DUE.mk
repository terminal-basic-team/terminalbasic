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
	${OBJECTDIR}/src/basic_arduinoio.o \
	${OBJECTDIR}/src/basic_common.o \
	${OBJECTDIR}/src/basic_dataparser.o \
	${OBJECTDIR}/src/basic_exteeprom.o \
	${OBJECTDIR}/src/basic_functionblock.o \
	${OBJECTDIR}/src/basic_gfx.o \
	${OBJECTDIR}/src/basic_gfx_serial.o \
	${OBJECTDIR}/src/basic_gfx_tvout.o \
	${OBJECTDIR}/src/basic_gfx_utft.o \
	${OBJECTDIR}/src/basic_internalfuncs.o \
	${OBJECTDIR}/src/basic_interpreter.o \
	${OBJECTDIR}/src/basic_interpreter_matrix.o \
	${OBJECTDIR}/src/basic_lexer.o \
	${OBJECTDIR}/src/basic_math.o \
	${OBJECTDIR}/src/basic_parser.o \
	${OBJECTDIR}/src/basic_parser_value.o \
	${OBJECTDIR}/src/basic_program.o \
	${OBJECTDIR}/src/basic_sdfs.o \
	${OBJECTDIR}/src/ucbasic_main.o


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
LDLIBSOPTIONS=-Wl,--gc-sections -Wl,-Map,basic_due.map -T/opt/Arduino/sam/variants/arduino_due_x/linker_scripts/gcc/flash.ld -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,-warn-common -Wl,--warn-section-align -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u write -u _exit -u kill -u _getpid /opt/Arduino/sam/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a ../../libarduinodue/dist/Debug/Arduino_ARM-Linux/liblibarduinodue.a -Wl,--end-group -lm -lgcc

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/basic

${CND_DISTDIR}/${CND_CONF}/basic: /opt/Arduino/sam/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

${CND_DISTDIR}/${CND_CONF}/basic: ../../libarduinodue/dist/Debug/Arduino_ARM-Linux/liblibarduinodue.a

${CND_DISTDIR}/${CND_CONF}/basic: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	arm-none-eabi-gcc -o ${CND_DISTDIR}/${CND_CONF}/basic ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/basic_arduinoio.o: src/basic_arduinoio.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_arduinoio.o src/basic_arduinoio.cpp

${OBJECTDIR}/src/basic_common.o: src/basic_common.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_common.o src/basic_common.cpp

${OBJECTDIR}/src/basic_dataparser.o: src/basic_dataparser.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_dataparser.o src/basic_dataparser.cpp

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

${OBJECTDIR}/src/basic_gfx_serial.o: src/basic_gfx_serial.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_gfx_serial.o src/basic_gfx_serial.cpp

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

${OBJECTDIR}/src/basic_interpreter_matrix.o: src/basic_interpreter_matrix.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -Wall -DARDUINO=10804 -DARDUINO_ARCH_SAM -DARDUINO_SAM_DUE -DF_CPU=84000000 -DUSBCON -DUSB_MANUFACTURER=\"Arduino\ LLC\" -DUSB_PID=0x003e -DUSB_PRODUCT=\"Arduino\ Due\" -DUSB_VID=0x2341 -D__SAM3X8E__ -Dprintf=iprintf -I/opt/Arduino/sam/variants/arduino_due_x -I/opt/Arduino/sam/cores/arduino -I/opt/Arduino/sam/system/CMSIS/Device/ATMEL -I/opt/Arduino/sam/system/CMSIS/CMSIS/Include -I/opt/Arduino/sam/system/libsam -Iinclude -I../../libarduinoext/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/basic_interpreter_matrix.o src/basic_interpreter_matrix.cpp

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

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../../libarduinodue && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
