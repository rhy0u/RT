/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 07:03:00 by jcentaur          #+#    #+#             */
/*   Updated: 2017/10/23 22:50:56 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_thread1(t_sdl *sdl, t_scene *scene)
{
	t_sdlpp	*s;
	pthread_t	thread;

	s = (t_sdlpp *)malloc(sizeof(t_sdlpp));
	s->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	s->y = 0;
	s->x = 0;
	s->limx = L / scene->res;
	s->limy = H / scene->res;
	s->sdl = sdl;
	s->scene = scene;
	pthread_create(&thread,  NULL,ft_thread, (void *)s);
	pthread_join(thread, NULL);
}

void	ft_thread2(t_sdl *sdl, t_scene *scene)
{
	t_sdlpp	*s;
	pthread_t	thread;

	s = (t_sdlpp *)malloc(sizeof(t_sdlpp));
	s->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	s->x = 0;
	s->y = 0;
	s->limx = L / scene->res;
	s->limy = H / (scene->res * 2.0);
	s->sdl = sdl;
	s->scene = scene;
	pthread_create(&thread,  NULL,ft_thread, (void *)s);
	pthread_join(thread, NULL);
}

void	ft_thread3(t_sdl *sdl, t_scene *scene)
{
	t_sdlpp	*s;
	pthread_t	thread;

	s = (t_sdlpp *)malloc(sizeof(t_sdlpp));
	s->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	s->y = H / (scene->res * 2.0);
	s->x = 0;
	s->limx = L / (scene->res * 2.0);
	s->limy = H / scene->res;
	s->sdl = sdl;
	s->scene = scene;
	pthread_create(&thread,  NULL,ft_thread, (void *)s);
	pthread_join(thread, NULL);
}

void	ft_thread4(t_sdl *sdl, t_scene *scene)
{
	t_sdlpp	*s;
	pthread_t	thread;

	s = (t_sdlpp *)malloc(sizeof(t_sdlpp));
	s->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	s->y = H / (scene->res * 2.0);
	s->x = L / (scene->res * 2.0);
	s->limx = L / scene->res;
	s->limy = H / scene->res;
	s->sdl = sdl;
	s->scene = scene;
	pthread_create(&thread,  NULL,ft_thread, (void *)s);
	pthread_join(thread, NULL);
}

void		ft_scene(t_sdl *sdl, t_scene *scene)
{
	ft_thread1(sdl, scene);
// 	ft_thread2(sdl, scene);
// 	ft_thread3(sdl, scene);
// 	ft_thread4(sdl, scene);
}
