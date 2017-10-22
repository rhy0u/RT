/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:23:38 by jcentaur          #+#    #+#             */
/*   Updated: 2017/10/22 18:27:32 by jcentaur         ###   ########.fr       */
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
			ray->color = ft_mul_vec_scal(ft_add_vec(ray->color, ft_mul_vec_scal(ref->color, 1)), 0.5);
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
	float n;

	if(ray->obj->refrac >= 1)
	{
		n = 1.0 / ray->obj->refrac;
		ref.objref = ray->obj;
		ref.eye = ray->obj->inter;
		ref.dir = ft_sub_vec(ft_mul_vec_scal(ray->obj->normal_inter,
			(n * ft_dot(ft_mul_vec(ray->obj->normal_inter,
			ft_mul_vec_scal(ray->dir, -1)))) - sqrt(1 - n * n * (1 -
			ft_dot(ft_sq_vec(ft_mul_vec(ray->obj->normal_inter,
			ft_mul_vec_scal(ray->dir, -1))))))),
			ft_mul_vec_scal(ft_mul_vec_scal(ray->dir, -1), n));
		ft_refrac_bis(scene, ray, &ref);
	}
	else
		ft_light(scene, ray);
}

void		*ft_thread(void  *data)
{
	t_sdlpp	*s;
	t_cam	c;
	t_ray	ray;
	int		x;
	int		xx;
	int		y;
	int		limx;
	int		limy;

	s = (t_sdlpp *)data;
	pthread_mutex_lock(&(s->lock));
	ft_cal_vec_cam(s->scene, &c);
	ray.eye = s->scene->cam.pos;
	y = s->y;
	xx = s->x;
	limx= s->limx;
	limy= s->limy;
	pthread_cond_signal(&(s->cond));
	pthread_mutex_unlock(&(s->lock));
	while (y < limy)
	{
		x = xx;
		while (x < limx)
		{
			pthread_mutex_lock(&(s->lock));
			ray.dir = ft_camera(s->scene, c, x, y);
			ft_normal(&ray.dir);
			s->sdl->pixels[(int)(y * L + x)] = rgb(filter(ft_vect(0, 0, 0), s->scene->filter));
			if (ft_inter_obj(s->scene, &ray) != 0)
			{
				ft_reflec(s->scene, &ray, 0);
				ft_refrac(s->scene, &ray);
				s->sdl->pixels[(int)(y * L + x)] = rgb(filter(ray.color, s->scene->filter));
			}
			pthread_mutex_unlock(&(s->lock));
			x++;
		}
		y++;
	}
	// printf("x = %d\ny = %d\nlimx = %d\nlimy = %d\n\n", s->x, s->y, s->limx, s->limy);
	pthread_exit(NULL);
}

void		ft_scene(t_sdl *sdl, t_scene *scene)
{
	t_sdlpp	*s;
	pthread_t	thread[4];

	s = (t_sdlpp *)malloc(sizeof(t_sdlpp));
	s->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	s->cond = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
	s->y = 0;
	s->x = 0;
	s->limx = L / (scene->res * 2.0);
	s->limy = H / (scene->res * 2.0);
	s->sdl = sdl;
	s->scene = scene;
	pthread_create(&thread[0],  NULL,ft_thread, (void *)s);
	pthread_mutex_lock(&(s->lock));
	pthread_cond_wait(&(s->cond), &(s->lock));
	s->x += s->limx;
	s->limx += s->limx;
	pthread_mutex_unlock(&(s->lock));
	pthread_create(&thread[1],  NULL,ft_thread, (void *)s);
	pthread_mutex_lock(&(s->lock));
	pthread_cond_wait(&(s->cond), &(s->lock));
	s->x = 0;
	s->limx = L / (scene->res * 2.0);
	s->y += s->limy;
	s->limy += s->limy;
	pthread_mutex_unlock(&(s->lock));
	pthread_create(&thread[2],  NULL,ft_thread, (void *)s);
	pthread_mutex_lock(&(s->lock));
	pthread_cond_wait(&(s->cond), &(s->lock));
	s->x += s->limx;
	s->limx += s->limx;
	pthread_mutex_unlock(&(s->lock));
	pthread_create(&thread[3],  NULL,ft_thread, (void *)s);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
}
