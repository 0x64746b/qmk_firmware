/* Copyright 2020 illness072
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#pragma once

// place overrides here

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 192
#define TAPPING_TERM_SFT 160

// place overrides here
#ifdef OLED_DRIVER_ENABLE
#define OLED_FONT_H "keymaps/default/glcdfont.c"
#endif
