#include "cub3d.h"
#include <string.h>

int	main(void)
{
	t_map	map;
	t_hero	hero;
	t_core	main_str;

	main_str.hero = malloc(sizeof(t_hero));
	ft_memset(main_str.hero, 0, sizeof(t_hero));
	main_str.hero->ma = malloc(sizeof(t_map));
	initilize_map(main_str.hero->ma);
	read_map(main_str.hero->ma);
	// checker(main_str.hero, main_str.hero->ma);
	ext_map(main_str.hero);
	main_str.con = mlx_init();
	main_str.win = mlx_new_window(main_str.con, 1000, 1000, "tmp");
	write_textures(&main_str);
	int	y = -1;
	int	x = -1;
	while (++ y < 64)
	{
		x = -1;
		while (++ x < 64)
			printf("y = %d, x = %d, var = %d\n", y, x, main_str.tex.s[y][x]);
	}
	main_str.img = mlx_new_image(main_str.con, 1000, 1000);
	main_str.addr = mlx_get_data_addr(main_str.img, &main_str.bits_per_pixel, &main_str.line_length, &main_str.endian);
	
	int z = 0;
	int i = 0;
	int	tmp;
	tmp = i;
	int j;
	
	y = -1;
	i = -1;
	j = -1;
	while (++ i < 64)
	{
		j = -1;
		x = -1;
		y = i % 64;
		while (++ j < 64)
		{
			my_mlx_pixel_put(&main_str, j, i, main_str.tex.n[y][x]);
			x ++;
		}
		y ++;
	}
	reduce_the_texture(&main_str, main_str.tex.n);
	// expand_the_texture(&main_str, main_str.tex.n);
	
	mlx_put_image_to_window(main_str.con, main_str.win, main_str.img, 0, 0);
	mlx_loop(main_str.con);
}
