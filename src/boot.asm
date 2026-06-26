BITS 32

section .multiboot
align 4

dd 0x1BADB002
dd 0
dd -(0x1BADB002)

section .text

global start
extern kernel_main

start:
    cli

    call kernel_main

.loop:
    hlt
    jmp .loop