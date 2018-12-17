#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>

#include "sys/cdefs.h"

__BEGIN_DECLS

/**
 * Cursor movement direction
 */
typedef enum
{
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
} direction_t;

/**
 * [Re]initialize terminal component
 */
void terminal_init();
/**
 * @brief Move cursor one position
 * @param direction
 */
void terminal_moveCursor(direction_t);
/**
 * @brief get current cursor position
 * @param line out
 * @param column out
 */
void terminal_cursorPosition(uint8_t*, uint8_t*);

uint16_t terminal_putc(char);

uint16_t terminal_puts(const char*);

uint16_t terminal_putu8(uint8_t);

uint16_t terminal_puts8(int8_t);

uint16_t terminal_putu16(uint16_t);

uint16_t terminal_puts16(int16_t);

uint16_t terminal_putu32(uint32_t);

uint16_t terminal_puts32(int32_t);

uint16_t terminal_putPtr(void*);

uint16_t terminal_putFloat(float);

void terminal_update();

__END_DECLS

#endif /* TERMINAL_H */

