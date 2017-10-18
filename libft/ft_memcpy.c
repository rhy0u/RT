/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:09:53 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/18 12:39:03 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		p[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}
