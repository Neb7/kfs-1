/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:22:40 by benpicar          #+#    #+#             */
/*   Updated: 2026/06/28 16:38:45 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vga.h"
#include "kernel.h"

t_vga	g_screens[2];
int		g_cur = 0;

void	switch_screen(int screen)
{
	size_t i, j;
	if (screen < 0 || screen > 1)
		return;
	g_cur = screen;
	ft_memcpy(vga, g_screens[screen].lines, sizeof(g_screens[screen].lines));
	update_cursor();
}

void	scroll()
{
	t_vga *vga_cur = &g_screens[g_cur];
	size_t i, j;

	ft_memmove(vga_cur->lines[0], vga_cur->lines[1], sizeof(vga_cur->lines)
		- sizeof(vga_cur->lines[0]));
	vga_cur->cursor_y--;
	ft_memcpy(vga, g_screens[g_cur].lines, sizeof(g_screens[g_cur].lines));
	update_cursor();
}
