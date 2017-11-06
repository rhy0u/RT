/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:56:08 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/11/07 00:29:57 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_sdl_loop_bis(t_sdl *sdl, t_scene *scene, int key)
{
	if (key == SDLK_f)
		ft_changefilter(sdl, scene);
	else if (key == SDLK_KP_PLUS || key == SDLK_KP_MINUS)
		ft_res(sdl, scene);
	else if (key == SDLK_m)
		ft_antialiasing(sdl);
	else if (key == SDLK_c)
		ft_celshading(sdl, scene);
	else
		ft_movecam(sdl, scene);
}

void		ft_sdl_loop(t_sdl *sdl, t_scene *scene)
{
	int		finish;
	int		key;

	finish = 1;
	while (finish)
	{
		SDL_WaitEvent(&sdl->event);
		key = sdl->event.key.keysym.sym;
		if (sdl->event.type == SDL_QUIT)
			finish = 0;
		if (sdl->event.type == SDL_KEYDOWN)
		{
			if (key == SDLK_ESCAPE)
				finish = 0;
			else if (key == SDLK_p)
				ft_save(sdl, scene);
			else
				ft_sdl_loop_bis(sdl, scene, key);
		}
	}
}

int			main2(t_sdl *sdl, t_scene *scene, char **filename)
{
	int			fd;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return (0);
	}
	if ((sdl->win = SDL_CreateWindow("rtv1", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, L, H, SDL_WINDOW_SHOWN)) == 0)
	{
		SDL_Quit();
		return (0);
	}
	if ((fd = open(filename[0], O_RDONLY)) < 0)
		return (0);
	scene->res = 1;
	scene->celshading = 0;
	scene->filter = 0;
	ft_get_scene(scene, fd);
	if (!(sdl->pixels = (Uint32*)malloc(sizeof(sdl->pixels) * (L / scene->res)
	* (H / scene->res))))
		return (0);
	ft_bzero(sdl->pixels, (L / scene->res) * (H / scene->res) * sizeof(Uint32));
	ft_scene(sdl, scene);
	return (1);
}

static void	main_bis(t_sdl sdl, t_scene scene)
{
	sdl.texture = SDL_CreateTexture(sdl.renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC, L / scene.res, H / scene.res);
	SDL_UpdateTexture(sdl.texture, NULL, sdl.pixels, L / scene.res
		* sizeof(Uint32));
	SDL_RenderClear(sdl.renderer);
	SDL_RenderCopy(sdl.renderer, sdl.texture, NULL, NULL);
	SDL_RenderPresent(sdl.renderer);
	ft_sdl_loop(&sdl, &scene);
	SDL_DestroyWindow(sdl.win);
	SDL_DestroyTexture(sdl.texture);
	SDL_DestroyRenderer(sdl.renderer);
	free_all(&scene, &sdl);
}

int			main(int ac, char **av)
{
	t_sdl			sdl;
	t_scene			scene;
	GtkApplication	*app;
	int				status;

	if ((ac == 3) && (ft_strncmp(av[1], "-f", 3) == 0))
	{
		g_filename = ft_strdup(av[2]);
		if (!main2(&sdl, &scene, &g_filename))
			return (0);
	}
	else
	{
		app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
		g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
		status = g_application_run(G_APPLICATION(app), ac, av);
		if (!main2(&sdl, &scene, (&g_filename + 1)))
			return (0);
		g_object_unref(app);
	}
	sdl.renderer = SDL_CreateRenderer(sdl.win, -1, 0);
	main_bis(sdl, scene);
	SDL_Quit();
	return (0);
}
