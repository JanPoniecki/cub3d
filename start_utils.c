/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:42:47 by jponieck          #+#    #+#             */
/*   Updated: 2024/07/11 23:20:10 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				hero->angle = 45;
				hero->map[crd[0]][crd[1]] = '0';
				return ;
			}
			crd[1] ++;
		}
		crd[1] = 0;
		crd[0] ++;
	}
}