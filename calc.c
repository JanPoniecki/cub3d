/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:17:33 by jponieck          #+#    #+#             */
/*   Updated: 2024/07/31 11:13:57 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_height(t_hero *hero, t_axis *axis, int i)
{
	int		a;
	int		b;
	float	c;
	int		ang;

	ang = -V_RANGE + i;
	a = ft_abs(axis->colision[0] - hero->pos[0]);
	b = ft_abs(axis->colision[1] - hero->pos[1]);
	c = sqrt(a * a + b * b);
	c = c * sine(90 - ang);
	a = c;
	a = (int)round(c);
	return (DIVIDER / (a * 0.7));
}

void	get_collision(t_hero *hero, int angle, int i)
{
	t_axis	axis;
	int		height;

	init_collision_vars(hero, &axis, angle);
	find_collision(hero, &axis, i);
	height = calc_height(hero, &axis, i);
	hero->vision[V_RANGE * 2 - 1 - i] = height;
}

void	check_neighbour_1(t_hero *hero, int i, int w, int h)
{
	h = 0;
	if (i > 0)
	{
		if (hero->walls[i - 1] / 10000 == 1 || hero->walls[i - 1] / 10000 == 3)
		{
			if (ft_abs(hero->walls[i - 1] % 10000 - hero->walls_c[i][0]) <= 1)
			{
				hero->vision[i - 1] = hero->vision[i];
				w = hero->walls[i - 1];
				while (hero->walls[i] / 10000 > 4)
				{
					hero->walls[i] = w;
					i ++;
				}
			}
		}
	}
}

void	write_to_walls_2(t_hero *hero, int i)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (i < V_RANGE * 2)
	{
		while (j < FILWI)
		{
			hero->vision_2[k] = hero->vision[i];
			hero->walls_2[k][0] = hero->walls[i];
			hero->walls_2[k][1] = hero->walls_c[i][0];
			hero->walls_2[k][2] = hero->walls_c[i][1];
			j ++;
			k ++;
		}
		j = 0;
		i ++;
	}
}

void	calc_viev(t_hero *hero)
{
	int	angle;
	int	i;

	angle = hero->angle - V_RANGE;
	i = 0;
	while (i != V_RANGE * 2)
	{
		get_collision(hero, angle, i);
		i ++;
		angle ++;
	}
	write_to_walls_2(hero, 0);
	fine_tune_view(hero);
}
