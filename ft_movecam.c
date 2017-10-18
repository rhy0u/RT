/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:23:15 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/06/03 00:39:07 by cmeaun-a         ###   ########.fr       */
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
		ft_scene(sdl, scene);
		SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, L * sizeof(Uint32));
		SDL_RenderClear(sdl->renderer);
		SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
		SDL_RenderPresent(sdl->renderer);
	}
}
