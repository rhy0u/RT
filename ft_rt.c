/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:23:38 by jcentaur          #+#    #+#             */
/*   Updated: 2017/10/24 04:50:23 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_reflec(t_scene *scene, t_ray *ray, int index)
{
	t_ray ref;

	if (ray->obj->refrac >= 1)
		return;
	if (index > 2)
		return ;
	if (ray->obj->reflec != 0)
	{
		ref.objref = ray->obj;
		ref.eye = ray->obj->inter;
		ref.dir = ft_sub_vec(ft_mul_vec_scal(ray->obj->normal_inter,
			ft_dot(ft_mul_vec(ft_mul_vec_scal(ray->dir, -1),
			ray->obj->normal_inter)) * 2), ft_mul_vec_scal(ray->dir, -1));
		if (ft_inter_obj(scene, &ref))
		{
			if (ref.obj->name == SPOT)
				ray->color = ft_add_vec(ray->color, ref.color);
			else
			{
				ft_light(scene, &ref);
				ft_reflec(scene, &ref, ++index);
				ray->color = ft_mul_vec_scal(ft_add_vec(ray->color,
					ft_mul_vec_scal(ref.color, ray->obj->reflec)), 0.5);
				}
			}
	}
}

void 		ft_refrac(t_scene *scene, t_ray *ray, int index)
{
	t_ray ref;
	float p;

	if (index > 2)
		return ;
	if(ray->obj->refrac >= 1)
	{
		ref.objref = ray->obj;
		ref.eye = ray->eye;
		p = 1.0 / ray->obj->refrac;
		ref.dir = ft_sub_vec(ft_mul_vec_scal(ray->obj->normal_inter,
			(p * (ft_dot(ft_mul_vec(ray->obj->normal_inter,
			ft_mul_vec_scal(ray->dir, -1)))) - sqrt(1 - p * p * (1 -
			ft_dot(ft_mul_vec(ray->obj->normal_inter, ft_mul_vec_scal(
			ray->dir, -1))) * ft_dot(ft_mul_vec(ray->obj->normal_inter,
			ft_mul_vec_scal(ray->dir, -1))))))), ft_mul_vec_scal(
			ft_mul_vec_scal(ray->dir, -1), p));
		if (ray->obj->name == PLANE)
			ref.dir = ray->dir;
		if (ft_inter_obj(scene, &ref))
		{
			if (ref.obj->name == SPOT)
				ray->color = ft_add_vec(ray->color, ref.color);
			else
			{
				ft_light(scene, &ref);
				ray->color = ft_mul_vec_scal(ft_add_vec(ray->color, ft_mul_vec_scal(ref.color, ray->obj->pctrans)), 0.5);
			}
		}
	}
}

void		*ft_thread(void *data)
{
	t_sdlpp	*s;
	t_cam	c;
	t_ray	ray;
	int		x;

	s = (t_sdlpp *)data;
	ft_cal_vec_cam(s->scene, &c);
	ray.eye = s->scene->cam.pos;
	while (s->y < s->limy)
	{
		x = s->x;
		while (x < s->limx)
		{
			ray.dir = ft_camera(s->scene, c, x, s->y);
			ft_normal(&ray.dir);
			s->sdl->pixels[(int)(s->y * L + x)] = rgb(filter(ft_vect(0, 0, 0), s->scene->filter));
			if (ft_inter_obj(s->scene, &ray) != 0)
			{
				ft_light(s->scene, &ray);
				ft_reflec(s->scene, &ray, 0);
				ft_refrac(s->scene, &ray, 0);
				s->sdl->pixels[(int)(s->y * L + x)] = rgb(filter(ray.color, s->scene->filter));
			}
			x++;
		}
		s->y++;
	}
	pthread_exit(NULL);
}
