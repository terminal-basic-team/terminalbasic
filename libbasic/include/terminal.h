/**
 * @file sgen_terminal.h
 * @brief Simple text terminal interface
 */

#ifndef TERMINAL_H
#define TERMINAL_H

#include <inttypes.h>

#include <sys/cdefs.h>

__BEGIN_DECLS

typedef uint16_t len_t;

extern uint8_t terminal_rows;
extern uint8_t terminal_cols;

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

char terminal_getc();

len_t terminal_putc(char);

/**
 * Terminal update callback (cursor blinking, etc...)
 */
void terminal_update();

__END_DECLS

#endif /* TERMINAL_H */
