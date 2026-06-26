BITS 32

section .multiboot
align 4

dd 0x1BADB002
dd 0
dd -(0x1BADB002)

section .text

global start
global keyboard_stub
extern kernel_main
extern keyboard_handler

start:
    cli

    call kernel_main

.loop:
    hlt
    jmp .loop

keyboard_stub:
    pusha              ; sauvegarde eax, ecx, edx, ebx, esp, ebp, esi, edi
    call keyboard_handler
    popa               ; restaure les registres
    iret               ; retour d'interruption (pas ret !)