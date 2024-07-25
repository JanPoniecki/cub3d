#include "cub3d.h"

void	put_filars(t_core *main_struct, int *lista, int len);
void	display_the_win(t_core *main_struct);

long	my_strtol(char *str)
{
	long	result = 0;
	int		shift = 0;
	int		digit;
	char	c;

	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str)
	{
		c = *str++;
		if (c >= '0' && c <= '9')
			digit = c - '0';
		else if (c >= 'a' && c <= 'f')
			digit = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			digit = c - 'A' + 10;
		else
			break;
		result = result * 16 + digit;
	}
	return result;
}

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

void for_arrows(int	keycode, t_core *mlx)
{
	if (keycode == 65361)
	{
		rotate(mlx, 4);
		int len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
	else if (keycode == 65363)
	{
		rotate(mlx, -4);
		int len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
}

int	my_key_hook(int keycode, t_core *mlx)
{
	int	len;

	if (keycode == 65307)
		close_window(mlx);
	else if (keycode == 119)
	{
		move_on_y(mlx, 1);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
	else if (keycode == 115)
	{
		move_on_y(mlx, - 1);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
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

int		set_color(t_core *main_struct, int hig, int i)
{
	int	trans;
	if (hig > 2000)
		trans = 0;
	else
		trans = 124 - hig / 1;
	if (trans < 0)
		trans = 0;
	if (main_struct->hero->walls_2[i][0] / 10000 == 1)
		return (int_color(0, 160 - trans, 218 - trans, 242 - trans));
	if (main_struct->hero->walls_2[i][0] / 10000 == 2)
		return (int_color(0, 242 - trans, 160 - trans, 167 - trans));
	if (main_struct->hero->walls_2[i][0] / 10000 == 3)
		return (int_color(0, 207- trans, 242 - trans, 160 - trans));
	if (main_struct->hero->walls_2[i][0] / 10000 == 4)
		return (int_color(0, 242- trans, 226 - trans, 160 - trans));
	else
		return (int_color(0, 200 - trans, 200 - trans, 200 - trans));
}

void	put_one_filar(t_core *main_struct, int i, int hig)
{
	int	j = -1;
	int	tmp = i;
	if (hig > HEIGHT)
		hig = HEIGHT;
	int	tmph = hig;
	int	tmpe = (HEIGHT - tmph) / 2;
	int	trans = set_color(main_struct, hig, i);
	j = HEIGHT / 2;
	// ceiling
	int	a = -1;
	while (++a < j)
	{
		i = tmp;
		while (i < 1 + tmp)
			my_mlx_pixel_put(main_struct, i ++, a, my_strtol(main_struct->hero->ma->ceiling));
	}

	// walls
	j = tmpe;
	while (++ j < tmpe + tmph)
	{
		i = tmp - 1;
		while (++ i < 1 + tmp)
			my_mlx_pixel_put(main_struct, i, j, main_struct->tex.e[j % 64][i % 64]);
	}

	// floor
	j = tmpe + tmph;
	while (++ j < HEIGHT)
	{
		i = tmp;
		while (i < 1 + tmp)
			my_mlx_pixel_put(main_struct, i ++, j, my_strtol(main_struct->hero->ma->floor));
	}
	main_struct->wid += 1;
}

void	put_filars(t_core *main_struct, int *lista, int len)
{
	int i = -1;
	mlx_destroy_image(main_struct->con, main_struct->img);
	main_struct->img = mlx_new_image(main_struct->con, WIDTH, HEIGHT);
	main_struct->addr = mlx_get_data_addr(main_struct->img, &main_struct->bits_per_pixel,
			&main_struct->line_length, &main_struct->endian);
	while (++i < len)
	{
		put_one_filar(main_struct, main_struct->wid, lista[i]);
		// printf("%d %d %d\n", main_struct->hero->walls_2[i][0],  main_struct->hero->walls_2[i][1], main_struct->hero->walls_2[i][2]);
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
// 	int lista[] = {90, 90, 90, 89, 89, 89, 88, 88, 87, 87, 86, 86, 85, 84, 84, 83, 82, 82, 81, 80, 79, 78, 77, 76, 74, 74,
// 		72, 60, 61, 61, 61, 60, 58, 53, 50, 45, 41, 41, 41, 41, 41, 41, 41, 41, 41, 40, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41,
// 		45, 49, 53, 57, 59, 62, 65, 67, 69, 71, 72, 73, 75, 76, 77, 78, 79, 80, 81, 81, 82, 83, 84, 84, 85, 85, 86, 86, 87, 87, 88, 88, 89, 89};
	int	len = sizeof(main_struct->hero->vision_2) / 4;

	// first put a image to window
	// write_textures(main_struct);
	put_filars(main_struct, main_struct->hero->vision_2, len);
	// the hooks
	// mlx_do_key_autorepeaton(main_struct->con);
	mlx_hook(main_struct->win, 17, 0L, mlx_loop_end, main_struct->con);
	mlx_hook(main_struct->win, 2, 1L<<0, my_key_hook, main_struct);
	// mlx_key_hook(main_struct->win, my_key_hook, main_struct);
	mlx_loop(main_struct->con);
	close_window(main_struct);
}