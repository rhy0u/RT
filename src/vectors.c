/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 05:00:53 by akerkeb           #+#    #+#             */
/*   Updated: 2017/11/03 05:01:02 by akerkeb          ###   ########.fr       */
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
