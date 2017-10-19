/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:39:35 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/18 04:04:37 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_cut_bis2(t_obj *s, float t1, float t2)
{
	if ((s->tcut > s->t1) && (s->tcut < s->t2))
		t1 = s->tcut;
	if (s->tcut > t2)
		s->t = LIM;
}

static void	ft_cut_bis(t_obj *s, float t1, float t2)
{
	if (s->dc == 0)
	{
		if (s->dw > 0)
		{
			s->t = LIM;
			return ;
		}
	}
	s->tcut = -s->dw / s->dc;
	if (s->dc < 0)
	{
		if ((s->tcut > t1) && (s->tcut < s->t2))
			s->t2 = s->tcut;
		if (s->tcut < t1)
			s->t = LIM;
	}
	else
		ft_cut_bis2(s, t1, t2);
}

void		ft_cut(t_ray r, t_obj *s)
{
	float	tmp;
	float	t1;
	float	t2;
	t_xyz	cutnorm;

	if (s->t1 > s->t2)
	{
		tmp = s->t1;
		s->t1 = s->t2;
		s->t2 = tmp;
	}
	t1 = s->t1;
	t2 = s->t2;
	cutnorm = s->cutnorm;
	if (s->cutisreal == 1)
		cutnorm = rot_all_inv(s->cutnorm, -s->rot.x, -s->rot.y, -s->rot.z);
	s->dc = ft_dot(ft_mul_vec(r.dir, cutnorm));
	s->dw = ft_dot(ft_mul_vec(ft_sub_vec(r.eye, s->cut), cutnorm));
	ft_cut_bis(s, t1, t2);
	if (t1 > t2)
		s->t = LIM;
	s->tcut = t1;
}
