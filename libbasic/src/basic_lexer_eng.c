#include "basic.h"

#include "avr/pgmspace.h"

const uint8_t _basic_lexer_symbolsShift PROGMEM = 0;

const uint8_t _basic_lexer_tokenTable[] PROGMEM = {
	0x80,
	'A', 'N', 'D'+0x80,                // 1
#if USE_DUMP
	'A', 'R', 'R', 'A', 'Y', 'S'+0x80, // 2
#endif
#if USE_SAVE_LOAD
	'C', 'H', 'A', 'I', 'N'+0x80,      // 4
#endif
#if USE_TEXTATTRIBUTES
	'C', 'L', 'S'+0x80,                // 5
#endif
#if USESTOPCONT
	'C', 'O', 'N', 'T'+0x80,           // 6
#endif
#if USE_MATRIX
	'C', 'O', 'N'+0x80,                // 7
#endif
#if USE_DATA
	'D', 'A', 'T', 'A'+0x80,           // 8
#endif
#if USE_DEFFN
	'D', 'E', 'F'+0x80,                // 9
#endif
#if USE_DELAY
	'D', 'E', 'L', 'A', 'Y'+0x80,      // 10
#endif
#if USE_MATRIX
	'D', 'E', 'T'+0x80,                // 11
#endif
	'D', 'I', 'M'+0x80,                // 12
#if USE_DIV_KW
	'D', 'I', 'V'+0x80,                // 13
#endif
#if USE_DOLOOP
	'D', 'O'+0x80,                     // 14
#endif
#if USE_DUMP
	'D', 'U', 'M', 'P'+0x80,           // 15
#endif
	'E', 'N', 'D'+0x80,
	'F', 'A', 'L', 'S', 'E'+0x80,
#if USE_DEFFN
	'F', 'N'+0x80,                     // 18
#endif
	'F', 'O', 'R'+0x80,                // 19
	'G', 'O', 'S', 'U', 'B'+0x80,      // 20
	'G', 'O', 'T', 'O'+0x80,           // 11
#if CONF_SEPARATE_GO_TO
	'G', 'O'+0x80,                     // 12
#endif
#if USE_MATRIX
	'I', 'D', 'N'+0x80,
#endif
	'I', 'F'+0x80,                     // 16
	'I', 'N', 'P', 'U', 'T'+0x80,      // 17
#if USE_MATRIX
	'I', 'N', 'V'+0x80,
#endif
	'L', 'E', 'T'+0x80,
	'L', 'I', 'S', 'T'+0x80,           // 19
#if USE_SAVE_LOAD
	'L', 'O', 'A', 'D'+0x80,           // 20
#endif
#if USE_TEXTATTRIBUTES
	'L', 'O', 'C', 'A', 'T', 'E'+0x80, // 21
#endif
#if USE_DOLOOP
	'L', 'O', 'O', 'P'+0x80,           // 22
#endif
#if USE_MATRIX
	'M', 'A', 'T'+0x80,                // 23
#endif
#if USE_INTEGER_DIV
	'M', 'O', 'D'+0x80,                // 24
#endif
	'N', 'E', 'W'+0x80,                // 21
	'N', 'E', 'X', 'T'+0x80,           // 22
	'N', 'O', 'T'+0x80,
	'O', 'N'+0x80,                     // 23
	'O', 'R'+0x80,
	'P', 'R', 'I', 'N', 'T'+0x80,
#if USE_RANDOM
	'R', 'A', 'N', 'D', 'O', 'M', 'I', 'Z', 'E'+0x80, //26
#endif
#if USE_DATA
	'R', 'E', 'A', 'D'+0x80,           // 27
#endif
	'R', 'E', 'M'+0x80,
#if USE_DATA
	'R', 'E', 'S', 'T', 'O', 'R', 'E'+0x80,
#endif
	'R', 'E', 'T', 'U', 'R', 'N'+0x80,
	'R', 'U', 'N'+0x80,
#if USE_SAVE_LOAD
	'S', 'A', 'V', 'E'+0x80,
#endif
#if CONF_USE_SPC_PRINT_COM
	'S', 'P', 'C'+0x80,
#endif
	'S', 'T', 'E', 'P'+0x80,
#if USESTOPCONT
	'S', 'T', 'O', 'P'+0x80,
#endif
#if USE_TEXTATTRIBUTES
	'T', 'A', 'B'+0x80,
#endif
	'T', 'H', 'E', 'N'+0x80,
	'T', 'O'+0x80,
#if USE_MATRIX
	'T', 'R', 'N'+0x80,
#endif
	'T', 'R', 'U', 'E'+0x80,
#if USE_DUMP
	'V', 'A', 'R', 'S'+0x80,
#endif
	'X', 'O', 'R'+0x80,
#if USE_MATRIX
	'Z', 'E', 'R'+0x80,
#endif
	'\0'
};
