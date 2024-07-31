/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myjob.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:32:16 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/30 16:13:20 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_filars(t_core *main_struct, int *lista, int len);
void	display_the_win(t_core *main_struct);

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
	free_list_int(mlx->tex.e, SIZE_E);
	free_list_int(mlx->tex.s, SIZE_S);
	free_list_int(mlx->tex.w, SIZE_W);
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

void	for_arrows(int keycode, t_core *mlx)
{
	int	len;

	if (keycode == 65361)
	{
		rotate(mlx, 4);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
	else if (keycode == 65363)
	{
		rotate(mlx, -4);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
}

int	num_of_col(t_core *main_struct, int wall, int i, int len, int *x1)
{
	int	check;
	int	num;

	num = 0;
	if (wall == 1 || wall == 3)
		check = 2;
	else
		check = 1;
	while (1)
	{
		if (i != 0 && ((wall == 1 || wall == 2)
				&& (main_struct->hero->walls_2[i - 1][0]
				!= main_struct->hero->walls_2[i][0]
			|| main_struct->hero->walls_2[i - 1][check] % POW
				> main_struct->hero->walls_2[i][check] % POW)))
			break ;
		else if (i != 0 && ((wall == 3 || wall == 4)
				&& (main_struct->hero->walls_2[i - 1][0]
				!= main_struct->hero->walls_2[i][0]
			|| main_struct->hero->walls_2[i - 1][check] % POW
				< main_struct->hero->walls_2[i][check] % POW)))
			break ;
		if (wall == 9)
			break ;
		i ++;
		num ++;
		if (i >= len)
		{
			num = -num;
			*x1 = main_struct->hero->walls_2[i - 1][check];
			break ;
		}
	}
	return (num);
}

int	ass_check(int wall)
{
	if (wall == 1 || wall == 3)
		return (2);
	else
		return (1);
}

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
		move_on_y(mlx, - 1);
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
		move_on_x(mlx, - 1);
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
// (t_core *main_struct, int hig, int n, 
// int col, int wall, int hig1, int x, t_tex *tex)

// 	set_color(main_struct, tex->r_hig, n, tex->col,
// 	tex->wall, tex->hig1, tex->x));
int set_color(t_core *main_struct, int n, int x, t_tex *tex)
{
	int darkener;

	tex->c = interpolation(tex->r_hig, SIZE_N - 1, n);
	if (tex->hig1 > 0)
		tex->e = interpolation(ft_abs(tex->hig1), SIZE_N - x, tex->col);
	else
		tex->e = interpolation(ft_abs(tex->hig1), x, tex->col);
	if (x > 1 && tex->hig1 > 0)
		tex->e += x;
	if (tex->wall == 1)
		tex->color = main_struct->tex.n[tex->c][tex->e % SIZE_N];
	else if (tex->wall == 2)
		tex->color = main_struct->tex.e[tex->c][tex->e % SIZE_N];
	else if (tex->wall == 3)
		tex->color = main_struct->tex.s[tex->c][tex->e % SIZE_N];
	else if (tex->wall == 4)
		tex->color = main_struct->tex.w[tex->c][tex->e % SIZE_N];
	darkener = tex->r_hig / 5;
	if (darkener > 125)
		darkener = 125;
	darkener = 125 - darkener;
	if (darkener > 5)
		tex->color = darken_color(tex->color, darkener);
	return tex->color;
}

void	calc_for_hig1(t_tex *tex, t_core *main_struct)
{
	if (tex->wid == 0)
		tex->hig1 = num_of_col(main_struct, tex->wall, 0, tex->len, &tex->x1);
	if (tex->wid != 0 && ((tex->wall == 1 || tex->wall == 2)
			&& (main_struct->hero->walls_2[tex->wid - 1][0]
			!= main_struct->hero->walls_2[tex->wid][0]
		|| main_struct->hero->walls_2[tex->wid - 1][tex->check] % POW
			> main_struct->hero->walls_2[tex->wid][tex->check] % POW)))
	{
		tex->col = 0;
		tex->hig1 = num_of_col(main_struct, tex->wall, tex->wid + 1,
				tex->len, &tex->x1);
		tex->init ++;
	}
	else if (tex->wid != 0 && ((tex->wall == 3 || tex->wall == 4)
			&& (main_struct->hero->walls_2[tex->wid - 1][0]
			!= main_struct->hero->walls_2[tex->wid][0]
		|| main_struct->hero->walls_2[tex->wid - 1][tex->check] % POW
			< main_struct->hero->walls_2[tex->wid][tex->check] % POW)))
	{
		tex->col = 0;
		tex->hig1 = num_of_col(main_struct, tex->wall, tex->wid + 1,
				tex->len, &tex->x1);
		tex->init ++;
	}
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
	main_struct->addr = mlx_get_data_addr(main_struct->img, &main_struct->bits_per_pixel,
			&main_struct->line_length, &main_struct->endian);
	display_the_win(main_struct);
}



void	display_the_win(t_core *main_struct)
{
	int	len;

	len = sizeof(main_struct->hero->vision_2) / 4;
	put_filars(main_struct, main_struct->hero->vision_2, len);
	mlx_hook(main_struct->win, 17, 0L, mlx_loop_end, main_struct->con);
	mlx_hook(main_struct->win, 2, 1L<<0, my_key_hook, main_struct);
	mlx_loop(main_struct->con);
	close_window(main_struct);
}
