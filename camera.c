/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:18:04 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/19 02:49:51 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_cal_vec_cam(t_scene *s, t_cam *c)
{
	c->up_vec = ft_vect(0, -1, 0);
	c->right_vec = ft_vect(1, 0, 0);
	c->look_at = s->cam.look_at;
	c->vec_dir = ft_sub_vec(c->look_at, s->cam.pos);
	ft_normal(&c->vec_dir);
	if (s->cam.pos.x != s->cam.look_at.x || s->cam.pos.z != s->cam.look_at.z)
	{
		c->right_vec = ft_cross_vec(c->vec_dir, c->up_vec);
		ft_normal(&c->right_vec);
		c->up_vec = ft_mul_vec_scal(ft_cross_vec(c->right_vec, c->vec_dir), -1);
	}
	else
	{
		c->up_vec = ft_cross_vec(c->vec_dir, c->right_vec);
		ft_normal(&c->up_vec);
		c->right_vec = ft_cross_vec(c->up_vec, c->vec_dir);
	}
	c->width = .5;
	c->ratio = .5;
	c->height = c->width * H / L;
}

t_xyz		ft_camera(t_scene *s, t_cam c, float x, float y)
{
	c.view_plane_up_left = ft_sub_vec(ft_add_vec(s->cam.pos, ft_add_vec(
				ft_mul_vec_scal(c.vec_dir, c.ratio), ft_mul_vec_scal(
				c.up_vec, c.height / 2.0))), ft_mul_vec_scal(c.right_vec,
				c.width / 2.0));
	c.xindent = c.width / (float)L * s->res;
	c.yindent = c.height / (float)H * s->res;
	return (ft_sub_vec(ft_add_vec(c.view_plane_up_left, ft_sub_vec(
					ft_mul_vec_scal(c.right_vec, c.xindent * x),
					ft_mul_vec_scal(c.up_vec, c.yindent * y))), s->cam.pos));
}
