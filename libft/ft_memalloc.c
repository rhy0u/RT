/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:43:06 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/18 12:39:17 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)malloc(sizeof(str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (str[i] && i < size)
	{
		str[i] = 0;
		i++;
	}
	str[i] = 0;
	return (str);
}
