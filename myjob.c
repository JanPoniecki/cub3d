#include "cub3d.h"

void	close_window(t_core *mlx)
{
	mlx_destroy_image(mlx->con, mlx->img);
	mlx_destroy_window(mlx->con, mlx->win);
	mlx_destroy_display(mlx->con);
	free(mlx->con);
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

int	my_key_hook(int keycode, t_core *mlx)
{
	if (keycode == 65307)
		close_window(mlx);
	return (0);
}

void	put_one_filar(t_core *main_struct, int i, int hig)
{
	int	j = -1;
	int	tmp = i;
	int	tmph = (hig * HEIGHT) / 100;
	int	tmpe = (HEIGHT - tmph) / 2;
	j = HEIGHT / 2;
	while (++ j < tmpe + tmph)
	{
		i = tmp;
		while (i < FILWI + tmp)
			my_mlx_pixel_put(main_struct, i ++, j, 0x00FF00);
	}
	j = HEIGHT / 2 + 1;
	while (-- j > tmpe)
	{
		i = tmp;
		while (i < FILWI + tmp)
			my_mlx_pixel_put(main_struct, i ++, j, 0x00FFFF);
	}
	main_struct->wid += FILWI;
}

void	put_filars(t_core *main_struct)
{
	int lista[] = {90, 90, 90, 89, 89, 89, 88, 88, 87, 87, 86, 86, 85, 84, 84, 83, 82, 82, 81, 80, 79, 78, 77, 76, 74, 74,
		72, 60, 61, 61, 61, 60, 58, 53, 50, 45, 41, 41, 41, 41, 41, 41, 41, 41, 41, 40, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41,
		45, 49, 53, 57, 59, 62, 65, 67, 69, 71, 72, 73, 75, 76, 77, 78, 79, 80, 81, 81, 82, 83, 84, 84, 85, 85, 86, 86, 87, 87, 88, 88, 89, 89};
	int i = -1;
	int	len = sizeof(lista) / 4;
	while (++i < len)
		put_one_filar(main_struct, main_struct->wid, lista[i]);
}

int	main(void)
{
	t_core	main_struct;

	main_struct.wid = 0;
	main_struct.con = mlx_init();
	main_struct.win = mlx_new_window(main_struct.con, WIDTH, HEIGHT, "cub3d");
	main_struct.img = mlx_new_image(main_struct.con, WIDTH, HEIGHT);
	main_struct.addr = mlx_get_data_addr(main_struct.img, &main_struct.bits_per_pixel,
			&main_struct.line_length, &main_struct.endian);
	put_filars(&main_struct);
	mlx_put_image_to_window(main_struct.con, main_struct.win,
		main_struct.img, 0, 0);
	mlx_hook(main_struct.win, 17, 0L, mlx_loop_end, main_struct.con);
	mlx_key_hook(main_struct.win, my_key_hook, &main_struct);
	mlx_loop(main_struct.con);
	close_window(&main_struct);
}
