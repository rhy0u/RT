/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:31:28 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/18 12:34:24 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			len;
	unsigned char	*p;

	if (n == 0)
		return (NULL);
	p = (unsigned char *)s;
	len = 0;
	while (len < n && p[len] != (unsigned char)c)
		len++;
	if (len >= n)
		return (NULL);
	else
		return ((void *)&p[len]);
}
