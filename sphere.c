/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:16:10 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/20 01:32:57 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		ft_equa_sphere(t_ray r, t_obj *s)
{
	float	delta;

	s->a = r.dir.x * r.dir.x + r.dir.y * r.dir.y + r.dir.z * r.dir.z;
	s->b = 2 * (r.dir.x * (r.eye.x - s->pos.x) + r.dir.y * (r.eye.y - s->pos.y)
		+ r.dir.z * (r.eye.z - s->pos.z));
	s->c = (r.eye.x - s->pos.x) * (r.eye.x - s->pos.x) + (r.eye.y - s->pos.y)
		* (r.eye.y - s->pos.y) + (r.eye.z - s->pos.z) * (r.eye.z - s->pos.z)
		- s->radius * s->radius;
	delta = s->b * s->b - 4 * s->a * s->c;
	return (delta);
}

static void	ft_sphere_bis(t_obj *s, float delta)
{
	s->t1 = (-s->b + sqrt(delta)) / (2 * s->a);
	s->t2 = (-s->b - sqrt(delta)) / (2 * s->a);
	s->t = (s->t1 < s->t2) ? s->t1 : s->t2;
}

int			ft_sphere(t_ray r, t_obj *s)
{
	float	delta;

	delta = ft_equa_sphere(r, s);
	if (delta < 0)
	{
		s->t = LIM;
		return (0);
	}
	ft_sphere_bis(s, delta);
	if (s->t < 0)
	{
		s->t = LIM;
		return (0);
	}
	if (s->cutonoff == 1)
		ft_cut(r, s);
	s->inter = ft_add_vec(r.eye, ft_mul_vec_scal(r.dir, s->t));
	if ((s->cutonoff == 1) && (s->tcut > s->t1 && s->tcut < s->t2))
		s->normal_inter = ft_mul_vec_scal(s->cutnorm, -1);
	else
		s->normal_inter = ft_mul_vec_scal(ft_sub_vec(s->inter, s->pos),
			1 / s->radius);
	ft_normal(&s->normal_inter);
	return (1);
}
