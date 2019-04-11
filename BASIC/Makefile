#
#  There exist several targets which are by default empty and which can be 
#  used for execution of your targets. These targets are usually executed 
#  before and after some main targets. They are: 
#
#     .build-pre:              called before 'build' target
#     .build-post:             called after 'build' target
#     .clean-pre:              called before 'clean' target
#     .clean-post:             called after 'clean' target
#     .clobber-pre:            called before 'clobber' target
#     .clobber-post:           called after 'clobber' target
#     .all-pre:                called before 'all' target
#     .all-post:               called after 'all' target
#     .help-pre:               called before 'help' target
#     .help-post:              called after 'help' target
#
#  Targets beginning with '.' are not intended to be called on their own.
#
#  Main targets can be executed directly, and they are:
#  
#     build                    build a specific configuration
#     clean                    remove built files from a configuration
#     clobber                  remove all built files
#     all                      build all configurations
#     help                     print help mesage
#  
#  Targets .build-impl, .clean-impl, .clobber-impl, .all-impl, and
#  .help-impl are implemented in nbproject/makefile-impl.mk.
#
#  Available make variables:
#
#     CND_BASEDIR                base directory for relative paths
#     CND_DISTDIR                default top distribution directory (build artifacts)
#     CND_BUILDDIR               default top build directory (object files, ...)
#     CONF                       name of current configuration
#     CND_PLATFORM_${CONF}       platform name (current configuration)
#     CND_ARTIFACT_DIR_${CONF}   directory of build artifact (current configuration)
#     CND_ARTIFACT_NAME_${CONF}  name of build artifact (current configuration)
#     CND_ARTIFACT_PATH_${CONF}  path to build artifact (current configuration)
#     CND_PACKAGE_DIR_${CONF}    directory of package (current configuration)
#     CND_PACKAGE_NAME_${CONF}   name of package (current configuration)
#     CND_PACKAGE_PATH_${CONF}   path to package (current configuration)
#
# NOCDDL

# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin

ARDUINO_PATH=/opt/arduino-1.8.6
TOOLS = ${ARDUINO_PATH}/hardware/tools/avr
AVRDUDE=${TOOLS}/bin/avrdude
OBJCOPY=${TOOLS}/bin/avr-objcopy
SIZE=${TOOLS}/bin/avr-size
AVRDUDE_CONF=${TOOLS}/etc/avrdude.conf
JAVA=/usr/lib/jvm/java-1.8.0-openjdk-i386/bin/java

OBJCOPY_ARM=/opt/Arduino/gcc-arm-none-eabi-4.8.3-2014q1/bin/arm-none-eabi-objcopy
SIZE_ARM=/opt/Arduino/gcc-arm-none-eabi-4.8.3-2014q1/bin/arm-none-eabi-size

BUILD:=$(shell cat "./build-${CONF}")
VERSION:=2.0-rc2-${BUILD}

# build
build: .build-post

.build-pre:
	echo "#define VERSION \"${VERSION}\"" > "./include/version.h"
	echo ${VERSION} > ./version

.build-post: .build-impl copy_${CONF}
	echo $(shell expr ${BUILD} + 1) ; \
	#echo $(shell expr ${BUILD} + 1) > "./build-${CONF}"

# clean
clean: .clean-post

.clean-pre:
# Add your pre 'clean' code here...

.clean-post: .clean-impl
# Add your post 'clean' code here...


# clobber
clobber: .clobber-post

.clobber-pre:
# Add your pre 'clobber' code here...

.clobber-post: .clobber-impl
# Add your post 'clobber' code here...


# all
all: .all-post

.all-pre:
# Add your pre 'all' code here...

.all-post: .all-impl
# Add your post 'all' code here...


# build tests
build-tests: .build-tests-post

.build-tests-pre:
# Add your pre 'build-tests' code here...

.build-tests-post: .build-tests-impl
# Add your post 'build-tests' code here...


# run tests
test: .test-post

.test-pre: build-tests
# Add your pre 'test' code here...

.test-post: .test-impl
# Add your post 'test' code here...


# help
help: .help-post

.help-pre:
# Add your pre 'help' code here...

.help-post: .help-impl
# Add your post 'help' code here...

ARCH=""

copy_Debug : ARCH=i686-linux_static-dbg
copy_Debug : copy-pc

copy_Release : ARCH=i686-linux_static
copy_Release : copy-pc

copy-pc:
	${CP} "${CND_ARTIFACT_PATH_${CONF}}" "${CND_ARTIFACT_PATH_${CONF}}_${VERSION}_${ARCH}"

copy_Arduino_nano328 : ARCH=arduinoNANO
copy_Arduino_nano328 : UCARCH=atmega328p
copy_Arduino_nano328 : copy

copy_Arduino_pro328 : ARCH=arduinoPRO
copy_Arduino_pro328 : UCARCH=atmega328p
copy_Arduino_pro328 : copy
	
copy_Atmega_128a : ARCH=arduino
copy_Atmega_128a : UCARCH=atmega128a
copy_Atmega_128a : copy

copy_Arduino_nano168 : ARCH=arduinoNANO
copy_Arduino_nano168 : UCARCH=atmega168
copy_Arduino_nano168 : copy
	
copy_Arduino_nano168p : ARCH=arduinoNANO
copy_Arduino_nano168p : UCARCH=atmega168p
copy_Arduino_nano168p : copy

copy_Arduino_mega2560 : ARCH=arduinoMEGA
copy_Arduino_mega2560 : UCARCH=atmega2560
copy_Arduino_mega2560 : copy

copy_Arduino_mega2560_tvout : ARCH=arduinoMEGA
copy_Arduino_mega2560_tvout : UCARCH=atmega2560
copy_Arduino_mega2560_tvout : copy

copy_Atmega1284 : ARCH=mighty1284
copy_Atmega1284 : UCARCH=atmega1284p
copy_Atmega1284 : copy

copy_Arduino_UNO : ARCH=arduinoUNO
copy_Arduino_UNO : UCARCH=atmega328p
copy_Arduino_UNO : copy
	
copy_Arduino_DUE:
	${OBJCOPY_ARM} "${CND_ARTIFACT_PATH_${CONF}}" \
	    "${CND_ARTIFACT_PATH_${CONF}}_${VERSION}.bin"
	${SIZE_ARM} "${CND_ARTIFACT_PATH_${CONF}}"

program: program_${CONF}

program_Arduino_UNO : ARCH=arduinoUNO
program_Arduino_UNO : UCARCH=atmega328p
program_Arduino_UNO : PROGRAMMER=arduino
program_Arduino_UNO : program_common
	
program_Arduino_nano168 : ARCH=arduinoNANO
program_Arduino_nano168 : UCARCH=atmega168
program_Arduino_nano168 : PROGRAMMER=usbasp
program_Arduino_nano168 : program_common
	
program_Arduino_nano168p : ARCH=arduinoNANO
program_Arduino_nano168p : UCARCH=atmega168p
program_Arduino_nano168p : PROGRAMMER=usbasp
program_Arduino_nano168p : program_common

program_Arduino_mega2560 : ARCH=arduinoMEGA
program_Arduino_mega2560 : UCARCH=atmega2560
program_Arduino_mega2560 : PROGRAMMER=wiring
program_Arduino_mega2560 : program_common
	
program_Arduino_mega2560_tvout : ARCH=arduinoMEGA
program_Arduino_mega2560_tvout : UCARCH=atmega2560
program_Arduino_mega2560_tvout : PROGRAMMER=wiring
program_Arduino_mega2560_tvout : program_common
	
program_Atmega1284 : ARCH=mighty1284
program_Atmega1284 : UCARCH=atmega1284p
program_Atmega1284 : PROGRAMMER=usbasp
program_Atmega1284 : program_common

copy:
	${OBJCOPY} -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load \
	  --no-change-warnings --change-section-lma .eeprom=0 \
	  "${CND_ARTIFACT_PATH_${CONF}}" "${CND_ARTIFACT_PATH_${CONF}}_${VERSION}_${ARCH}-${UCARCH}.eep"
	${OBJCOPY} -O ihex -R .eeprom "${CND_ARTIFACT_PATH_${CONF}}" \
	  "${CND_ARTIFACT_PATH_${CONF}}_${VERSION}_${ARCH}-${UCARCH}.hex"
	${OBJCOPY} -O binary -R .eeprom "${CND_ARTIFACT_PATH_${CONF}}" \
	  "${CND_ARTIFACT_PATH_${CONF}}_${VERSION}_${ARCH}-${UCARCH}.bin"
	${SIZE} -C --mcu=${UCARCH} ${CND_ARTIFACT_PATH_${CONF}}

program_common:
	#${AVRDUDE} -D -C ${AVRDUDE_CONF} -v -c ${PROGRAMMER} -p ${UCARCH} \
	#  -P /dev/ttyACM0 -b115200 -U flash:w:"${CND_ARTIFACT_PATH_${CONF}}_${VERSION}_${ARCH}-${UCARCH}.hex":i
	${AVRDUDE} -C ${AVRDUDE_CONF} -v -c ${PROGRAMMER} -p ${UCARCH} \
	  -P /dev/ttyUSB0 -b115200 -D -U flash:w:"${CND_ARTIFACT_PATH_${CONF}}_${VERSION}_${ARCH}-${UCARCH}.hex":i
	#${AVRDUDE} -C ${AVRDUDE_CONF} -v -c ${PROGRAMMER} -p ${UCARCH} \
	#  -U flash:w:"${CND_ARTIFACT_PATH_${CONF}}_${VERSION}_${ARCH}-${UCARCH}.hex":i
	#${AVRDUDE} -C ${AVRDUDE_CONF} -v -c arduino -p m328p -P /dev/ttyUSB0 \
	#-U flash:w:"${CND_ARTIFACT_PATH_${CONF}}_${VERSION}_${ARCH}-${UCARCH}.hex":i
	#${AVRDUDE} -C ${AVRDUDE_CONF} -v -c usbasp -p m328p \
	#-U flash:w:"${CND_BASEDIR}/${CND_ARTIFACT_PATH_${CONF}}.hex":i
	#${AVRDUDE} -C ${AVRDUDE_CONF} -v -c usbasp -p m128 \
	#-U flash:w:"${CND_BASEDIR}/${CND_ARTIFACT_PATH_${CONF}}.hex":i

# include project implementation makefile
include nbproject/Makefile-impl.mk

# include project make variables
include nbproject/Makefile-variables.mk
