/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:07:56 by benpicar          #+#    #+#             */
/*   Updated: 2026/06/28 15:26:11 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VGA_H
# define VGA_H

typedef struct	s_vga
{
	uint16_t		cursor_x;
	uint16_t		cursor_y;
	char			lines[80][25];
	const uint16_t	*vga;
}	t_vga;

extern t_vga	g_vga;

#endif
