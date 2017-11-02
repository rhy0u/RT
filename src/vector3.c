/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthouard <pthouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:38:00 by pthouard          #+#    #+#             */
/*   Updated: 2017/10/31 03:40:06 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_xyz		ft_sq_vec(t_xyz a)
{
	t_xyz	res;

	res.x = a.x * a.x;
	res.y = a.y * a.y;
	res.z = a.z * a.z;
	return (res);
}

t_xyz		ft_cross_vec(t_xyz a, t_xyz b)
{
	t_xyz	res;

	res.x = (a.y * b.z) - (a.z * b.y);
	res.y = (a.z * b.x) - (a.x * b.z);
	res.z = (a.x * b.y) - (a.y * b.x);
	return (res);
}

float		ft_dot(t_xyz a)
{
	return (a.x + a.y + a.z);
}

t_xyz		ft_vect(float x, float y, float z)
{
	t_xyz res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

float		ft_mag_vec(t_xyz a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
