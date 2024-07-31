/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myjob.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:32:16 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 09:57:31 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook_helper(int keycode, t_core *mlx)
{
	int	len;

	if (keycode == 65307)
	{
		close_window(mlx);
		return (1);
	}
	else if (keycode == 119)
	{
		move_on_y(mlx, 1);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
		return (1);
	}
	else if (keycode == 115)
	{
		move_on_y(mlx, -1);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
		return (1);
	}
	return (-1);
}

int	my_key_hook(int keycode, t_core *mlx)
{
	int	len;

	if (key_hook_helper(keycode, mlx) == 1)
		len = -1;
	else if (keycode == 97)
	{
		move_on_x(mlx, -1);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
	else if (keycode == 100)
	{
		move_on_x(mlx, 1);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
	for_arrows(keycode, mlx);
	return (0);
}

void	draw_walls(t_tex *tex, t_core *main_struct)
{
	int	n;

	n = (tex->r_hig - tex->hig) / 2;
	tex->j = tex->tmpe;
	while (++ tex->j < tex->tmpe + tex->tmph)
	{
		tex->wid = tex->t_w - 1;
		while (++ tex->wid < 1 + tex->t_w)
		{
			if (tex->init == 0 || tex->hig1 < 0)
				my_mlx_pixel_put(main_struct, tex->wid, tex->j,
					set_color(main_struct, n, tex->x, tex));
			else
				my_mlx_pixel_put(main_struct, tex->wid, tex->j,
					set_color(main_struct, n, 1, tex));
			n ++;
		}
	}
}

void	draw_ceiling(t_core *main_struct, t_tex *tex)
{
	int	a;

	a = -1;
	while (++a < tex->j)
	{
		tex->wid = tex->t_w;
		while (tex->wid < 1 + tex->t_w)
			my_mlx_pixel_put(main_struct, tex->wid ++, a,
				my_strtol(main_struct->hero->ma->ceiling));
	}
}

void	draw_floor(t_core *main_struct, t_tex *tex)
{
	tex->j = tex->tmpe + tex->tmph;
	while (++tex-> j < HEIGHT)
	{
		tex->wid = tex->t_w;
		while (tex->wid < 1 + tex->t_w)
			my_mlx_pixel_put(main_struct, tex->wid ++, tex->j,
				my_strtol(main_struct->hero->ma->floor));
	}
}
