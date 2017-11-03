/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 05:02:02 by akerkeb           #+#    #+#             */
/*   Updated: 2017/11/03 05:02:08 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_damier(t_ray ray, t_obj *obj)
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
		obj->inter = ft_add_vec(ray.eye, ft_scal(ray.dir, obj->t));
		if (ft_dot(den))
			obj->normal_inter = obj->n;
		else
			obj->normal_inter = ft_scal(obj->n, -1);
		ft_normal(&obj->normal_inter);
		obj->normal_inter.x += sin(obj->inter.x / 2) * obj->vague;
	}
	return (1);
}

t_xyz	ft_damcolor(t_obj *s)
{
	int		x;
	int		z;
	t_xyz	res;

	x = (int)fabs(s->inter.x);
	z = (int)fabs(s->inter.z);
	if (s->inter.x < 0)
		x += 10;
	if (s->inter.z < 0)
		z += 10;
	if (x % 20 < 10)
	{
		if (z % 20 < 10)
			res = (z > 0) ? ft_vect(200, 200, 200) : ft_vect(50, 50, 50);
		else
			res = (z > 0) ? ft_vect(50, 50, 50) : ft_vect(200, 200, 200);
	}
	else
	{
		if (z % 20 < 10)
			res = (z > 0) ? ft_vect(50, 50, 50) : ft_vect(200, 200, 200);
		else
			res = (z > 0) ? ft_vect(200, 200, 200) : ft_vect(50, 50, 50);
	}
	return (res);
}
