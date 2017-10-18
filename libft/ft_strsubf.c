/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:51:48 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/01/04 11:52:28 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsubf(char *s, unsigned int start, size_t len)
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
	free(s);
	return (dest);
}
