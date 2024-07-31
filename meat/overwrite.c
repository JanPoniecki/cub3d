/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:20:32 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:33 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	overwrite_left(t_hero *hero, int i, int n)
{
	int	w;

	i = i - (n + 1);
	w = hero->walls_2[i][0];
	while (n > 0 && i < V_RANGE * 2 * FILWI)
	{
		hero->walls_2[i][0] = w;
		i ++;
		n --;
	}
}

void	overwrite_right(t_hero *hero, int i, int n)
{
	int	w;

	w = hero->walls_2[i][0];
	while (n > 0 && i > 0)
	{
		hero->walls_2[i][0] = w;
		i --;
		n --;
	}
	i = 0;
	while (i < 30)
	{
		i ++;
	}
}

void	overwrite_both(t_hero *hero, int i, int n)
{
	int	w;

	overwrite_right(hero, i, n / 2);
	i = i - (n + 1);
	w = hero->walls_2[i][0];
	n = n / 2 + 1;
	while (n > 0 && i < V_RANGE * 2 * FILWI)
	{
		hero->walls_2[i][0] = w;
		i ++;
		n --;
	}
}

void	overwrite_corner(t_hero *hero, int i, int l, int r)
{
	int	n;
	int	corner;

	n = 0;
	corner = hero->walls_2[i][0];
	while (hero->walls_2[i][0] == corner && i > 0)
	{
		i++;
		n++;
	}
	if (l == 1 && r == 0)
		overwrite_left(hero, i, n);
	if (l == 0 && r == 1)
		overwrite_right(hero, i, n);
	if (l == 1 && r == 1)
		overwrite_both(hero, i, n);
}
