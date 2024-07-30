/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:35:41 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/30 13:36:12 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_core	main_str;

	main_str.hero = malloc(sizeof(t_hero));
	ft_memset(main_str.hero, 0, sizeof(t_hero));
	main_str.hero->ma = malloc(sizeof(t_map));
	ft_memset(main_str.hero->ma, 0, sizeof(t_map));
	initilize_map(main_str.hero->ma);
	read_map(main_str.hero, main_str.hero->ma);
	ext_map(main_str.hero);
	checker(main_str.hero, main_str.hero->ma);
	delete_n(main_str.hero, -1, 0, 0);
	find_start(main_str.hero);
	calc_axis(main_str.hero, 'y');
	calc_axis(main_str.hero, 'x');
	calc_viev(main_str.hero);
	create_win(&main_str);
	free_list(main_str.hero->map);
	free_map(main_str.hero->ma);
	free(main_str.hero);
	free(main_str.hero->ma);
}
