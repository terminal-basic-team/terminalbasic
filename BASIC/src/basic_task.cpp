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

#include "basic_task.hpp"

namespace BASIC
{

Task::Task(const char*) :
    m_halproxyStream(0),
    m_interpreter(m_halproxyStream, m_halproxyStream, BASIC::SINGLE_PROGSIZE)
{

#if CONF_MODULE_ARDUINOIO
	m_interpreter.addModule(&m_arduinoio);
#endif
	
#if USE_GFX
	m_interpreter.addModule(&m_gfx);
#endif
	
#if USEMATH
	m_interpreter.addModule(&m_math);
#endif
	
#if CONF_USE_EXTMEMFS
	m_interpreter.setSDFSModule(&m_sdfs);
	m_interpreter.addModule(&m_sdfs);
	
#endif
}

void
Task::init()
{
	m_interpreter.init();
}

void
Task::step()
{
	m_interpreter.step();
}

} // namespace BASIC
