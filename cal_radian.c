/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_radian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:42:58 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/06/06 00:30:47 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		deg_to_rad(t_xyz *a)
{
	a->x = a->x * M_PI / 180.0;
	a->y = a->y * M_PI / 180.0;
	a->z = a->z * M_PI / 180.0;
}

float		get_radius_rad(char *str)
{
	double	r;
	int		i;

	i = 0;
	while (isdigit(str[i]) == 0 && str[i] != '-')
		i++;
	r = ft_atoi(&str[i]);
	r = r * M_PI / 180.0;
	return (r);
}

t_xyz		get_rad(char *str)
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
	deg_to_rad(&o);
	return (o);
}

t_xyz		rot_all_inv(t_xyz vect, float ax, float ay, float az)
{
	t_xyz v;

	v = vect;
	v = rotation_z(v, -az);
	v = rotation_y(v, -ay);
	v = rotation_x(v, -ax);
	return (v);
}
