/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:00:45 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/14 11:14:41 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (!s2[i])
		return ((char *)&s1[i]);
	if (!s1[i])
		return (0);
	while (i < len && s1[i])
	{
		j = 0;
		while (j + i < len && s2[j] && s2[j] == s1[i + j])
		{
			j++;
			if (j == ft_strlen(s2))
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
