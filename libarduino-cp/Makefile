# Path to arduino IDE
ARDUINO_PATH=/opt/arduino-1.6.13
# toolchain path
TOOLS=${ARDUINO_PATH}/hardware/tools/avr/bin
# toolchain tools prefix
TOOLS_PREFIX=avr-
# C compiler
CC=${TOOLS}/${TOOLS_PREFIX}gcc
# C++ compiler
CXX=${TOOLS}/${TOOLS_PREFIX}g++
# C preprocessor
CPP=${TOOLS}/${TOOLS_PREFIX}cpp
# Archiver
AR=${TOOLS}/${TOOLS_PREFIX}gcc-ar
# Ranlib
RANLIB=${TOOLS}/${TOOLS_PREFIX}gcc-ranlib
# Arduino internal libs sources
INTERNAL_LIBS_SOURCES=${ARDUINO_PATH}/hardware/arduino/avr
# Arduino core library
CORE_LIB_PATH=${INTERNAL_LIBS_SOURCES}/cores/arduino
# Internal libraries
INT_LIBS_PATH=${INTERNAL_LIBS_SOURCES}/libraries
# Internal libraries
INT_LIBS=SoftwareSerial SPI

COMPILE_OPTS=-mmcu=atmega2560 -Os -Wall -Wextra -ffunction-sections -fdata-sections -MMD -MP -MF -flto
C_COMPILE_OPTS=$(COMPILE_OPTS) -std=gnu11
CXX_COMPILE_OPTS=$(COMPILE_OPTS) -fno-rtti -fpermissive -fno-exceptions -fno-threadsafe-statics -std=gnu++11

DEFINES=-DARDUINO=10613 -DARDUINO_ARCH_AVR -DF_CPU=16000000L -DARDUINO_AVR_MEGA2560
INCLUDES=-I$(MAIN_LIB) -I$(LIB_SOURCES)/variants/mega
CFLAGS=$(DEFINES) $(INCLUDES) $(C_COMPILE_OPTS)
CXXFLAGS=$(DEFINES) $(INCLUDES) $(CXX_COMPILE_OPTS)

OBJDIR=obj
OBJECTS=${OBJDIR}/CDC.cpp.o \
	${OBJDIR}/HardwareSerial.cpp.o \
	${OBJDIR}/HardwareSerial0.cpp.o \
	${OBJDIR}/HardwareSerial1.cpp.o \
	${OBJDIR}/HardwareSerial2.cpp.o \
	${OBJDIR}/HardwareSerial3.cpp.o \
	${OBJDIR}/IPAddress.cpp.o \
	${OBJDIR}/PluggableUSB.cpp.o \
	${OBJDIR}/Print.cpp.o \
	${OBJDIR}/Stream.cpp.o \
	${OBJDIR}/Tone.cpp.o \
	${OBJDIR}/USBCore.cpp.o \
	${OBJDIR}/WInterrupts.c.o \
	${OBJDIR}/WMath.cpp.o \
	${OBJDIR}/WString.cpp.o \
	${OBJDIR}/abi.cpp.o \
	${OBJDIR}/hooks.c.o \
	${OBJDIR}/main.cpp.o \
	${OBJDIR}/new.cpp.o \
	${OBJDIR}/wiring.c.o \
	${OBJDIR}/wiring_analog.c.o \
	${OBJDIR}/wiring_digital.c.o \
	${OBJDIR}/wiring_pulse.c.o \
	${OBJDIR}/wiring_pulse.s.o \
	${OBJDIR}/wiring_shift.c.o

ARDUINO_OBJECTS=${OBJDIR}/ARDUINO/SoftwareSerial.cpp.o
SPI_OBJECTS=${OBJDIR}/ARDUINO/SPI.cpp.o

all: dirs ${OBJECTS} ${ARDUINO_OBJECTS} ${SPI_OBJECTS}
	${AR} -rv libarduino.a ${OBJECTS} ${ARDUINO_OBJECTS} ${SPI_OBJECTS}
	${RANLIB} libarduino.a

app: all entry.cpp
	$(CXX) $(CXXFLAGS) -c -o entry.cpp.o -include Arduino.h entry.cpp
	$(CXX) $(CXXFLAGS) -O3 -S -o entry.cpp.s -include Arduino.h entry.cpp
	$(CXX) $(CXXFLAGS) -fuse-linker-plugin -mrelax -Wl,--gc-sections entry.cpp.o libarduino.a -mmcu=atmega128a

dirs:
	mkdir -p ${OBJDIR}/ARDUINO

${OBJDIR}/%.cpp.o : ${MAIN_LIB}/%.cpp
	${CXX} $(CXXFLAGS) -c -o $@ $<

${OBJDIR}/%.c.o : ${MAIN_LIB}/%.c
	${CC} $(CFLAGS) -c -o $@ $<

${OBJDIR}/%.s.o : ${MAIN_LIB}/%.S
	${CC} $(CFLAGS) -c -x assembler-with-cpp -o $@ $<

${OBJDIR}/ARDUINO/SoftwareSerial.cpp.o : ${INT_LIB}/SoftwareSerial/src/SoftwareSerial.cpp
	${CXX} $(CFLAGS) -I${INT_LIB}/SoftwareSerial/src/ -c -o $@ $<

${OBJDIR}/ARDUINO/SoftwareSerial.cpp.o : ${INT_LIB}/SoftwareSerial/src/SoftwareSerial.cpp
	${CXX} $(CFLAGS) -I${INT_LIB}/SoftwareSerial/src/ -c -o $@ $<

${OBJDIR}/ARDUINO/SPI.cpp.o : ${INT_LIB}/SPI/src/SPI.cpp
	${CXX} $(CFLAGS) -I${INT_LIB}/SPI/src/ -c -o $@ $<

clean:
	rm -rf ${OBJDIR}
	rm -rf libarduino.a
