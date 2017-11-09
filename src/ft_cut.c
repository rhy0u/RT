/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:39:35 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/11/09 01:17:44 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_cut_bis(t_obj *s, float t1, float t2)
{
	s->tcut = -s->dw / s->dc;
	if (s->dc < 0)
	{
		if ((s->tcut > s->t1) && (s->tcut < s->t2))
			t2 = s->tcut;
		if (s->tcut < t1)
			s->t = LIM;
	}
	else
	{
		if ((s->tcut > s->t1) && (s->tcut < s->t2))
			t1 = s->tcut;
		if (s->tcut > t2)
			s->t = LIM;
	}
	if (t1 > t2)
	{
		s->t = LIM;
		return ;
	}
	else
		s->tcut = t1;
}

void			ft_cut(t_ray r, t_obj *s)
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
	s->dc = ft_dot(ft_mul_vec(r.dir, cutnorm));
	s->dw = ft_dot(ft_mul_vec(ft_sub_vec(r.eye, s->cut), cutnorm));
	if (s->dc == 0)
	{
		if (s->dw > 0)
		{
			s->t = LIM;
			return ;
		}
	}
	ft_cut_bis(s, t1, t2);
}
