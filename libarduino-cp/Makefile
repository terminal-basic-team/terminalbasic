ARDUINO_PATH=/opt/arduino-1.6.12
TOOLS=${ARDUINO_PATH}/hardware/tools/avr/bin
TOOLS_PREFIX=avr-
CC=${TOOLS}/${TOOLS_PREFIX}gcc
CXX=${TOOLS}/${TOOLS_PREFIX}g++
CPP=${TOOLS}/${TOOLS_PREFIX}cpp
AR=${TOOLS}/${TOOLS_PREFIX}gcc-ar
RANLIB=${TOOLS}/${TOOLS_PREFIX}gcc-ranlib
LIB_SOURCES=${ARDUINO_PATH}/hardware/arduino/avr
MAIN_LIB=${LIB_SOURCES}/cores/arduino

COMPILE_OPTS=-mmcu=atmega128a -Os -Wall -Wextra -ffunction-sections -fdata-sections -MMD -MP -MF
C_COMPILE_OPTS=$(COMPILE_OPTS) -std=gnu11
CXX_COMPILE_OPTS=$(COMPILE_OPTS) -fno-rtti -fpermissive -fno-exceptions -fno-threadsafe-statics -std=gnu++11

DEFINES=-DARDUINO=10612 -DARDUINO_ARCH_AVR -DF_CPU=8000000L
#-DARDUINO_AVR_MEGA2560
INCLUDES=-I$(MAIN_LIB) -I$(LIB_SOURCES)/variants/atmega64_128
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

all: dirs ${OBJECTS}
	${AR} -rv libarduino.a ${OBJECTS}
	${RANLIB} libarduino.a

app: all entry.cpp
	$(CXX) $(CXXFLAGS) -c -o entry.cpp.o -include Arduino.h entry.cpp
	$(CXX) $(CXXFLAGS) -O3 -S -o entry.cpp.s -include Arduino.h entry.cpp
	$(CXX) $(CXXFLAGS) -fuse-linker-plugin -mrelax -Wl,--gc-sections entry.cpp.o libarduino.a -mmcu=atmega128a

dirs:
	mkdir -p ${OBJDIR}

${OBJDIR}/%.cpp.o : ${MAIN_LIB}/%.cpp
	${CXX} $(CXXFLAGS) -c -o $@ $<

${OBJDIR}/%.c.o : ${MAIN_LIB}/%.c
	${CC} $(CFLAGS) -c -o $@ $<

${OBJDIR}/%.s.o : ${MAIN_LIB}/%.S
	${CC} $(CFLAGS) -c -x assembler-with-cpp -o $@ $<

clean:
	rm -rf ${OBJDIR}
	rm -rf libarduino.a
