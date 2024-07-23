/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:42:47 by jponieck          #+#    #+#             */
/*   Updated: 2024/07/22 12:15:43 by bkotwica         ###   ########.fr       */
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

// powiekszanie
void	expand_the_texture(t_core *main_str, int **texture)
{
	int z = 0;
	int i = 0;
	int	tmp;
	tmp = i;
	int j;
	int x = 0;
	int y = 0;
	while (i < 128)
	{
		z = 0;
		while (z < 2)
		{
			x = 0;
			j = 63;
			y = tmp % 64;
			while (++ j < 128)
			{
				my_mlx_pixel_put(main_str, j, i, texture[y][x]);
				x ++;
			}
			x = 0;
			j = 127;
			y = tmp % 64;
			while (++ j < 192)
			{
				my_mlx_pixel_put(main_str, j, i, texture[y][x]);
				x ++;
			}
			i ++;
			z ++;
		}
		tmp ++;
		y ++;
	}
}

void	reduce_the_texture(t_core *main_str, int **texture)
{
	int	z;
	int	i;
	int	tmp;
	int	j;
	int	y;
	int	x;

	z = 0;
	i = 0;
	tmp = i;
	while (i < 64)
	{
		j = 63;
		y = tmp % 64;
		x = 0;
		while (++ j < 128)
		{
			my_mlx_pixel_put(main_str, j, i, texture[y][x]);
			x ++;
		}
		i ++;
		tmp += 2;
	}
}
