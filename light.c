/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 07:15:49 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/25 03:01:42 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
void	cel(float *a)
{
	if (*a <= -0.8)
		*a = -0.8;
	else if (*a <= -0.6)
		*a = -0.6;
	else if (*a <= -0.4)
		*a = -0.4;
	else
		*a = -0.2;
}

void	ft_cal_color_final(t_ray *ray, t_spot *l)
{
	float a;
	t_xyz c;
	t_xyz cd;
	t_xyz cs;
	t_xyz r;

	if (ft_dot(ft_mul_vec(ray->dir, ray->obj->normal_inter)) < 0 || ray->obj->refrac >= 1)
	{
		r = ft_sub_vec(ft_mul_vec_scal(ray->obj->normal_inter,
			ft_dot(ft_mul_vec(l->dir, ray->obj->normal_inter)) * 2), l->dir);
		if ((a = ft_dot(ft_mul_vec(l->dir, ray->obj->normal_inter))) < 0)
		{
			if (cell == 1)
				cel(&a);
			cd = ft_mul_vec_scal(ft_mul_vec_scal(l->color, -a), l->diffuse);
			cs = ft_mul_vec_scal(l->color, pow(ft_dot(ft_mul_vec(r, ray->dir)),
					100));
			if (ray->obj->specular == 0)
				cs = ft_vect(0, 0, 0);
			c = ft_add_vec(cd, cs);
			ray->color = ft_add_vec(ray->color, c);
		}
	}
	if (ray->obj->name == SPOT)
		ray->color = ray->obj->color;
}

int		block(t_spot *l, t_obj *o, t_ray *ray)
{
	t_ray	rl;
	int		block;

	block = 0;
	rl.eye = l->pos;
	rl.dir = l->dir;
	while (o)
	{
		if (o->refrac >= 1 && o->name == PLANE)
			o = o->next;
		if (!o)
			return 0;
		if (o->name == 6)
			o = o->next;
		else if (o != ray->obj)
		{
			if (ft_get_inter(&rl, o))
			{
				l->light_to_inter_dist = ft_magnitude_vec(ft_sub_vec(o->inter,
							l->pos));
				if (l->light_to_inter_dist < l->light_to_obj_dist)
					block = 1;
			}
		}
		o = o->next;
	}
	return (block);
}

void	ft_light(t_scene *s, t_ray *ray)
{
	t_obj	*o;
	t_spot	*l;

	if (s->spot == NULL)
		return ;
	l = s->spot;
	while (l)
	{
		o = s->obj;
		l->dir = ft_sub_vec(ray->obj->inter, l->pos);
		l->light_to_obj_dist = ft_magnitude_vec(l->dir);
		ft_normal(&l->dir);
		if (!block(l, o, ray))
			ft_cal_color_final(ray, l, scene->celshading);
		l = l->next;
	}
}
