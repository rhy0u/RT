/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:03:47 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/20 21:05:11 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_reflec_bis(t_scene *scene, t_ray *ray, t_ray *ref, int index)
{
	if (ft_inter_obj(scene, ref))
	{
		if (ref->obj->name == SPOT)
			ray->color = ft_add_vec(ray->color, ref->color);
		else
		{
		ft_light(scene, ref);
		ft_reflec(scene, ref, ++index);
		ray->color = ft_mul_vec_scal(ft_add_vec(ray->color,
			ft_mul_vec_scal(ref->color, ray->obj->reflec)), 0.5);
		}
	}
	else
	{
		ft_light(scene, ray);
		ray->color = ft_mul_vec_scal(ft_add_vec(ray->color,
			ft_vect(0, 0, 0)), 0.5);
	}
}

void		ft_reflec(t_scene *scene, t_ray *ray, int index)
{
	t_ray ref;

	if (index > 2)
		return ;
	if (ray->obj->reflec != 0)
	{
		ref.objref = ray->obj;
		ref.eye = ray->obj->inter;
		ref.dir = ft_sub_vec(ft_mul_vec_scal(ray->obj->normal_inter,
			ft_dot(ft_mul_vec(ft_mul_vec_scal(ray->dir, -1),
			ray->obj->normal_inter)) * 2), ft_mul_vec_scal(ray->dir, -1));
		ft_reflec_bis(scene, ray, &ref, index);
	}
	else
		ft_light(scene, ray);
}

void		ft_refrac_bis(t_scene *scene, t_ray *ray, t_ray *ref)
{
	if (ft_inter_obj(scene, ref))
	{
		if (ref->obj->name == SPOT)
			ray->color = ft_add_vec(ray->color, ref->color);
		else
		{
			ft_light(scene, ref);
			ray->color = ft_mul_vec_scal(ft_add_vec(ray->color, ft_mul_vec_scal(ref->color, ray->obj->pctrans)), 0.5);
		}
	}
	else
	{
		ft_light(scene, ray);
		ray->color = ft_mul_vec_scal(ft_add_vec(ray->color,
			ft_vect(0, 0, 0)), 0.5);
	}
}

void 		ft_refrac(t_scene *scene, t_ray *ray)
{
	t_ray ref;
	float p;

	if(ray->obj->refrac >= 1)
	{
		if(ray->obj->name == PLANE)
		{
			ref.objref = ray->obj;
			ref.eye = ray->obj->inter;
			ref.dir = ray->dir;
			ft_refrac_bis(scene, ray, &ref);
		}
		else
		{

			p = 1.0 / 1.05;
			ref.objref = ray->obj;
			ref.eye = ray->eye;
			ref.dir = ray->dir;
			t_xyz n = ray->obj->normal_inter;
			t_xyz i = ft_mul_vec_scal(ray->dir, -1);
			ref.dir = ft_sub_vec(ft_mul_vec_scal(n,
				(p * (ft_dot(ft_mul_vec(n, i) ))-sqrt(1-p*p*(1- ft_dot(ft_mul_vec(n, i) )* ft_dot(ft_mul_vec(n, i) )  ))      ) ),
				ft_mul_vec_scal(i, p)
			);







			ft_refrac_bis(scene, ray, &ref);






		}
	}
	if (ray->obj->reflec)
		ray->color = ft_mul_vec_scal(ray->color, 0.5);
}

void		ft_scene(t_sdl *sdl, t_scene *scene)
{
	double	x;
	double	y;
	t_ray	ray;
	t_cam	c;

	ft_cal_vec_cam(scene, &c);
	ray.eye = scene->cam.pos;
	y = 0;
	while (y < H / scene->res)
	{
		x = 0;
		while (x < L / scene->res)
		{
			ray.dir = ft_camera(scene, c, x, y);
			ft_normal(&ray.dir);
			sdl->pixels[(int)(y * (L) + x)] = rgb(filter(ft_vect(0, 0, 0), scene->filter));
			if (ft_inter_obj(scene, &ray) != 0)
			{
				ft_reflec(scene, &ray, 0);
				ft_refrac(scene, &ray);
				sdl->pixels[(int)(y * L + x)] = rgb(filter(ray.color, scene->filter));
			}
			x++;
		}
		y++;
	}
}
