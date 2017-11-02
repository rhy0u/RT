/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:13:44 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/06/07 00:10:38 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj		*new_list(void)
{
	return (NULL);
}

void		list_push_back(t_obj **li, t_obj *new)
{
	t_obj	*tmp;

	tmp = *li;
	if (!new)
		return ;
	if (!tmp)
	{
		*li = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		list_add_spot(t_spot **li, t_spot *new)
{
	t_spot	*tmp;

	tmp = *li;
	if (!new)
		return ;
	if (!tmp)
	{
		*li = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_spot		*spot(char *str)
{
	int		i;
	t_spot	*s;

	i = 1;
	s = NULL;
	if (!(s = (t_spot *)malloc(sizeof(t_spot))))
		return (NULL);
	while (str[i] && (ft_strncmp("</spot>", &str[i], 7)))
	{
		if (ft_strncmp("<origine>", &str[i], 9) == 0)
			s->pos = get_xyz(&str[i]);
		else if (ft_strncmp("<color>", &str[i], 7) == 0)
			s->color = get_xyz(&str[i]);
		else if (ft_strncmp("<diffuse>", &str[i], 9) == 0)
			s->diffuse = get_float(&str[i]);
		i++;
	}
	s->next = NULL;
	return (s);
}
