/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:17:54 by jponieck          #+#    #+#             */
/*   Updated: 2024/07/24 20:59:11 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_hero *hero)
{
	int	i;

	i = 0;
	while(hero->map[i])
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

// int	darken_color(int color, int darkener)
// {
// 	char	*colors;

// 	colors = (char *)&color;
// 	colors[0] -= darkener;
// 	colors[1] -= darkener;
// 	colors[2] -= darkener;
// 	colors[3] = 0;
// 	if (colors[0] < 0)
// 		colors[0] = 0;
// 	if (colors[1] < 0)
// 		colors[1] = 0;
// 	if (colors[2] < 0)
// 		colors[2] = 0;
// 	return (*(int *)colors);
// }

int darken_color(int color, int darkener) {
    unsigned char red, green, blue;
    
    // Wyodrębnij składowe koloru
    red = (color >> 16) & 0xFF;
    green = (color >> 8) & 0xFF;
    blue = color & 0xFF;
    
    // Zmniejsz składowe koloru, upewniając się, że nie przekroczą zakresu
    if (darkener > red) red = 0; else red -= darkener;
    if (darkener > green) green = 0; else green -= darkener;
    if (darkener > blue) blue = 0; else blue -= darkener;
    
    // Złóż kolor z powrotem
    return (red << 16) | (green << 8) | blue;
}
