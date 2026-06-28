/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:28:15 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 14:53:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Fills area of memory from *s with char c for n bytes. (bzero with extra step)
void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	long long	c8;

	i = -1;
	c8 = 0;
	while (++i < sizeof(long long))
		c8 = c8 | (long long)(unsigned char)c << sizeof(long long) * i;
	i = 0;
	while (n > sizeof(long long))
	{
		((long long *)s)[i] = c8;
		i++;
		n = n - sizeof(long long);
	}
	i = i * sizeof(long long);
	while (n > 0)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}
