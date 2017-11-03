/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 05:01:14 by akerkeb           #+#    #+#             */
/*   Updated: 2017/11/03 05:01:17 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_normal(t_xyz *vec)
{
	float norme;

	norme = 1 / ft_mag_vec(*vec);
	if (norme)
	{
		vec->x *= norme;
		vec->y *= norme;
		vec->z *= norme;
	}
}

t_xyz		ft_sub_vec(t_xyz a, t_xyz b)
{
	t_xyz	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_xyz		ft_scal(t_xyz a, float b)
{
	t_xyz	res;

	res.x = (a.x * b);
	res.y = (a.y * b);
	res.z = (a.z * b);
	return (res);
}

t_xyz		ft_add_vec(t_xyz a, t_xyz b)
{
	t_xyz	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_xyz		ft_mul_vec(t_xyz a, t_xyz b)
{
	t_xyz	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}
