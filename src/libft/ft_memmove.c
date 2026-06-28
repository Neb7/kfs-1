/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:47:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 14:53:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies n bytes from memory area src to memory area dest.  
The memory areas may overlap: copying takes place 
as though the bytes in src are first copied 
from the end so there is no overlapping between src or dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest || !src)
		return (dest);
	else
	{
		d = dest;
		s = src;
		if (d > s && d < s + n)
		{
			d = d + n;
			s = s + n;
			while (n--)
				*(--d) = *(--s);
		}
		else
		{
			while (n--)
				*d++ = *s++;
		}
		return (dest);
	}
}
