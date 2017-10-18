/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:50:48 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/18 12:42:46 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*des;

	des = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		des[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
