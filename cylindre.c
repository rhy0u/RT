/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:39:35 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/18 04:05:18 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		ft_equa_cyl(t_ray r, t_obj *s)
{
	float	delta;

	s->a = r.dir.y * r.dir.y + r.dir.z * r.dir.z;
	s->b = 2 * (r.dir.y * (r.eye.y - s->pos.y) + r.dir.z *
			(r.eye.z - s->pos.z));
	s->c = (r.eye.y - s->pos.y) * (r.eye.y - s->pos.y) + (r.eye.z - s->pos.z)
		* (r.eye.z - s->pos.z) - s->radius * s->radius;
	delta = s->b * s->b - 4 * s->a * s->c;
	if (delta < 0)
		return (0);
	s->t1 = (-s->b + sqrt(delta)) / (2 * s->a);
	s->t2 = (-s->b - sqrt(delta)) / (2 * s->a);
	s->t = (s->t1 < s->t2) ? s->t1 : s->t2;
	if (s->cutonoff == 1)
		ft_cut(r, s);
	return (1);
}

int			ft_cylindre(t_ray ray, t_obj *s)
{
	t_ray	r;

	r = ray_virt(ray, s);
	if (ft_equa_cyl(r, s) == 0)
	{
		s->t = LIM;
		return (0);
	}
	s->v = ft_vect(1, 0, 0);
	s->inter = ft_add_vec(r.eye, ft_mul_vec_scal(r.dir, s->t));
	if ((s->cutonoff == 1) && (s->tcut > s->t1 && s->tcut < s->t2))
		s->normal_inter = ft_mul_vec_scal(s->cutnorm, -1);
	else
		s->normal_inter = ft_mul_vec_scal(ft_sub_vec(ft_sub_vec(s->inter,
		s->pos), ft_mul_vec(ft_mul_vec(ft_sub_vec(s->inter, s->pos),
		s->v), s->v)), 1 / s->radius);
	ft_normal(&s->normal_inter);
	s->normal_inter = rot_all_inv(s->normal_inter, s->rot.x, s->rot.y,
			s->rot.z);
	s->inter = ft_add_vec(ray.eye, ft_mul_vec_scal(ray.dir, s->t));
	return (1);
}
