/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:48:15 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:36 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_one_filar(t_core *main_struct, t_tex *tex)
{
	tex->j = -1;
	tex->wall = main_struct->hero->walls_2[tex->wid][0] / 10000;
	tex->x1 = 0;
	tex->check = ass_check(tex->wall);
	calc_for_hig1(tex, main_struct);
	tex->t_w = tex->wid;
	tex->r_hig = tex->hig;
	if (tex->hig > HEIGHT)
		tex->hig = HEIGHT;
	tex->tmph = tex->hig;
	tex->tmpe = (HEIGHT - tex->tmph) / 2;
	tex->j = HEIGHT / 2;
	draw_ceiling(main_struct, tex);
	if (tex->hig1 < 0 && tex->finit++ == 0)
		tex->x = ft_abs(tex->x1 - main_struct->hero
				->walls_2[tex->wid][tex->check])
			* SIZE_N / POW;
	draw_walls(tex, main_struct);
	draw_floor(main_struct, tex);
	main_struct->wid += 1;
}

void	write_data_to_tex(t_tex *tex, t_core *main_struct, int len)
{
	tex->i = -1;
	tex->col = 0;
	tex->x = 0;
	tex->init = 0;
	tex->finit = 0;
	tex->wall = main_struct->hero->walls_2[tex->i + 1][0] / 10000;
	tex->check = ass_check(tex->wall);
	tex->len = len;
	tex->wid = 0;
}

void	put_filars(t_core *main_struct, int *lista, int len)
{
	t_tex	tex;
	int		i;

	i = -1;
	write_data_to_tex(&tex, main_struct, len);
	mlx_destroy_image(main_struct->con, main_struct->img);
	main_struct->img = mlx_new_image(main_struct->con, WIDTH, HEIGHT);
	main_struct->addr = mlx_get_data_addr(main_struct->img,
			&main_struct->bits_per_pixel,
			&main_struct->line_length, &main_struct->endian);
	if (tex.wall == 1 || tex.wall == 2)
		tex.x = main_struct->hero->walls_2[i + 1][tex.check] % POW;
	else
		tex.x = POW - main_struct->hero->walls_2[i + 1][tex.check] % POW;
	tex.x = SIZE_N * tex.x / POW;
	while (++i < len)
	{
		tex.hig = lista[i];
		tex.wid = main_struct->wid;
		put_one_filar(main_struct, &tex);
		tex.col ++;
	}
	mlx_put_image_to_window(main_struct->con, main_struct->win,
		main_struct->img, 0, 0);
	main_struct->wid = 0;
}

void	create_win(t_core *main_struct)
{
	main_struct->wid = 0;
	main_struct->con = mlx_init();
	write_textures(main_struct);
	main_struct->win = mlx_new_window(main_struct->con, WIDTH, HEIGHT, "cub3d");
	main_struct->img = mlx_new_image(main_struct->con, WIDTH, HEIGHT);
	main_struct->addr = mlx_get_data_addr(main_struct->img,
			&main_struct->bits_per_pixel,
			&main_struct->line_length, &main_struct->endian);
	display_the_win(main_struct);
}

void	display_the_win(t_core *main_struct)
{
	int	len;

	len = sizeof(main_struct->hero->vision_2) / 4;
	put_filars(main_struct, main_struct->hero->vision_2, len);
	mlx_hook(main_struct->win, 17, 0L, mlx_loop_end, main_struct->con);
	mlx_hook(main_struct->win, 2, 1L << 0, my_key_hook, main_struct);
	mlx_loop(main_struct->con);
	close_window(main_struct);
}
