#ifndef BASIC_HPP
#define BASIC_HPP

#include <stdio.h>
#include <inttypes.h>

/**
 * @brief SImple BASIC language interpreter package
 */
namespace BASIC
{
// Max size of the program strings and string constants/variables
const uint8_t STRINGSIZE = 72;
// Number of bytes for program text, variables and stack
const size_t PROGSIZE = 256;
// Number of characters in variable name
const uint8_t VARSIZE = 4; 
// integer type
typedef int16_t Integer;
// floating point type
typedef float Real;
}

#endif
