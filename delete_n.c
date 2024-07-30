/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:09:56 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/30 14:09:56 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	poww(int num)
{
	int	i;

	i = 2;
	if (num == 1)
		return (1);
	while (i < num)
	{
		if (i * i == num)
			return (i);
		i ++;
	}
	return (-1);
}

void	ass_the_starts(int *j_start, int *i_start, int i, int j)
{
	*i_start = i;
	*j_start = j;
}

void	delete_n(t_hero *hero, int i, int j, int sum)
{
	int		i_start;
	int		j_start;
	int		tmp;
	char	c;

	while (hero->map[++ i])
	{
		j = -1;
		while (hero->map[i][++ j])
		{
			if (hero->map[i][j] == 'N' || hero->map[i][j] == 'S'
				|| hero->map[i][j] == 'E' || hero->map[i][j] == 'W')
			{
				c = hero->map[i][j];
				hero->map[i][j] = '0';
				sum ++;
			}
			if (sum == 1)
				ass_the_starts(&j_start, &i_start, i, j);
		}
	}
	tmp = poww(sum) / 2;
	if (tmp + i_start < i && ft_strlen(hero->map[i_start]) > tmp + j_start)
		hero->map[tmp + i_start][tmp + j_start] = c;
}
