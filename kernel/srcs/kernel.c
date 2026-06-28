/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:25:41 by benpicar          #+#    #+#             */
/*   Updated: 2026/06/28 15:53:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"
#include "vga.h"

uint16_t	*vga = (uint16_t*)0xB8000;

char scancode_map[128] = {
	0, 0, '1','2','3','4','5','6','7','8','9','0','-','=', 0, 0,
	'q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
	'a','s','d','f','g','h','j','k','l',';','\'','`', 0,'\\',
	'z','x','c','v','b','n','m',',','.','/', 0, 0, 0,' '
};

void keyboard_handler()
{
	uint8_t scancode = inb(0x60);

	if (scancode & 0x80) {
		// touche relâchée (bit 7 = 1), on ignore pour l'instant
	} else {
		char c = scancode_map[scancode];
		if (c) putchar(c);
	}

	outb(0x20, 0x20);  // EOI — signale la fin de l'interruption au PIC
}

void enable_cursor(uint8_t top, uint8_t bottom)
{
	outb(0x3D4, 10);
	outb(0x3D5, (0x00 << 5) | top);	// bit 5 = 0 → clignotement activé

	outb(0x3D4, 11);
	outb(0x3D5, bottom);
}

void update_cursor()
{
	uint16_t pos = g_vga.cursor_y * 80 + g_vga.cursor_x;
	outb(0x3D4, 14);
	outb(0x3D5, pos >> 8);
	outb(0x3D4, 15);
	outb(0x3D5, pos & 0xFF);
}

void putchar(char c)
{
	t_vga *vga_cur = &g_screens[g_cur];
	
	if (c == '\n')
	{
		vga_cur->cursor_x = 0;
		vga_cur->cursor_y++;
	}
	else
	{
		vga[vga_cur->cursor_y * 80 + vga_cur->cursor_x] = (vga_cur->color << 8) | c;
		vga_cur->lines[vga_cur->cursor_y][vga_cur->cursor_x] = (vga_cur->color << 8) | c;
		vga_cur->cursor_x++;
		if (vga_cur->cursor_x >= 80)
		{   // retour à la ligne automatique
			vga_cur->cursor_x = 0;
			vga_cur->cursor_y++;
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

	ft_bzero(g_screens, sizeof(g_screens) * 2);
	g_screens[0].color = 0x0F;
	g_screens[1].color = 0x24;
	enable_cursor(0, 15);
	putchar('4');
	putchar('2');
	while (1)
	{
	}
}
