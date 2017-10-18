/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:56:56 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/06/06 00:29:03 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_xyz		rotation_x(t_xyz vect, float a)
{
	t_xyz	v;

	v.x = vect.x;
	v.y = vect.y * cos(a) - vect.z * sin(a);
	v.z = vect.y * sin(a) + vect.z * cos(a);
	return (v);
}

t_xyz		rotation_y(t_xyz vect, float a)
{
	t_xyz	v;

	v.x = vect.x * cos(a) + vect.z * sin(a);
	v.y = vect.y;
	v.z = -vect.x * sin(a) + vect.z * cos(a);
	return (v);
}

t_xyz		rotation_z(t_xyz vect, float a)
{
	t_xyz	v;

	v.x = vect.x * cos(a) - vect.y * sin(a);
	v.y = vect.x * sin(a) + vect.y * cos(a);
	v.z = vect.z;
	return (v);
}

t_xyz		rot_all(t_xyz vect, float ax, float ay, float az)
{
	t_xyz v;

	v = vect;
	v = rotation_x(v, ax);
	v = rotation_y(v, ay);
	v = rotation_z(v, az);
	return (v);
}

t_ray		ray_virt(t_ray r, t_obj *obj)
{
	t_xyz	dist;
	t_ray	ray;

	dist = ft_sub_vec(r.eye, obj->pos);
	dist = rot_all(dist, obj->rot.x, obj->rot.y, obj->rot.z);
	ray.eye = ft_add_vec(obj->pos, dist);
	ray.dir = rot_all(r.dir, obj->rot.x, obj->rot.y, obj->rot.z);
	return (ray);
}
