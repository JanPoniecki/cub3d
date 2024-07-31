/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:17:54 by jponieck          #+#    #+#             */
/*   Updated: 2024/07/31 11:58:46 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map(t_hero *hero)
{
	int	i;

	i = 0;
	while (hero->map[i])
	{
		printf("%s\n", hero->map[i]);
		i ++;
	}
}

int	int_color(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b)
{
	char	color[4];

	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = t;
	return (*(int *)color);
}

int	darken_color(int color, int darkener)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;
	if (!darkener)
		return (((red - 10) << 16) | ((green - 10) << 8) | (blue - 10));
	if (darkener > red)
		red = 0;
	else
		red -= darkener;
	if (darkener > green)
		green = 0;
	else
		green -= darkener;
	if (darkener > blue)
		blue = 0;
	else
		blue -= darkener;
	return ((red << 16) | (green << 8) | blue);
}
