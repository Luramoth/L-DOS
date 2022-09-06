.extern kernel_main ; declare main kernal function in kernel.c

.global start ; tells the linker that this bit of code is acsessable outside of the assembly file

.set MB_MAGIC, 0x1BADB002 ; "magic" constant that tells grub where the kernel is
.set MB_FLAGS, (1 << 0) | (1 << 1) ; tell grub to load modules on page boundaries and provide a memory map

.set MB_CHECKSUM, (0 - (MB_MAGIC + MB_FLAGS)) ; finally calculate a checksum that includes all previous values

; multiboot header
.section .multiboot
	.align 4 ; make following data allign on a multiple of 4 bytes

	; use the previously calculated constants and put them into the executable
	.long MB_MAGIC
	.long MB_FLAGS
	; use the checksum
	.long MB_CHECKSUM

; initialise data to 0's when kernel is loaded
.section .bss
	;create stack for C code to run
	.align 16
	stack_bottom:
		.skip 4096 ; reserve a 4096 byte stack (4kb)
	stack_top:

; assembly code that runs when the kernel loads
.section .text
	start:
		mov $stack_top, %esp ; move pointer to the top of the stack

		call kernel_main ; C is now running ande the main function is called

		; if the kernel returns for some reason, hang the CPU
		hang:
			cli ; dissable CPU interupts
			hlt ; halt the CPU
			jmp hang ; if it dident work, try again
