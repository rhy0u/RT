/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:39:35 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/06/06 00:30:22 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void ft_save(t_sdl *sdl)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurfaceFrom((void *)sdl->pixels, L, H, 32, 4 * L,
	0xff000000 >> 8,
	0x00ff0000 >> 8,
	0x0000ff00 >> 8,
	0x000000ff >> 8);
	SDL_SaveBMP(surface, "save.bmp");
	SDL_FreeSurface(surface);
}
