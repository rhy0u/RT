/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 07:15:49 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/31 02:51:03 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cel(float *a, int cell)
{
	if (cell != 1)
		return ;
	if (*a <= -0.8)
		*a = -0.8;
	else if (*a <= -0.7)
		*a = -0.7;
	else if (*a <= -0.6)
		*a = -0.6;
	else if (*a <= -0.5)
		*a = -0.5;
	else if (*a <= -0.4)
		*a = -0.4;
	else if (*a <= -0.3)
		*a = -0.3;
	else if (*a <= -0.2)
		*a = -0.2;
	else
		*a = -0.1;
}

void	ft_cal_color_final(t_ray *ray, t_spot *l, int cell, float block)
{
	float a;
	t_xyz c;
	t_xyz cd;
	t_xyz cs;
	t_xyz r;

	if (ft_dot(ft_mul_vec(ray->dir, ray->obj->normal_inter)) < 0
	|| ray->obj->refrac >= 1)
	{
		r = ft_sub_vec(ft_scal(ray->obj->normal_inter,
			ft_dot(ft_mul_vec(l->dir, ray->obj->normal_inter)) * 2), l->dir);
		if ((a = ft_dot(ft_mul_vec(l->dir, ray->obj->normal_inter))) < 0)
		{
			cel(&a, cell);
			cd = ft_scal(ft_scal(l->color, -a), l->diffuse);
			cs = ft_scal(l->color, pow(ft_dot(ft_mul_vec(r, ray->dir)),
					100));
			if (ray->obj->specular == 0)
				cs = ft_vect(0, 0, 0);
			c = ft_scal(ft_add_vec(cd, cs), block);
			ray->color = ft_add_vec(ray->color, c);
		}
	}
	if (ray->obj->name == SPOT)
		ray->color = ray->obj->color;
}

float	block(t_spot *l, t_obj *o, t_ray *ray)
{
	t_ray	rl;
	float	block;

	block = 1;
	rl.eye = l->pos;
	rl.dir = l->dir;
	while (o)
	{
		if (o != ray->obj && o->name != 6)
		{
			if (ft_get_inter(&rl, o))
			{
				l->l_to_inter_dist = ft_mag_vec(ft_sub_vec(o->inter, l->pos));
				if (l->l_to_inter_dist < l->light_to_obj_dist)
					block *= o->pctrans;
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
	float	bloc;

	if (s->spot == NULL)
		return ;
	l = s->spot;
	while (l)
	{
		o = s->obj;
		l->dir = ft_sub_vec(ray->obj->inter, l->pos);
		l->light_to_obj_dist = ft_mag_vec(l->dir);
		ft_normal(&l->dir);
		bloc = block(l, o, ray);
		ft_cal_color_final(ray, l, s->celshading, bloc);
		l = l->next;
	}
}
