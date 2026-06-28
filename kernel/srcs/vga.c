/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:22:40 by benpicar          #+#    #+#             */
/*   Updated: 2026/06/28 16:24:49 by benpicar         ###   ########.fr       */
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
	ft_memcpy(vga, g_screens[screen].lines, g_screens[screen].cursor_y * 80
			* g_screen_cursor_x * sizeof(uint16_t));
	update_cursor();
}

// t_vga	g_vga[2] = {{
// 		.cursor_x = 0,
// 		.cursor_y = 0,
// 		.lines = {{0}},
// 	},
// 	{
// 		.cursor_x = 0,
// 		.cursor_y = 0,
// 		.lines = {{0}},
// 	}
// };
