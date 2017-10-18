/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:18:10 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/18 12:40:34 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)dest;
	i = 0;
	if (n == 0)
		return (dest);
	if (dest <= src)
		while (i < n)
		{
			p[i] = ((unsigned char *)src)[i];
			i++;
		}
	else
	{
		i = n - 1;
		while (i > 0)
		{
			p[i] = ((unsigned char *)src)[i];
			i--;
		}
		p[i] = ((unsigned char *)src)[i];
	}
	return (dest);
}
