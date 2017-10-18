/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:06:08 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/01/05 14:18:19 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (size < ft_strlen(dest))
		return (ft_strlen(src) + size);
	while (i < size && dest[i])
		i++;
	j = 0;
	while (i + j < size - 1 && src[j])
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
