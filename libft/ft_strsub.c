/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:46:15 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/12 11:04:54 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	if (!s)
		return (NULL);
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	i = start;
	while (i < len + start && ((char *)s)[i])
	{
		dest[i - start] = ((char *)s)[i];
		i++;
	}
	dest[i - start] = '\0';
	return (dest);
}
