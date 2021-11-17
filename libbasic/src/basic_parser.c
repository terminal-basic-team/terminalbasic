/*
 * This file is part of Terminal-BASIC: a lightweight BASIC-like language
 * interpreter.
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019-2021 Terminal-BASIC team
 *     <https://github.com/terminal-basic-team>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "basic_parser.h"

BOOLEAN
basic_parser_fidentifier(basic_parser_context_t* self, char *idName)
{
/*	if ((_lexer.getToken() >= Token::INTEGER_IDENT) &&
	    (_lexer.getToken() <= Token::BOOL_IDENT)) {
		strncpy(idName, _lexer.id(), IDSIZE);
		idName[IDSIZE-1] = '\0';
		return true;
	} else*/
	return FALSE;
}
