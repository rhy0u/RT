/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthouard <pthouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 01:49:43 by pthouard          #+#    #+#             */
/*   Updated: 2017/11/03 02:22:44 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj		*list_damier(char *str)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = DAM;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_cyl(char *str)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = CYL;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_plane(char *str)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = PLANE;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_disk(char *str)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = DISK;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}

t_obj		*list_spot(char *str)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	clear_obj(obj);
	obj->name = SPOT;
	info_obj(str, obj);
	obj->next = NULL;
	return (obj);
}
