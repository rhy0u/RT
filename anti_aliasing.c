/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:55:13 by jcentaur          #+#    #+#             */
/*   Updated: 2017/10/25 02:44:28 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static	t_xyz ub(Uint32 i)
{
	t_xyz rgb;

	rgb.z = i & 255;
	rgb.y = i >> 8 & 255;
	rgb.x = i >> 16 & 255;
	return rgb;
}

static Uint32 moy(t_xyz aa[4])
{
	t_xyz	res;

	res = ft_add_vec(aa[0], ft_add_vec(aa[1], ft_add_vec(aa[2],
		ft_add_vec(aa[3], ft_add_vec(aa[4], ft_add_vec(aa[5],
		ft_add_vec(aa[6], ft_add_vec(aa[7], aa[8]))))))));
	res = ft_mul_vec_scal(res, 1 / 9.0);
	return (rgb(res));
}

void	ft_antialiasing(t_sdl *sdl)
{
	int		x;
	int		y;
	t_xyz	aa[9];

	y = 1;
	while (y < H - 1)
	{
		x = 1;
		while (x < L - 1)
		{
			aa[0] = ub(sdl->pixels[(y * L + x)]);
			aa[1] = ub(sdl->pixels[((y - 1) * L + (x - 1))]);
			aa[2] = ub(sdl->pixels[(((y - 1) * L + x))]);
			aa[3] = ub(sdl->pixels[((y - 1) * L + (x + 1))]);
			aa[4] = ub(sdl->pixels[((y * L + (x - 1)))]);
			aa[5] = ub(sdl->pixels[((y * L + (x + 1)))]);
			aa[6] = ub(sdl->pixels[((y + 1) * L + (x - 1))]);
			aa[7] = ub(sdl->pixels[((y + 1) * L + x)]);
			aa[8] = ub(sdl->pixels[((y + 1) * L + (x + 1))]);
			sdl->pixels[(y * L + x)] = moy(aa);
			x++;
		}
		y++;
	}
	SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, L * sizeof(Uint32));
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}
