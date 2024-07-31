/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:54:37 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:37:03 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_window(t_core *mlx)
{
	mlx_destroy_image(mlx->con, mlx->img);
	mlx_destroy_window(mlx->con, mlx->win);
	mlx_destroy_display(mlx->con);
	free(mlx->con);
	free_list(mlx->hero->map);
	free_map(mlx->hero->ma);
	free(mlx->hero);
	free_list_int(mlx->tex.n, SIZE_N);
	free_list_int(mlx->tex.e, SIZE_N);
	free_list_int(mlx->tex.s, SIZE_N);
	free_list_int(mlx->tex.w, SIZE_N);
	exit (0);
}

// This function puts a pixel at a specific position on the screen.
// It calculates the address of the pixel and then sets its color.
void	my_mlx_pixel_put(t_core *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ass_check(int wall)
{
	if (wall == 1 || wall == 3)
		return (2);
	else
		return (1);
}

void	handle_corners(t_hero *hero)
{
	int	i;

	i = 0;
	while (i < V_RANGE * 2)
	{
		if (hero->walls[i] / 10000 > 4)
		{
			if (i > 0)
				check_neighbour_1(hero, i, 0, 0);
		}
		i ++;
	}
}
