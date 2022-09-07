/* specify entry point for the bootloader is at the assembly start symbol (defined in start.s) */
ENTRY(start)

/* tell the linker where the kernel sections are and where to put the kernel */
SECTIONS {
	/* begin at 1 MB because everythig else is reserved fr other x86 stuff */
	. = 1M;

	/* allign sections at multiples of 4Kb */
	/* put Multiboot header in .rodata section */
	.rodata BLOCK(4K) : ALIGN(4K){
		*(.multiboot)
	}

	/* executable code */
	.text BLOCK(4K) : ALIGN(4K){
		*(.text)
	}

	/* read-only data */
	.rodata BLOCK(4K) : ALIGN(4K){
		*(.rodata)
	}

	/* read-write data (initialised) */
	.data BLOCK(4K) : ALIGN(4K){
		*(.data)
	}

	/* read-write data (uninitialised) and stack */
	.bss BLOCK(4k) : ALIGN(4K){
		*(COMMON)
		*(.bss)
	}
}