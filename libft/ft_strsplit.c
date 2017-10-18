/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:29:00 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/02/03 16:26:43 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_nbword(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c || s[i + 1] == '\0')
			j++;
		if (s[i] == c && (s[i + 1] == c && s[i + 1]))
			k++;
		i++;
	}
	return (j - k);
}

static size_t	ft_lenword(char const *s, char c)
{
	unsigned int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

static char		*ft_copyword(const char *s, size_t len)
{
	char		*dest;
	unsigned	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(*dest) * len + 1)))
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	w;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	w = ft_nbword(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * w + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (j < w)
	{
		while (s[i] == c && s[i])
			i++;
		tab[j] = ft_copyword(&s[i], ft_lenword(&s[i], c));
		if (!tab[j])
			return (NULL);
		i = i + ft_lenword(&s[i], c);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
