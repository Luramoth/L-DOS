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
	struct limine_terminal *terminal = terminal_request.response->terminals[0];

	terminal_request.response->write(terminal, "Hello, World!", 11);

	//finished, now hang
	done();
}