#include <stdint.h>
#include <stddef.h>
#include "include/limine.h"

static volatile struct limine_terminal_request terminal_request = {
	.id = LIMINE_TERMINAL_REQUEST,
	.revision = 0
};

static void done(void){
	for(;;){
		__asm__("hlt");
	}
}

// kernel entry point
void _start(void){
	// make sure we actually have a terminal
	if (terminal_request.response == NULL
	|| terminal_request.response->terminal_count < 1){
		done();
	}

	// call the limine terminal to print some stuff
	// by default the terminal is 113 columns and 48 rows
	struct limine_terminal  *terminal = terminal_request.response->terminals[0];

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