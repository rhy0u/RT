/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 05:01:27 by akerkeb           #+#    #+#             */
/*   Updated: 2017/11/03 05:01:29 by akerkeb          ###   ########.fr       */
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
