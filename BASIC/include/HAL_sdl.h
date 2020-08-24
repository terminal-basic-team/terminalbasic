/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019,2020 Terminal-BASIC team
 *     <https://bitbucket.org/%7Bf50d6fee-8627-4ce4-848d-829168eedae5%7D/>
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

/**
 * @brief Configuration for the SDL2 HAL implementation
 */

#ifndef HAL_SDL_H
#define HAL_SDL_H

#include "HAL.h"

#if HAL_GFX

/*
 * SDL2 HAL_GFX implementation
 */
#define HAL_SDL_GFX 1

#if HAL_SDL_GFX

/**
 * Width of the SDL window
 */
#define HAL_SDL_WIDTH 640
/**
 * Height of the SDL window
 */
#define HAL_SDL_HEIGHT 480

#endif /* HAL_SDL_GFX */

#endif /* HAL_GFX */

#endif /* HAL_SDL_H */
