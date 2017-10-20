/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:56:08 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/20 21:07:51 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_sdl_loop(t_sdl *sdl, t_scene *scene)
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
				ft_save(sdl);
			else if (key == SDLK_f)
				ft_changefilter(sdl, scene);
			else if (key == SDLK_KP_PLUS || key == SDLK_KP_MINUS)
				ft_res(sdl, scene);
			else if (key == SDLK_m)
				ft_antialiasing(sdl);
			else
				ft_movecam(sdl, scene);
		}
	}
}

int		main2(t_sdl *sdl, t_scene *scene, char **av)
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
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (0);
	ft_get_scene(scene, fd);
	if (!(sdl->pixels = (Uint32*)malloc(sizeof(sdl->pixels) * (L / scene->res) * (H / scene->res))))
		return (0);
	ft_bzero(sdl->pixels, (L / scene->res) * (H / scene->res) * sizeof(Uint32));
	scene->filter = 0;
	ft_scene(sdl, scene);
	return (1);
}

int		main(int ac, char **av)
{
	t_sdl		sdl;
	t_scene		scene;
	GtkWidget *win;
	GtkWidget *bouton_explorer;

	gtk_init(&ac,&av);
	if (!(filename = malloc(sizeof(char**))))
		return(0);
	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(win),"GtkFileSelection");
	gtk_window_set_default_size(GTK_WINDOW(win),320,200);
	bouton_explorer=gtk_button_new_with_mnemonic("_Explorer...");
	gtk_container_add(GTK_CONTAINER(win),bouton_explorer);

	g_signal_connect(G_OBJECT(win),"destroy",G_CALLBACK(quitter), NULL);
	g_signal_connect(G_OBJECT(bouton_explorer), "clicked", G_CALLBACK(creer_file_selection), win);

	gtk_widget_show_all(win);
	gtk_main();
	gtk_widget_destroy((GtkWidget *)win);
	gtk_main_quit();
	if (!main2(&sdl, &scene, &filename))
		return (0);
	scene.res = 1;
	sdl.renderer = SDL_CreateRenderer(sdl.win, -1, 0);
	sdl.texture = SDL_CreateTexture(sdl.renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC, L / scene.res, H / scene.res);
	SDL_UpdateTexture(sdl.texture, NULL, sdl.pixels, L / scene.res * sizeof(Uint32));
	SDL_RenderClear(sdl.renderer);
	SDL_RenderCopy(sdl.renderer, sdl.texture, NULL, NULL);
	SDL_RenderPresent(sdl.renderer);
	ft_sdl_loop(&sdl, &scene);
	SDL_DestroyWindow(sdl.win);
	SDL_DestroyTexture(sdl.texture);
	SDL_DestroyRenderer(sdl.renderer);
	free_all(&scene, &sdl);
	SDL_Quit();
	return (0);
}
