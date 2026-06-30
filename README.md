# KFS-1: A 32-bit Kernel from Scratch

A minimal 32-bit x86 operating system kernel built from the ground up, featuring bare-metal x86 assembly, interrupt handling, and basic I/O capabilities.

## Overview

KFS-1 is an educational OS kernel project that demonstrates core low-level operating system concepts:
- **Bootloader Integration**: GRUB-based multiboot loading
- **Interrupt Handling**: IDT (Interrupt Descriptor Table) setup and interrupt service routines
- **Hardware I/O**: PIC (Programmable Interrupt Controller) initialization and management
- **Display**: VGA text mode support with cursor control
- **Keyboard**: Keyboard input with scancode mapping
- **Standard Library**: Custom C standard library (libft) implemented without external dependencies

## Project Structure

```
.
├── kernel/                   # Kernel source code
│   ├── boot.asm              # 32-bit entry point and boot code
│   ├── includes/
│   │   ├── kernel.h          # Main kernel header
│   │   └── vga.h             # VGA mode definitions
│   ├── libft/                # Helper functions
│   │   ├── libft.h
│   │   └── *.c               # Memory, string, and utility functions
│   └── srcs/
│       ├── kernel.c          # Main kernel code
│       ├── idt.c             # Interrupt Descriptor Table setup
│       ├── pic.c             # PIC initialization
│       ├── vga.c             # VGA driver
│       └── kprintf.c         # Printf helper
├── iso/                      # ISO image configuration
│   └── boot/grub/grub.cfg    # GRUB bootloader config
├── linker.ld                 # Linker script for kernel layout
├── Makefile                  # Build system
└── README.md                 # This file
```

## Building

### Requirements
- GCC with 32-bit support (`gcc-multilib`)
- NASM assembler
- GNU binutils (ld, objcopy)
- GRUB tools (for ISO generation)
- Make

### Compilation

```bash
# Build the kernel binary
make

# Clean build artifacts
make clean

# Generate ISO image
make iso

# make iso and run it
make run
```

The build process:
1. Compiles C source files with `-m32` flag for 32-bit output
2. Assembles boot code with NASM to ELF 32-bit format
3. Links object files using the custom linker script (`linker.ld`)
4. Produces `kernel.bin` and optionally `kfs01.iso`

## Features

### Core Components

**Interrupt Handling (IDT)**
- Interrupt Descriptor Table setup for exception and interrupt handling
- Interrupt service routines for keyboard and other hardware interrupts
- Keyboard scancode mapping

**Hardware Initialization**
- PIC (Programmable Interrupt Controller) configuration
- Interrupt enable/disable management
- Port I/O operations (in/out instructions)

**Display System**
- VGA text mode driver (80x25 characters)
- Cursor positioning and control
- Text output with color support
- Formatted printing (kprintf - kernel printf)

**Custom Standard Library (libft)**
- Memory operations: `memcpy`, `memmove`, `memset`, `memchr`, `memcmp`
- String operations: `strlen`, `strchr`, `strlcpy`, `strlcat`, `strncmp`, `strnstr`
- Character classification: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`
- Character conversion: `toupper`, `tolower`
- Utility functions: `atoi`, `bzero`, `striteri`

## Compilation Flags

| Flag | Purpose |
|------|---------|
| `-m32` | Generate 32-bit code |
| `-fno-builtin` | Disable built-in function optimization |
| `-fno-stack-protector` | Disable stack protection (not available in kernel) |
| `-nostdlib` | Don't link standard library |
| `-nodefaultlibs` | Don't link default libraries |
| `-f elf32` | NASM ELF 32-bit format |
| `-T linker.ld` | Use custom linker script |

## Kernel Memory Layout

The kernel is loaded at **1MB** (0x100000) by the bootloader as defined in `linker.ld`:
- `.text`: Executable code
- `.rodata`: Read-only data
- `.data`: Initialized data
- `.bss`: Uninitialized data

## Multiboot Compliance

The kernel follows the Multiboot specification, allowing it to be loaded by any Multiboot-compliant bootloader (e.g., GRUB).

## Usage

After building:

```bash
# Run with QEMU (if available)
qemu-system-i386 -cdrom kfs01.iso

# Or use any other x86 emulator with Multiboot support
```

## Educational Value

This project is suitable for learning:
- x86 assembly language fundamentals
- Bootloader and boot process
- Interrupt handling mechanisms
- Memory management and paging basics
- Device driver development
- C programming without standard library
- Linker scripts and memory layout
- Build systems (Makefile)

## Author

Benjamin Picard
Veliga Syutkin

---

**Note**: This is a minimal educational kernel. It is not intended for production use or as a complete operating system.

## Video

YouTube V2F: "vas-y, viens, on recode Windows de zéro" https://youtu.be/ELTwwTsR5w8?si=Oijyna7_t4np2Ltq
