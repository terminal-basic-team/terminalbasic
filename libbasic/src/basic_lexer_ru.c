#include "avr/pgmspace.h"

const uint8_t _basic_lexer_symbolsShift PROGMEM = (uint8_t)('Ä')-'A';

static const uint8_t _basic_lexer_tokenTable[] PROGMEM = {
    'ä', 'é', 'ç', 'Ö', 'ñ'+0x80,
    'è', 'Ö', 'ó', 'Ä', 'í', 'ú'+0x80,
    'è', 'ì', 'ë', 'í', 'ú'+0x80,
    'Ç', 'é', 'á', 'Ç', 'ê', 'Ä', 'í'+0x80,
    '\0'
};
