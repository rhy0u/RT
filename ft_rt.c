/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:03:47 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/19 02:49:37 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
			sdl->pixels[(int)(y * L + x)] = rgb(filter(ft_vect(0, 0, 0), scene->filter));

			if (ft_inter_obj(scene, &ray) != 0)
			{
				if (ray.obj->name)
				{
					t_ray ref;
					ref.objref = ray.obj;
					ref.eye = ray.obj->inter;
					ref.dir = ft_sub_vec(ft_mul_vec_scal(ray.obj->normal_inter,
						ft_dot(ft_mul_vec(ft_mul_vec_scal(ray.dir, -1), ray.obj->normal_inter)) * 2), ft_mul_vec_scal(ray.dir, -1));
					if (ft_inter_obj(scene, &ref))
					{
						// if (ref.obj->name != SPHERE)
						// {

							ft_light(scene, &ref);
							ray.color = ft_mul_vec_scal(ft_add_vec(ray.color, ref.color), 0.9);
							// ray.color = ft_vect(255, 0, 0);
						// }
						// else
						// 		ft_light(scene, &ray);
					}
					else
						ft_light(scene, &ray);
					sdl->pixels[(int)(y * L + x)] = rgb(filter(ray.color, scene->filter));
				}
				else
					ft_light(scene, &ray);
				sdl->pixels[(int)(y * L + x)] = rgb(filter(ray.color, scene->filter));
			}
			x++;
		}
		y++;
	}
}
