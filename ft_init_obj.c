/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 03:07:55 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/06/07 01:12:05 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
		else if (ft_strncmp("<cutonoff>", &str[i], 10) == 0)
			obj->cutonoff = get_radius(&str[i]);
		else if (ft_strncmp("<cutisreal>", &str[i], 11) == 0)
			obj->cutisreal = get_radius(&str[i]);
		else if (ft_strncmp("<cut>", &str[i], 5) == 0)
			obj->cut = get_xyz(&str[i]);
		else if (ft_strncmp("<cutnorm>", &str[i], 9) == 0)
			obj->cutnorm = get_xyz(&str[i]);
		i++;
	}
}

t_obj		*list_sphere(char *str)
{
	t_obj	*obj;

	obj = new_list();
	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->name = SPHERE;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_cone(char *str)
{
	t_obj	*obj;

	obj = new_list();
	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->name = CONE;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_damier(char *str)
{
	t_obj	*obj;

	obj = new_list();
	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->name = DAM;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_cyl(char *str)
{
	t_obj	*obj;

	obj = new_list();
	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->name = CYL;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_plane(char *str)
{
	t_obj	*obj;

	obj = new_list();
	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->name = PLANE;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_disk(char *str)
{
	t_obj	*obj;

	obj = new_list();
	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->name = DISK;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_spot(char *str)
{
	t_obj	*obj;

	obj = new_list();
	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->name = SPOT;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}
