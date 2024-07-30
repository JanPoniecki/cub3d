/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:42:47 by jponieck          #+#    #+#             */
/*   Updated: 2024/07/30 09:59:42 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_angle(t_hero *hero, char s)
{
	if (s == 'N')
		hero->angle = 180;
	if (s == 'S')
		hero->angle = 0;
	if (s == 'E')
		hero->angle = 90;
	if (s == 'W')
		hero->angle = -90;
}

void	find_start(t_hero *hero)
{
	int	crd[2];

	crd[0] = 0;
	crd[1] = 0;
	while (hero->map[crd[0]])
	{
		while (hero->map[crd[0]][crd[1]])
		{
			if (ft_strchr("NSEW", hero->map[crd[0]][crd[1]]))
			{
				hero->pos[0] = crd[0];
				hero->pos[1] = crd[1];
				set_angle(hero, hero->map[crd[0]][crd[1]]);
				hero->map[crd[0]][crd[1]] = '0';
				return ;
			}
			crd[1] ++;
		}
		crd[1] = 0;
		crd[0] ++;
	}
}

int	len_of_file(char *file)
{
	int		fd;
	int		i;
	char	*buf;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		free(buf);
		i ++;
	}
	close(fd);
	return (i);
}
