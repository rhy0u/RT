/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 21:56:39 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/05/12 22:03:21 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_xyz		ft_div_vec(t_xyz a, t_xyz b)
{
	t_xyz	res;

	res.x = a.x / b.x;
	res.y = a.y / b.y;
	res.z = a.z / b.z;
	return (res);
}

t_xyz		ft_sqrt_vec(t_xyz a)
{
	t_xyz	res;

	res.x = sqrt(a.x);
	res.y = sqrt(a.y);
	res.z = sqrt(a.z);
	return (res);
}

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
