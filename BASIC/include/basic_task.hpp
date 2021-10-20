/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019,2021 Terminal-BASIC team
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

#ifndef BASIC_TASK_HPP
#define BASIC_TASK_HPP

#include "basic.hpp"

#if CONF_USE_EXTMEMFS
#include "basic_extmemfs.hpp"
#endif

#if USEMATH
#include "basic_math.hpp"
#endif

#if CONF_MODULE_ARDUINOIO
#include "basic_arduinoio.hpp"
#endif

#if USE_GFX
#include "basic_gfx.hpp"
#endif

#include "basic_interpreter.hpp"
#include "HALProxyStream.hpp"

class Task
{
protected:
	
	Task() = default;
	
public:
	
	virtual void init() = 0;
	virtual void step() = 0;
};

namespace BASIC
{

/**
 * @brief Terminal-BASIC task
 */
class Task : public ::Task
{
public:
	
	explicit Task(const char*);
	
	void init() override;
	
	void step() override;
	
private:
	
	BASIC::HALProxyStream m_halproxyStream;
	
#if CONF_MODULE_ARDUINOIO
	ArduinoIO m_arduinoio;
#endif
	
#if USEMATH
	Math m_math;
#endif
	
#if USE_GFX
	GFXModule m_gfx;
#endif
	
#if CONF_USE_EXTMEMFS
	ExtmemFSModule m_sdfs;
#endif
	
	// Interpreter object
	Interpreter m_interpreter;
};

} // namespace BASIC

#endif // BASIC_TASK_HPP
