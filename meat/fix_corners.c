/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_corners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:01:18 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:20 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_first(t_hero *hero, int i, int *check, int *wall)
{
	*wall = 5;
	if (hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] + 1] == '3')
	{
		*check = 1;
		*wall = 3;
	}
}

void	check_left_n(t_hero *hero, int i, int *l, int check)
{
	int	wall;

	if (i == 0)
		return ;
	check_first(hero, i, &check, &wall);
	if (hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] - 1] == '1')
	{
		check = 1;
		wall = 1;
	}
	if (hero->map[hero->walls_2[i][1] - 1][hero->walls_2[i][2]] == '2')
	{
		check = 2;
		wall = 2;
	}
	if (hero->map[hero->walls_2[i][1] + 1][hero->walls_2[i][2]] == '4')
	{
		check = 2;
		wall = 4;
	}
	if (hero->walls_2[i - 1][check] == hero->walls_2[i][check]
			&& hero->walls_2[i - 1][0] / 10000 == wall)
		*l = 1;
}

void	check_two_last(t_hero *hero, int i, int *check, int *wall)
{
	if (hero->map[hero->walls_2[i][1] - 1][hero->walls_2[i][2]] == '4')
	{
		*check = 2;
		*wall = 4;
	}
	if (hero->map[hero->walls_2[i][1] + 1][hero->walls_2[i][2]] == '2')
	{
		*check = 2;
		*wall = 2;
	}
}

void	check_right_n(t_hero *hero, int i, int *r, int check)
{
	int	wall;
	int	corner;

	wall = 5;
	corner = hero->walls_2[i][0];
	while (hero->walls_2[i][0] == corner && i < V_RANGE * 2 * FILWI)
		i ++;
	i --;
	if (hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] + 1] == '1')
	{
		check = 1;
		wall = 1;
	}
	if (hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] - 1] == '3')
	{
		check = 1;
		wall = 3;
	}
	check_two_last(hero, i, &check, &wall);
	if (hero->walls_2[i + 1][check] == hero->walls_2[i][check]
			&& hero->walls_2[i + 1][0] / 10000 == wall)
		*r = 1;
}

void	fix_corners(t_hero *hero, int i)
{
	int	l;
	int	r;
	int	corner;

	while (i < V_RANGE * 2 * FILWI)
	{
		l = 0;
		r = 0;
		if (hero->walls_2[i][0] / 10000 == 9)
		{
			corner = hero->walls_2[i][0];
			check_left_n(hero, i, &l, 0);
			check_right_n(hero, i, &r, 0);
			overwrite_corner(hero, i, l, r);
			while (hero->walls_2[i][0] == corner)
				i++;
		}
		i ++;
	}
}
