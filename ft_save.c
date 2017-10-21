/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:39:35 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/21 02:20:29 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void ft_save(t_sdl *sdl, t_scene *s)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurfaceFrom((void *)sdl->pixels, L / s->res, H / s->res, 32, 4 * L ,
	0xff000000 >> 8,
	0x00ff0000 >> 8,
	0x0000ff00 >> 8,
	0x000000ff >> 8);
	SDL_SaveBMP(surface, "save.bmp");
	SDL_FreeSurface(surface);
}
