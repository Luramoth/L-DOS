#include <stdint.h>
#include <stddef.h>
#include "include/limine.h"

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

//vars
struct limine_terminal  *terminal;

static volatile struct limine_terminal_request terminal_request = {
	.id = LIMINE_TERMINAL_REQUEST,
	.revision = 0
};

static void done(void){
	for(;;){
		__asm__("hlt");
	}
}

// function that initialises the terminal
void init_term(){
	// make sure we actually have a terminal
	if (terminal_request.response == NULL
	|| terminal_request.response->terminal_count < 1){
		done();
	}

	// call the limine terminal to print some stuff
	// by default the terminal is 113 columns and 49 rows
	terminal = terminal_request.response->terminals[0];
}
 // function that determines the length of a string
size_t strlen(const char *str){
	size_t len = 0;
	while(str[len])
		len ++;
	return len;
}

	terminal_request.response->write(terminal, "Hello, World!\n", 14);
	terminal_request.response->write(terminal, "Kernel initialised\n", 19);

	terminal_request.response->write(terminal, "@\n", 2);
	terminal_request.response->write(terminal, "@@@\n", 4);
	terminal_request.response->write(terminal, "@@@@@,\n", 7);
	terminal_request.response->write(terminal, "@@@@@@@@\n", 9);
	terminal_request.response->write(terminal, "@@@@@@@@@@@\n", 12);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/ \n", 14);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/ \n", 14);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/ \n", 14);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/ \n", 14);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/ \n", 14);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/ \n", 14);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@@@@@@@@@@@@@@@#           @@@@@@@@@@@@@@@@@@@@@@\n", 112);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@@@@@@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@&        @@@@@@@@@(       @@@@@@@@@@      (@@@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@                 ", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@                 ", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@                 ", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@@##########      ", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(        @@@@@@@@@@@@@@@@@@@@@@@@ ", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(          @@@@@@@@@@@@@@@@@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                        &@@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@/   @@@@@@@@@                                               @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@@@  @@@@@@@@@  (((((((((((((((((((((((((((((((((((((((((((  @@@@@@@@( ((((((((((((            @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@@@  @@@@@@@@@  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  @@@@@@@@( %%%%%%%%%%%%%%          @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@@@  @@@@@@@@@  ###########################################  @@@@@@@@( #################       @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@@@  @@@@@@@@@  (((((((((((((((((((((((((((((((((((((((((((  @@@@@@@@( (((((((((((((((((((     @@@@@@@@", 113);
	terminal_request.response->write(terminal, "@@@@@@@@@@@@@  @@@@@@@@@  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  @@@@@@@@( &&&&&&&&&&&&&&&&&&&&&&  @@@@@@@@", 113);
	terminal_request.response->write(terminal, "               @@@@@@@@@                                               @@@@@@@@(                         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "               @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "               @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "               @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@         @@@@@@@@", 113);
	terminal_request.response->write(terminal, "               @@@@@@@@@           @@@@@@@@@        @@@@@@@@@          @@@@@@@@(       @@@@@@@@@(       @@@@@@@@@", 113);
	terminal_request.response->write(terminal, "               @@@@@@@@@@@@@@@@@@@@@@@@@@@@/        (@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@", 113);
	terminal_request.response->write(terminal, "               @@@@@@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@@@@@@@@@@@@@@@%           @@@@@@@@@@@@@@@@@@@@@@& ", 113);
	terminal_request.response->write(terminal, "\n", 1);
	terminal_request.response->write(terminal, "Welcome to LDOS!\n", 17);

	//finished, now hang
	done();
}