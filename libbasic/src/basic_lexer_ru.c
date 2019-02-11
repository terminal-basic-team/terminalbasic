#include "avr/pgmspace.h"
#include "basic_config.h"
#include "basic.h"

#if CONF_LANG == LANG_RU

const uint8_t _basic_lexer_symbolsShift PROGMEM = (uint8_t)('Ä')-'A';

const uint8_t _basic_lexer_tokenTable[] PROGMEM = {
	ASCII_NUL,
	'Ç', 'Ç', 'é', 'Ñ', ASCII_ETX,
	'Ç', 'é', 'á', 'Ç', 'ê', 'Ä', 'í', ASCII_ETX,
	'Ç', 'õ', 'Ç', 'é', 'Ñ', ASCII_ETX,
	'Ö', 'ë', 'ã', 'à', ASCII_ETX,
	'ä', 'é', 'ç', 'Ö', 'ñ', ASCII_ETX,
	'è', 'ì', 'ë', 'ä', ASCII_ETX,
	'è', 'ì', 'ë', 'í', 'ú', ASCII_ETX,
#if USESTOPCONT
	'ë', 'í', 'é', 'è', ASCII_NUL,
#endif
	ASCII_NUL
};

#endif 
