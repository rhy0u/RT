/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <jcentaur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 02:28:58 by jcentaur          #+#    #+#             */
/*   Updated: 2017/10/18 03:50:04 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xyz filter(t_xyz color, int filter)
{
    t_xyz   res;
    if (!filter)
        return color;
    if (filter == 1)
    {
        res.x = (color.x + color.y + color.y) / 3;
        res.y = (color.x + color.y + color.y) / 3;
        res.z = (color.x + color.y + color.y) / 3;
        return (res);
    }
    if (filter == 2)
    {
        res.x = 255 - color.x;
        res.y = 255 - color.y;
        res.z = 255 - color.z;
        return (res);
    }
    if (filter == 3)
    {
        res.x = color.x * 0.393 + color.y * 0.769 + color.z * 0.189;
        res.y = color.x * 0.349 + color.y * 0.686 + color.z * 0.168;
        res.z = color.x * 0.272 + color.y * 0.534 + color.z * 0.131;
        return (res);
	}
}
