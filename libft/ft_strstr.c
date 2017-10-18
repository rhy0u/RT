/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:58:22 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/14 11:00:36 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (!s2[i])
		return ((char *)&s1[i]);
	if (!s1[i])
		return (0);
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s2[j] == s1[i + j])
		{
			j++;
			if (j == ft_strlen(s2))
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
