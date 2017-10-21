/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movecam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:05:18 by jcentaur          #+#    #+#             */
/*   Updated: 2017/10/21 02:05:30 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void move(t_scene *scene, int key, t_xyz dir)
{
	if (key == SDLK_s || key == SDLK_w || key == SDLK_q || key == SDLK_e)
	{
		if (key == SDLK_w)
		{
			scene->cam.look_at = ft_add_vec(scene->cam.look_at, ft_mul_vec_scal(dir, 10));
			scene->cam.pos = ft_add_vec(scene->cam.pos, ft_mul_vec_scal(dir, 10));
		}
		else if (key == SDLK_s)
		{
			scene->cam.look_at = ft_add_vec(scene->cam.look_at, ft_mul_vec_scal(dir, -10));
			scene->cam.pos = ft_add_vec(scene->cam.pos, ft_mul_vec_scal(dir, -10));
		}
		else if (key == SDLK_e)
		{
			scene->cam.look_at.y += 5;
			scene->cam.pos.y += 5;
		}
		else if (key == SDLK_q)
		{
			scene->cam.look_at.y -= 5;
			scene->cam.pos.y -= 5;
		}
	}
}

void ft_movecam(t_sdl *sdl, t_scene *scene)
{
	int		key;
	t_xyz	dir;

	key = sdl->event.key.keysym.sym;
	dir = ft_sub_vec(scene->cam.look_at, scene->cam.pos);
	ft_normal(&dir);
	move(scene, key, dir);
	if (key == SDLK_d || key == SDLK_a)
	{
		if (key == SDLK_d)
		dir = rotation_y(dir, 0.0872665);
		else if (key == SDLK_a)
		dir = rotation_y(dir, -0.0872665);
		scene->cam.look_at = ft_add_vec(scene->cam.pos, dir);
	}
	ft_bzero(sdl->pixels, (L / scene->res) * (H / scene->res) * sizeof(Uint32));
	ft_scene(sdl, scene);
	SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, L * sizeof(Uint32));
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}
