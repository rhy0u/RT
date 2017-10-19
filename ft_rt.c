/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:03:47 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/19 05:17:26 by jcentaur         ###   ########.fr       */
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
				ft_light(scene, &ray);
				sdl->pixels[(int)(y * L + x)] = rgb(filter(ray.color, scene->filter));
			}
			x++;
		}
		y++;
	}
}
