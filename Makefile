NAME		:= kernel.bin
ISO			:= kfs01.ixo

CC			:= gcc
ASM			:= nasm
LD			:= ld

# Flags gcc: 32-bit, sans stdlib, sans dépendances hôte
CFLAGS		:= -m32 -fno-builtin -fno-stack-protector -nostdlib -nodefaultlibs -Wall -Wextra 

# Flag nasm: format ELF 32-bit (obligatory for the linker)
ASMFLAGS 	:= -f elf32

LDFLAGS		:= -m elf_i386 -T linker.ld

SRC_C		:= $(wildcard src/*.c)
SRC_ASM		:= $(wildcard src/*.asm)

OBJ_C		:= $(SRC_C:.c=.o)
OBJ_ASM		:= $(SRC_ASM:.asm=.o)
OBJ			:= $(OBJ_C) $(OBJ_ASM)	# boot.o has to be first

# RULES

all: $(NAME)

# link all .o -> kernel.bin wiht custom linker
$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

# compile .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# compile .asm -> .o
%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

# create .ISO bootable with GRUB
iso: $(NAME)
	cp $(NAME) iso/boot/
	grub-mkrescue -o $(ISO) iso/

# launch in QEMU / KVM
run: iso
	qemu-system-i386 -cdrom $(ISO)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(ISO) iso/boot/$(NAME)

re: fclean all

.PHONY: all iso run clean fclean re
