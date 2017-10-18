/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:17:14 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/12 12:28:05 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s) - 1;
	while (j > i && (s[j] == ' ' || s[j] == ',' || s[j] == '\n'
				|| s[j] == '\t'))
		j--;
	dest = (char *)malloc(sizeof(*dest) * ((j + 1 - i) + 1));
	if (!dest)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		dest[k++] = s[i];
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
