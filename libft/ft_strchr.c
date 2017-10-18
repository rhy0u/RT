/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:19:10 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/18 12:46:10 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	if (s[i] == '\0')
		return (NULL);
	while (s[i] != c && s[i])
	{
		i++;
	}
	if (i == len && c != '\0')
		return (NULL);
	return ((char *)&s[i]);
}
