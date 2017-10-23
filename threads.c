/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 07:03:00 by jcentaur          #+#    #+#             */
/*   Updated: 2017/10/23 09:58:00 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void init_s(t_sdlpp *s, t_scene *scene, t_sdl *sdl) {

	s->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	s->cond = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
	s->y = 0;
	s->x = 0;
	s->limx = L / (scene->res * 2.0);
	s->limy = H / (scene->res * 2.0);
	s->sdl = sdl;
	s->scene = scene;
	s->islock = 0;
}

void		ft_scene(t_sdl *sdl, t_scene *scene)
{
	t_sdlpp	*s;
	int		i;
	pthread_t	thread[4];

	s = (t_sdlpp *)malloc(sizeof(t_sdlpp));
	init_s(s, scene, sdl);
	i = 0;
	while (i < 4)
	{
		pthread_create(&thread[i],  NULL,ft_thread, (void *)s);
		pthread_mutex_lock(&(s->lock));
		pthread_cond_wait(&s->cond, &s->lock);
		s->x += s->limx;
		s->limx += s->limx;
		if (s->x >= H / scene->res)
		{
			s->x = 0;
			s->limx = L / (scene->res * 2.0);
			s->y += s->limy;
			s->limy += s->limy;
		}
		pthread_cond_signal(&s->cond);
		pthread_mutex_unlock(&(s->lock));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
