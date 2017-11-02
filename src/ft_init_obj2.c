/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthouard <pthouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 01:49:43 by pthouard          #+#    #+#             */
/*   Updated: 2017/10/31 01:56:13 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
