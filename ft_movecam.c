/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movecam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:23:15 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/20 21:05:22 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void ft_movecam(t_sdl *sdl, t_scene *scene)
{
	int		key;

	key = sdl->event.key.keysym.sym;
	if (key == SDLK_q || key == SDLK_s || key == SDLK_d
		|| key == SDLK_a || key == SDLK_e || key == SDLK_w)
	{
		if (key == SDLK_w)
			scene->cam.pos.z += 10;
		else if (key == SDLK_s)
			scene->cam.pos.z -= 10;
		else if (key == SDLK_d)
			scene->cam.pos.x += 10;
		else if (key == SDLK_a)
			scene->cam.pos.x -= 10;
		else if (key == SDLK_e)
			scene->cam.pos.y += 10;
		else if (key == SDLK_q)
			scene->cam.pos.y -= 10;
		ft_bzero(sdl->pixels, (L / scene->res) * (H / scene->res) * sizeof(Uint32));
		ft_scene(sdl, scene);
		SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, L * sizeof(Uint32));
		SDL_RenderClear(sdl->renderer);
		SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
		SDL_RenderPresent(sdl->renderer);
	}
}
void	ft_res(t_sdl *sdl, t_scene *scene)
{
	if (scene->res > 1 && sdl->event.key.keysym.sym == SDLK_KP_PLUS)
		scene->res--;
	else if (scene->res < 20 && sdl->event.key.keysym.sym == SDLK_KP_MINUS)
		scene->res++;
	else
		return ;
	SDL_DestroyTexture(sdl->texture);
	ft_bzero(sdl->pixels, (L) * (H) * sizeof(Uint32));
	ft_scene(sdl, scene);
	sdl->texture = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC, L / scene->res, H / scene->res);
	SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, L * sizeof(Uint32));
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}

void	ft_changefilter(t_sdl *sdl, t_scene *scene)
{
	scene->filter++;
	if (scene->filter > 6)
		scene->filter = 0;
	ft_bzero(sdl->pixels, (L / scene->res) * (H / scene->res) * sizeof(Uint32));
	ft_scene(sdl, scene);
	SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, L * sizeof(Uint32));
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}
