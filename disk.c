/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthouard <pthouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 03:38:06 by pthouard          #+#    #+#             */
/*   Updated: 2017/10/18 04:04:58 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_disk(t_ray ray, t_obj *obj)
{
	float	p;
	t_xyz	d;

	if (ft_plane(ray, obj))
	{
		d = ft_add_vec(ray.eye, ft_scal(ray.dir, obj->t));
		p = ft_mag_vec(ft_sub_vec(obj->pos, d));
		if (p > obj->radius)
		{
			obj->t = LIM;
			return (0);
		}
		return (1);
	}
	else
		return (0);
}
