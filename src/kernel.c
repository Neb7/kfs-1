#include "kernel.h"

int cursor_x = 0;
int cursor_y = 0;
uint16_t *vga = (uint16_t*)0xB8000;

void enable_cursor(uint8_t top, uint8_t bottom)
{
	outb(0x3D4, 10);
	outb(0x3D5, (0x00 << 5) | top);	// bit 5 = 0 → clignotement activé

	outb(0x3D4, 11);
	outb(0x3D5, bottom);
}

void update_cursor()
{
	uint16_t pos = cursor_y * 80 + cursor_x;
	outb(0x3D4, 14);
	outb(0x3D5, pos >> 8);
	outb(0x3D4, 15);
	outb(0x3D5, pos & 0xFF);
}

void putchar(char c)
{
    if (c == '\n')
	{
        cursor_x = 0;
        cursor_y++;
    }
	else
	{
        vga[cursor_y * 80 + cursor_x] = (0x0F << 8) | c;
        cursor_x++;
        if (cursor_x >= 80)
		{   // retour à la ligne automatique
            cursor_x = 0;
            cursor_y++;
        }
    }
    update_cursor();  // ← synchronise le curseur matériel après chaque modif
}

void kernel_main(void)
{
	// uint16_t *vga = (uint16_t*)0xB8000;

	// vga[0] = '4' << 8 | 0x0F;
	// vga[1] = '2' << 8 | 0x0F;
	idt_init();
    pic_init();
    idt_set_gate(33, (uint32_t)keyboard_stub, 0x08, 0x8E);

    __asm__ volatile ("sti");  // active les interruptions

    enable_cursor(0, 15);
    putchar('4');
    putchar('2');
	while (1)
	{
	}
}
