/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 22:01:22 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/05/15 17:57:53 by cmeaun-a         ###   ########.fr       */
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
