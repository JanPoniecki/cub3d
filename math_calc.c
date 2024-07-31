/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:25:38 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 10:27:06 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bzero_axis(t_hero *hero, int size, char type)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (type == 'y')
			hero->y_axis[i][0] = -1;
		else
			hero->x_axis[i][0] = -1;
		i ++;
	}
}

double	cosine(int angle)
{
	double	rads;

	rads = angle * (M_PI / 180.0);
	return (cos(rads));
}

double	sine(int angle)
{
	double	rads;

	rads = angle * (M_PI / 180.0);
	return (sin(rads));
}

int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

void	re_init_axis(t_hero *hero, int rotation)
{
	if (rotation == -180)
	{
		bzero_axis(hero, 500, 'y');
		hero->y_index = 0;
	}
	else
	{
		bzero_axis(hero, 500, 'x');
		hero->x_index = 0;
	}
}
