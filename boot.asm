; Declare constants for the multiboot header.
MBALIGN  equ  1 << 0            ; align loaded modules on page boundaries
MEMINFO  equ  1 << 1            ; provide memory map
FLAGS    equ  MBALIGN | MEMINFO ; this is the Multiboot 'flag' field
MAGIC    equ  0x1BADB002        ; 'magic number' lets bootloader find the header
CHECKSUM equ -(MAGIC + FLAGS)   ; checksum of above, to prove we are multiboot

; Define our multiboot header
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

; Define our stack
section .bss
align 16
stack_bottom:
resb 16384 ; 16 KiB
stack_top:


section .text
global _start:function (_start.end - _start)
_start:
	; Set stack pointer to top of stack
	mov esp, stack_top

	; Call main kernel function
	extern kernel_main
	call kernel_main

	; If we return, hang infinitely to prevent executing random code
	cli
.hang:	hlt
	jmp .hang
.end: