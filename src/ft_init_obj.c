/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 03:07:55 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/11/03 02:23:03 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	info_obj_bis(char *str, t_obj *obj, int i)
{
	if (ft_strncmp("<cutonoff>", &str[i], 10) == 0)
		obj->cutonoff = get_radius(&str[i]);
	else if (ft_strncmp("<cutisreal>", &str[i], 11) == 0)
		obj->cutisreal = get_radius(&str[i]);
	else if (ft_strncmp("<cut>", &str[i], 5) == 0)
		obj->cut = get_xyz(&str[i]);
	else if (ft_strncmp("<cutnorm>", &str[i], 9) == 0)
		obj->cutnorm = get_xyz(&str[i]);
	else if (ft_strncmp("<reflec>", &str[i], 8) == 0)
		obj->reflec = get_radius(&str[i]) / 100;
	else if (ft_strncmp("<refrac>", &str[i], 8) == 0)
		obj->refrac = get_radius(&str[i]) / 100;
	else if (ft_strncmp("<pctrans>", &str[i], 9) == 0)
		obj->pctrans = get_radius(&str[i]) / 100;
	else if (ft_strncmp("<vague>", &str[i], 7) == 0)
		obj->vague = get_radius(&str[i]);
}

void		info_obj(char *str, t_obj *obj)
{
	int i;

	i = 0;
	while (str[i] && ft_strncmp("</object>", &str[i], 9))
	{
		if (ft_strncmp("<rotation>", &str[i], 10) == 0)
			obj->rot = get_rad(&str[i]);
		else if (ft_strncmp("<translation>", &str[i], 13) == 0)
			obj->trans = get_xyz(&str[i]);
		else if (ft_strncmp("<origine>", &str[i], 8) == 0)
			obj->pos = get_pos(&str[i], obj->trans);
		else if (ft_strncmp("<radius>", &str[i], 8) == 0)
			obj->radius = get_radius(&str[i]);
		else if (ft_strncmp("<color>", &str[i], 7) == 0)
			obj->color = get_xyz(&str[i]);
		else if (ft_strncmp("<specular>", &str[i], 10) == 0)
			obj->specular = get_radius(&str[i]);
		else if (ft_strncmp("<normal>", &str[i], 8) == 0)
			obj->n = rot_all(get_xyz(&str[i]), obj->rot.x, obj->rot.y,
				obj->rot.z);
		else
			info_obj_bis(str, obj, i);
		i++;
	}
}

t_obj		*list_sphere(char *str)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = SPHERE;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_cone(char *str)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = CONE;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}
