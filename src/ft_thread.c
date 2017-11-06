/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthouard <pthouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:35:09 by pthouard          #+#    #+#             */
/*   Updated: 2017/11/07 00:35:30 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_thread_bis(t_sdlpp *s, t_cam c, t_ray ray)
{
	int		x;

	while (s->y < s->limy)
	{
		x = s->x;
		while (x < s->limx)
		{
			ray.dir = ft_camera(s->scene, c, x, s->y);
			ft_normal(&ray.dir);
			s->sdl->pixels[(int)(s->y * L + x)] = rgb(filter(ft_vect(0, 0, 0),
			s->scene->filter));
			if (ft_inter_obj(s->scene, &ray) != 0)
			{
				ft_light(s->scene, &ray);
				ft_reflec(s->scene, &ray, 0);
				ft_refrac(s->scene, &ray, 0);
				s->sdl->pixels[(int)(s->y * L + x)] = rgb(filter(ray.color,
					s->scene->filter));
			}
			x++;
		}
		s->y++;
	}
}

void		*ft_thread(void *data)
{
	t_sdlpp	*s;
	t_cam	c;
	t_ray	ray;

	s = (t_sdlpp *)data;
	ft_cal_vec_cam(s->scene, &c);
	ray.eye = s->scene->cam.pos;
	ft_thread_bis(s, c, ray);
	pthread_exit(NULL);
}
