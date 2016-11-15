/****************************************************************************
    This file is part of scopduino.

    Copyright (C) 2014-2016 by Andrey V. Skvortsov

    Scopduino is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    Casim is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with Casim; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 ****************************************************************************/

#ifndef ARDUINO_LOGGER_HPP
#define ARDUINO_LOGGER_HPP

#include "cps.hpp"
#include "Stream.h"
#include "Arduino.h"

#define ARDUINO_LOG 0

#if ARDUINO_LOG
#define LOG_INIT(T) Logger::init(T)
#define LOG(args...) Logger::log(args)
#define LOG_TRACE LOG(__PRETTY_FUNCTION__)

Package(Logger) {
	public:

	enum class format_t
	{
		bin = 2, dec = 10, oct = 8, hex = 16, endl
	};

	static void init(Stream&);

	template<typename... Args>
	    static void log(const Args&... args)
	{
		_log(args...);
		_instance._stream->println();
	}

	private:

	friend Logger &operator<<(Logger &logger, format_t formaat)
	{
		logger._format = formaat;
		return (logger);
	}
	
	friend Logger &operator<<(Logger &logger, const Printable &p) {
		logger._stream->print(p);
		return (logger);
	}

	friend Logger &operator<<(Logger &logger, uint8_t val) {
		logger._stream->print(val, int(_format));
		return (logger);
	}

	friend Logger &operator<<(Logger &logger, const char* first) {
		logger._stream->print(first);
		return (logger);
	}

	friend Logger &operator<<(Logger &logger, char* first) {
		logger._stream->print(first);
		return (logger);
	}

	template<typename T>
	friend Logger &operator<<(Logger &logger, T * first)
	{
		logger._stream->print(intptr_t(first), 16);
		return (logger);
	}

	template<typename T>
	friend Logger &operator<<(Logger &logger, T first)
	{
		logger._stream->print(first);
		return (logger);
	}

	template<typename T>
	static void _log(T first)
	{
		_instance << first;
	}

	template<typename T, typename... Args>
	static void _log(T first, const Args&... args)
	{
		_log(first);
		_instance._stream->print(" ");
		_log(args...);
	}

	static Logger _instance;

	static format_t _format;

	Stream *_stream;
};
#else
#define LOG_INIT(T)
#define LOG(...)
#define LOG_TRACE

Package(Logger)
{
	public:

	static void init(Stream&)
	{
	}

	template<typename... Args>
	    static void log(const Args&... args)
	{
	}
	private:

	template<typename T>
	friend Logger &operator<<(Logger &logger, T first)
	{
		return (logger);
	}
};
#endif

class ByteArray : public Printable
{
public:
	ByteArray(const uint8_t*, size_t);

	size_t printTo(Print& p) const override;

	const uint8_t *data() const
	{
		return (_data);
	}

	size_t size() const
	{
		return (_size);
	}
private:
	const uint8_t *_data;
	size_t _size;
};

#endif
