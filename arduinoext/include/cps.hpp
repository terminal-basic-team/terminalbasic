/****************************************************************************
    This file is part of scccoduino.

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

#ifndef CPS_HPP
#define CPS_HPP

#if __cplusplus <  201103L
#error This file requires C++11-able compiler
#endif

#define CPS_PACKED __attribute__ ((__packed__))

#define CPS_NOTCOPYABLE(ClassName)        \
private:                                  \
  ClassName(const ClassName&) = delete;   \
  ClassName(ClassName&&) = delete;        \
  ClassName &operator =(const ClassName&) = delete;

#define CPS_STATIC(ClassName)        \
private:                             \
  ClassName() = delete;

#define Package(ClassName) class ClassName final

#define CPS_PACKAGE(ClassName) \
  CPS_STATIC(ClassName) CPS_NOTCOPYABLE(ClassName)

#define Interface (ClassName) class ClassName

#define CPS_INTERFACE (ClassName) \
public: \
  virtual ~ClassName() = default; \
protected: \
  ClassName() = default; \
  CPS_NOTCOPYABLE(ClassName)

#endif //CPS_HPP

