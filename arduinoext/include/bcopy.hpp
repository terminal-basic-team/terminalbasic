/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * Copyright (C) 2016  Andrey V. Skvortsov <starling13@mail.ru>
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

#ifndef BCOPY_HPP
#define BCOPY_HPP

#include <stdlib.h>

/**
 * @brief The bcopy() function copies len bytes from buffer src to buffer dst.
 * 
 * The two buffers may overlap. If len is zero, no bytes are copied.
 * @param src source buffer
 * @param dst destination buffer
 * @param len length
 */
extern void
bcopy(const void *src, void *dst, size_t len);

#endif
