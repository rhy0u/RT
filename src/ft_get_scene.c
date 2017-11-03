/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:22:48 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/11/03 02:47:18 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		get_cam(t_scene *s, char *str)
{
	int i;

	i = 0;
	while (str[i] && (ft_strncmp("</camera>", &str[i], 9)))
	{
		if (!ft_strncmp("<origine>", &str[i], 9))
			s->cam.pos = get_xyz(&str[i]);
		else if (!ft_strncmp("<look_at>", &str[i], 9))
			s->cam.look_at = get_xyz(&str[i]);
		else if (!ft_strncmp("<ambiante>", &str[i], 10))
			s->ambiante = get_float(&str[i]);
		i++;
	}
}

static void	get_objets_bis(t_scene *scene, char *str, int i)
{
	if (ft_strncmp("name=\"sphere\">", &str[i], 14) == 0)
		list_push_back(&scene->obj, list_sphere(&str[i]));
	else if (ft_strncmp("name=\"cone\">", &str[i], 12) == 0)
		list_push_back(&scene->obj, list_cone(&str[i]));
	else if (ft_strncmp("name=\"cylindre\">", &str[i], 16) == 0)
		list_push_back(&scene->obj, list_cyl(&str[i]));
	else if (ft_strncmp("name=\"plane\">", &str[i], 13) == 0)
		list_push_back(&scene->obj, list_plane(&str[i]));
	else if (ft_strncmp("name=\"disk\">", &str[i], 12) == 0)
		list_push_back(&scene->obj, list_disk(&str[i]));
	else if (ft_strncmp("name=\"spot\">", &str[i], 12) == 0)
		list_push_back(&scene->obj, list_spot(&str[i]));
	else if (ft_strncmp("name=\"damier\">", &str[i], 14) == 0)
		list_push_back(&scene->obj, list_damier(&str[i]));
}

void		get_objets(t_scene *scene, char *str)
{
	int i;

	clear_cam(scene);
	scene->obj = NULL;
	i = 0;
	while (str[i])
	{
		if (!ft_strncmp("<object", &str[i], 7))
		{
			while (str[i] && str[i] != '>')
			{
				get_objets_bis(scene, str, i);
				i++;
			}
		}
		i++;
	}
}

void		get_spot(t_scene *scene, char *str)
{
	int i;

	scene->spot = NULL;
	i = 0;
	while (str[i])
	{
		if (!ft_strncmp("<spot>", &str[i], 6))
			list_add_spot(&scene->spot, spot(&str[i]));
		i++;
	}
}

void		ft_get_scene(t_scene *scene, int fd)
{
	int		ret;
	char	buff[BUFF_SIZE];
	char	*str;

	str = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return ;
		buff[ret] = '\0';
		str = ft_strjoinf(str, buff);
	}
	get_cam(scene, str);
	get_spot(scene, str);
	get_objets(scene, str);
	free(str);
	close(fd);
}
