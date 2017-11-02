/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 21:56:39 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/31 03:40:13 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_xyz		ft_div_vec(t_xyz a, t_xyz b)
{
	t_xyz	res;

	res.x = a.x / b.x;
	res.y = a.y / b.y;
	res.z = a.z / b.z;
	return (res);
}

t_xyz		ft_sqrt_vec(t_xyz a)
{
	t_xyz	res;

	res.x = sqrt(a.x);
	res.y = sqrt(a.y);
	res.z = sqrt(a.z);
	return (res);
}
