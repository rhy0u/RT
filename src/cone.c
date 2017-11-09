/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:23:42 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/11/09 01:02:28 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float				ft_equa_cone(t_ray r, t_obj *s)
{
	float	delta;

	s->a = r.dir.x * r.dir.x + r.dir.y * r.dir.y - r.dir.z * r.dir.z *
		(tan(s->radius) * tan(s->radius));
	s->b = 2 * (r.dir.x * (r.eye.x - s->pos.x) + r.dir.y * (r.eye.y - s->pos.y)
			- r.dir.z * (r.eye.z - s->pos.z) * (tan(s->radius) *
				tan(s->radius)));
	s->c = (r.eye.x - s->pos.x) * (r.eye.x - s->pos.x) + (r.eye.y - s->pos.y)
		* (r.eye.y - s->pos.y) - (r.eye.z - s->pos.z) * (r.eye.z - s->pos.z)
		* (tan(s->radius) * tan(s->radius));
	delta = s->b * s->b - 4 * s->a * s->c;
	if (delta < 0)
		return (0);
	s->t1 = (-s->b + sqrt(delta)) / (2 * s->a);
	s->t2 = (-s->b - sqrt(delta)) / (2 * s->a);
	s->t = (s->t1 < s->t2) ? s->t1 : s->t2;
	if (s->t < 0)
		return (0);
	if (s->cutonoff == 1)
		ft_cut(r, s);
	return (1);
}

int					ft_cone(t_ray ray, t_obj *s)
{
	t_ray r;
	float k;

	s->v = ft_vect(0, 0, 1);
	r = ray_virt(ray, s);
	if (ft_equa_cone(r, s) == 0)
	{
		s->t = LIM;
		return (0);
	}
	k = tan(s->radius / 2.0);
	s->inter = ft_add_vec(r.eye, ft_scal(r.dir, s->t));
	s->normal_inter = ft_sub_vec(ft_sub_vec(s->inter, s->pos), ft_scal(
		ft_mul_vec(s->v, ft_mul_vec(ft_sub_vec(s->inter, s->pos), s->v)),
		(1 + k * k)));
	if ((s->cutonoff == 1) && (s->tcut > s->t1 && s->tcut < s->t2))
	{
		s->inter = ft_add_vec(r.eye, ft_scal(r.dir, s->tcut));
		s->normal_inter = ft_scal(s->cutnorm, -1);
	}
	ft_normal(&s->normal_inter);
	s->normal_inter = rot_all_inv(s->normal_inter, s->rot.x, s->rot.y,
			s->rot.z);
	s->inter = ft_add_vec(ray.eye, ft_scal(ray.dir, s->t));
	return (1);
}
