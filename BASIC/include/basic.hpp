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
const size_t STRINGSIZE = 64;
// Number of bytes for program text, variables and stack
const size_t PROGSIZE = 128;
// integer type
typedef int16_t Integer;
}

#endif
