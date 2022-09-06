#include <stddef.h>
#include <stdint.h>

//check if the user is using a gcc cross compiler
#if defined (__linux__)
	#error "this code must be compiled with a cross compiler, learn more at https://wiki.osdev.org/GCC_Cross-Compiler"
#elif !defined (__i386__)
	#error "This code must be compiled with an x86-elf compiler learn more at https://wiki.osdev.org/GCC_Cross-Compiler"
#endif

// the x86 VGA textmode buffer. to display text you have to write to it
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
// by default the VGA textmode has a buffer of 80 columns and 25 rows or 80x25
const int VGA_COLS = 80;
const int VGA_ROWS = 25;

// set the cursor to the top left (0,0)
int term_col = 0;
int term_row = 0;
uint8_t term_color = 0x0F; // black background, white text

// initiate the terminal when called
void term_init(){
	// clear textmode buffer
	for (int col = 0; col < VGA_COLS; col++){
		for (int row = 0; row < VGA_ROWS; row++){
			const size_t index = (VGA_COLS * row) + col;// find index and put it into the buffer

			// every entry in the VGA buffer take the binary form of BBBBFFFFCCCCCCCC
			// B being background color
			// F being foreground color
			// C being the ascii character itself
			vga_buffer[index] = ((uint16_t)term_color << 8) | ' '; // set character to a blank (a space)
		}
	}
}

// this puts a single character to the screen
void term_putc(char c){
	switch (c){
		case '\n':{ // newline characters should start a new row
			term_col = 0;
			term_row ++;
			break;
		}
		default:{ // normal characters should just be displayed like normal and should increment the columns
			const size_t index = (VGA_COLS * term_row) + term_col; // calculate the buffer index
			vga_buffer[index] = ((uint16_t)term_color << 8) | c;
			term_col ++;
			break;
		}
	}

	// if you reach the end of the column then set it to 0 and go down a row
	if (term_col >= VGA_COLS){
		term_col = 0;
		term_row ++;
	}

	// if you reach the very last row then reset back to the very top
	if (term_row >= VGA_COLS){
		term_col = 0;
		term_row = 0;
	}
}

// print whole strings to the screen
void term_print(const char* str){
	for (size_t i = 0; str[i] != '\0'; i++){// keep placing characters until you reach a line terminating character
		term_putc(str[i]);
	}
}

// finally, the kernel's main function
void kernel_main(){
	term_init(); // init terminal now that we are booted

	// time for some messages!
	term_print("Kernel initialised\n");
	term_print("Hello world!\n");
	term_print("Welcome to L-DOS!\n");
}