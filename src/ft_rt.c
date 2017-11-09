/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:23:38 by jcentaur          #+#    #+#             */
/*   Updated: 2017/11/09 03:17:40 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_reflec_bis(t_scene *scene, t_ray *ray, t_ray *ref, int index)
{
	if (ft_inter_obj(scene, ref))
	{
		if (ref->obj->name == SPOT)
			ray->color = ft_add_vec(ray->color, ref->color);
		else
		{
			ft_light(scene, ref);
			if (ref->obj->refrac >= 1)
				ft_refrac(scene, ref, index);
			ft_reflec(scene, ref, ++index);
			ray->color = ft_scal(ft_add_vec(ray->color,
				ft_scal(ref->color, ray->obj->reflec)), 0.5);
		}
	}
	else
		ray->color = ft_scal(ft_add_vec(ray->color, ft_vect(0, 0, 0)), 0.5);
}

void		ft_reflec(t_scene *scene, t_ray *ray, int index)
{
	t_ray ref;

	if (ray->obj->refrac >= 1 || index > REFLEXMAX)
		return ;
	if (ray->obj->reflec != 0)
	{
		ref.objref = ray->obj;
		ref.eye = ray->obj->inter;
		ref.dir = ft_sub_vec(ft_scal(ray->obj->normal_inter,
			ft_dot(ft_mul_vec(ft_scal(ray->dir, -1),
			ray->obj->normal_inter)) * 2), ft_scal(ray->dir, -1));
		ft_reflec_bis(scene, ray, &ref, index);
	}
}

static void	ft_refrac_bis(t_scene *scene, t_ray *ray, t_ray ref, int index)
{
	if (ray->obj->name == PLANE)
		ref.dir = ray->dir;
	if (ft_inter_obj(scene, &ref))
	{
		if (ref.obj->name == SPOT)
			ray->color = ft_add_vec(ray->color, ref.color);
		else
		{
			ft_light(scene, &ref);
			ft_refrac(scene, &ref, ++index);
			ray->color = ft_scal(ft_add_vec(ray->color,
				ft_scal(ref.color, ray->obj->pctrans)), 0.5);
		}
	}
	else
		ray->color = ft_scal(ft_add_vec(ray->color, ft_vect(0, 0, 0)), 0.5);
}

void		ft_refrac(t_scene *scene, t_ray *ray, int index)
{
	t_ray ref;
	float p;

	if (index > 2)
		return ;
	if (ray->obj->refrac >= 1)
	{
		ref.objref = ray->obj;
		ref.eye = ray->eye;
		p = 1.0 / ray->obj->refrac;
		ref.dir = ft_sub_vec(ft_scal(ray->obj->normal_inter,
			(p * (ft_dot(ft_mul_vec(ray->obj->normal_inter,
			ft_scal(ray->dir, -1)))) - sqrt(1 - p * p * (1 -
			ft_dot(ft_mul_vec(ray->obj->normal_inter, ft_scal(
			ray->dir, -1))) * ft_dot(ft_mul_vec(ray->obj->normal_inter,
			ft_scal(ray->dir, -1))))))), ft_scal(
			ft_scal(ray->dir, -1), p));
		ft_refrac_bis(scene, ray, ref, index);
	}
}
