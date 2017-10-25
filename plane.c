/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:23:15 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/25 07:11:14 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_plane(t_ray ray, t_obj *obj)
{
	t_xyz den;
	t_xyz num;

	den = ft_mul_vec(obj->n, ray.dir);
	num = (ft_mul_vec(obj->n, ft_sub_vec(ray.eye, obj->pos)));
	obj->t = -((num.x + num.y + num.z) / (den.x + den.y + den.z));
	if (obj->t < 0)
	{
		obj->t = LIM;
		return (0);
	}
	else
	{
		obj->inter = ft_add_vec(ray.eye, ft_mul_vec_scal(ray.dir, obj->t));
		if (ft_dot(den))
			obj->normal_inter = obj->n;
		else
			obj->normal_inter = ft_mul_vec_scal(obj->n, -1);
		ft_normal(&obj->normal_inter);
		obj->normal_inter.x += sin(obj->inter.x / 2) * obj->vague;
	}
	return (1);
}
