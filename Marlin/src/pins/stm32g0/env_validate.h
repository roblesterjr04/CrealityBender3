/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2023 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
<<<<<<< HEAD
#pragma once
=======
#ifndef ENV_VALIDATE_H
#define ENV_VALIDATE_H
>>>>>>> bugfix-2.1.x

#if NOT_TARGET(STM32G0xx) || NOT_TARGET(STM32G0B1xx)
  #error "Oops! Select an STM32G0 board in 'Tools > Board.'"
#endif
<<<<<<< HEAD
=======

#endif
>>>>>>> bugfix-2.1.x
