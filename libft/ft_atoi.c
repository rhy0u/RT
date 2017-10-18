/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:05:43 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/11/09 16:26:22 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int res;
	int nb;

	i = 0;
	nb = 0;
	res = 0;
	while (str[i] >= 0 && str[i] <= 32)
		i++;
	if (str[i] == '-')
		nb = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (nb == 1)
		return (-res);
	else
		return (res);
}
