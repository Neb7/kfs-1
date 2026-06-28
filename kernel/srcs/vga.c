/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:22:40 by benpicar          #+#    #+#             */
/*   Updated: 2026/06/28 16:43:39 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vga.h"
#include "kernel.h"

t_vga	g_screens[2];
int		g_cur = 0;

void	switch_screen(int screen)
{
	if (screen < 0 || screen > 1)
		return;
	g_cur = screen;
	ft_memcpy(vga, g_screens[screen].lines, sizeof(g_screens[screen].lines));
	update_cursor();
}

void	scroll()
{
	t_vga *vga_cur = &g_screens[g_cur];

	ft_memmove(vga_cur->lines[0], vga_cur->lines[1], sizeof(vga_cur->lines)
		- sizeof(vga_cur->lines[0]));
	vga_cur->cursor_y--;
	ft_bzero(vga_cur->lines[24], sizeof(vga_cur->lines[24]));
	ft_memcpy(vga, g_screens[g_cur].lines, sizeof(g_screens[g_cur].lines));
	update_cursor();
}
