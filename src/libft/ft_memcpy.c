/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:31:15 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 14:53:25 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  memcpy() function copies n bytes 
from memory area src to memory area dest. 
The memory areas must not overlap. 
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*srce;
	size_t				i;

	if (!src || !dest)
		return (dest);
	else
	{
		dst = dest;
		srce = src;
		i = 0;
		while (i < n)
		{
			dst[i] = srce[i];
			i++;
		}
		return (dest);
	}
}
