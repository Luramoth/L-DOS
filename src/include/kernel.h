#pragma once

#include <stdint.h>
#include <stddef.h>
#include "limine.h"

/*	LDOS a from scratch custom 64 bit OS
	Copyright (C) 2022  Kayla "Luramoth" Earnest

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>. */

extern struct limine_terminal  *terminal;

static volatile struct limine_terminal_request terminal_request;

static void done(void);

// function that initialises the terminal
void init_term();

 // function that determines the length of a string
size_t strlen(const char *str);

// function that prints a string to the terminal
void print(const char *str);