/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:57:26 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/06/14 21:19:07 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_get_inter(t_ray *ray, t_obj *obj)
{
	int		inter;

	inter = 0;
	if (obj->name == 1)
		inter = ft_sphere(*ray, obj);
	else if (obj->name == 2)
		inter = ft_cone(*ray, obj);
	else if (obj->name == 3)
		inter = ft_cylindre(*ray, obj);
	else if (obj->name == 4)
		inter = ft_plane(*ray, obj);
	else if (obj->name == 5)
		inter = ft_disk(*ray, obj);
	else if (obj->name == 6)
		inter = ft_sphere(*ray, obj);
	else if (obj->name == 7)
		inter = ft_damier(*ray, obj);
	return (inter);
}

int			ft_inter_obj(t_scene *s, t_ray *ray)
{
	t_obj	*tmp;

	tmp = s->obj;
	ray->t = LIM;
	ray->obj = new_list();
	while (tmp)
	{
		if (tmp != ray->objref)
		{
			ft_get_inter(ray, tmp);
			if (ray->t > tmp->t)
			{
				if (tmp->name == DAM)
					tmp->color = ft_damcolor(tmp);
				ray->t = tmp->t;
				ray->color = ft_mul_vec_scal(tmp->color, s->ambiante);
				ray->obj = tmp;
			}
		}
		tmp = tmp->next;
	}
	return (ray->t < LIM) ? 1 : 0;
}
