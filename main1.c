/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:55:20 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/16 17:13:54 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_map	map;
	t_hero	hero;

	initilize_map(&map);
	read_map(&map);

	ext_map(&hero);
	checker(&hero, &map);
	
	free_list(hero.map);
	free_map(&map);

	printf("The map is ok, the program finished!");
}

	// printf("%s\n", map.no);
	// printf("%s\n", map.so);
	// printf("%s\n", map.we);
	// printf("%s\n", map.ea);
	// printf("%s\n", map.f[0]);
	// printf("%s\n", map.c[0]);
