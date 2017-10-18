/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:01:27 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/16 09:30:17 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_len(int n)
{
	unsigned int	len;
	unsigned		nb;

	nb = n;
	len = 1;
	if (n < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	int				len;

	nb = n;
	len = ft_len(n);
	s = (char *)malloc(sizeof(*s) * len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	len--;
	if (n < 0)
		nb = -nb;
	while (len >= 0)
	{
		s[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
