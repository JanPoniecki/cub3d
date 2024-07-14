/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:17:54 by jponieck          #+#    #+#             */
/*   Updated: 2024/07/13 20:44:28 by jponieck         ###   ########.fr       */
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