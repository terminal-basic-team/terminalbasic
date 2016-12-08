#ifndef ASCII_HPP
#define ASCII_HPP

/**
 * @brief ASCII control characters
 */
enum class ASCII : uint8_t
{
	NUL = 0x00,
	SOH = 0x01,
        EOT = 0x03,
	ENQ = 0x05,
	BEL = 0x07,
        BS  = 0x08,
	HT  = 0x09,
	LF  = 0x0A,
	CR  = 0x0D,
	CAN = 0x18,
	ESC = 0x1B
};

#endif
