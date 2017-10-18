/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 01:14:24 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/06/03 02:14:37 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	*free_obj(t_obj **obj)
{
	t_obj *tmp;
	t_obj *obj_next;

	tmp = *obj;
	while (tmp != NULL)
	{
		obj_next = tmp->next;
		free(tmp);
		tmp = obj_next;
	}
	return (NULL);
}

t_spot	*free_spot(t_spot **spot)
{
	t_spot *tmp;
	t_spot *obj_next;

	tmp = *spot;
	while (tmp != NULL)
	{
		obj_next = tmp->next;
		free(tmp);
		tmp = obj_next;
	}
	return (NULL);
}

void	free_all(t_scene *scene, t_sdl *sdl)
{
	scene->obj = free_obj(&scene->obj);
	scene->spot = free_spot(&scene->spot);
	free(sdl->pixels);
}
