#ifndef BASIC_LEXER_HPP
#define BASIC_LEXER_HPP

#include "basic_lexer.h"

namespace BASIC
{

class Lexer
{
public:
	
	void init(const char*);
	
	const basic_lexer_context_t &context() const { return m_context; }
	
	basic_lexer_context_t &context() { return m_context; }
	
private:
	
	basic_lexer_context_t m_context;
};

} // namespace BASIC

#endif /* BASIC_LEXER_HPP */

