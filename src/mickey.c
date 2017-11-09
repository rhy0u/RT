/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mickey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 23:54:36 by jcentaur          #+#    #+#             */
/*   Updated: 2017/11/09 01:37:10 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj		*oreille_droite(t_obj *o)
{
	t_obj *obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = SPHERE;
	obj->cutonoff = 0;
	obj->rot = ft_vect(0, 0, 0);
	obj->pos = ft_vect(o->pos.x - o->radius, o->pos.y + o->radius * 0.8,
		o->pos.z);
	obj->color = ft_vect(o->color.x, o->color.y, o->color.z);
	obj->specular = o->specular;
	obj->reflec = o->reflec;
	obj->refrac = o->refrac;
	obj->pctrans = o->pctrans;
	obj->radius = o->radius / 2;
	return (obj);
}

t_obj		*oreille_gauche(t_obj *o)
{
	t_obj *obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = SPHERE;
	obj->cutonoff = 0;
	obj->rot = ft_vect(0, 0, 0);
	obj->pos = ft_vect(o->pos.x + o->radius, o->pos.y + o->radius * 0.8,
		o->pos.z);
	obj->color = ft_vect(o->color.x, o->color.y, o->color.z);
	obj->specular = o->specular;
	obj->reflec = o->reflec;
	obj->pctrans = o->pctrans;
	obj->refrac = o->refrac;
	obj->radius = o->radius / 2;
	return (obj);
}

t_obj		*list_mickey(char *str)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	info_obj(str, obj);
	obj->name = SPHERE;
	obj->cutonoff = 0;
	obj->rot = ft_vect(0, 0, 0);
	obj->next = oreille_gauche(obj);
	obj->next->next = oreille_droite(obj);
	return (obj);
}
