/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:04:25 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/01/05 14:18:45 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[0] == '\0')
		return (NULL);
	if (ft_isascii(c) == 0)
		return (NULL);
	while ((int)i >= 0 && s[i] != c)
	{
		i--;
	}
	if (s[i] != c)
		return (NULL);
	return ((char *)&s[i]);
}
