/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:08:12 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/31 01:40:07 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_xyz		get_xyz(char *str)
{
	t_xyz	o;
	int		i;

	i = 0;
	while (isdigit(str[i]) == 0 && str[i] != '-')
		i++;
	o.x = ft_atoi(&str[i]);
	while (str[i] != ' ')
		i++;
	i++;
	o.y = ft_atoi(&str[i]);
	while (str[i] != ' ')
		i++;
	i++;
	o.z = ft_atoi(&str[i]);
	return (o);
}

t_xyz		get_pos(char *str, t_xyz trans)
{
	t_xyz	o;
	int		i;

	i = 0;
	(void)trans;
	while (isdigit(str[i]) == 0 && str[i] != '-')
		i++;
	o.x = ft_atoi(&str[i]) + trans.x;
	while (str[i] != ' ')
		i++;
	i++;
	o.y = ft_atoi(&str[i]) + trans.y;
	while (str[i] != ' ')
		i++;
	i++;
	o.z = ft_atoi(&str[i]) + trans.z;
	return (o);
}

float		get_radius(char *str)
{
	double	r;
	int		i;

	i = 0;
	while (isdigit(str[i]) == 0 && str[i] != '-')
		i++;
	r = ft_atoi(&str[i]);
	return (r);
}

float		get_float(char *str)
{
	float	f;
	int		i;

	i = 0;
	while (isdigit(str[i]) == 0 && str[i] != '-')
		i++;
	f = ft_atoi(&str[i]) / (float)100;
	return (f);
}
