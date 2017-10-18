/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:35:26 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/10 13:55:30 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int		j;
	size_t	i;
	char	*p;

	p = dest;
	i = 0;
	j = 0;
	if (src[0] == '\0')
		return (ft_memset(dest, 0, n));
	while (i < n)
	{
		if (j == 0)
		{
			if (src[i] == '\0')
				j = 1;
			p[i] = src[i];
			i++;
		}
		else
		{
			p[i] = '\0';
			i++;
		}
	}
	return (dest);
}
