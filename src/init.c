/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 01:10:15 by jcentaur          #+#    #+#             */
/*   Updated: 2017/11/03 02:46:15 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	clear_obj(t_obj *o)
{
	o->name = 1;
	o->pos = ft_vect(0, 0, 0);
	o->n = ft_vect(0, 0, 0);
	o->rot = ft_vect(0, 0, 0);
	o->trans = ft_vect(0, 0, 0);
	o->cut = ft_vect(0, 0, 0);
	o->cutnorm = ft_vect(0, 0, 0);
	o->color = ft_vect(0, 0, 0);
	o->radius = 0;
	o->specular = 0;
	o->cutonoff = 0;
	o->reflec = 0;
	o->refrac = 1;
	o->pctrans = 0;
	o->cutisreal = 0;
	o->vague = 0;
	o->next = NULL;
}

void	clear_spot(t_spot *l)
{
	l->pos = ft_vect(0, 0, 0);
	l->color = ft_vect(255, 255, 255);
	l->diffuse = 0.2;
}

void	clear_cam(t_scene *s)
{
	s->ambiante = 0.2;
	s->cam.pos = ft_vect(0, 0, -200);
	s->cam.look_at = ft_vect(0, 0, 0);
}
