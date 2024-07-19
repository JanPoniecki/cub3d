#include "cub3d.h"
#include <string.h>

int	main(void)
{
	t_map	map;
	t_hero	hero;
	t_core		main_str;

	main_str.hero = malloc(sizeof(t_hero));
	ft_memset(main_str.hero, 0, sizeof(t_hero));
	main_str.hero->ma = malloc(sizeof(t_map));
	initilize_map(main_str.hero->ma);
	read_map(main_str.hero->ma);
	checker(main_str.hero, main_str.hero->ma);
	ext_map(main_str.hero);
	printf("%s", main_str.hero->ma->no);
	return (0);
	main_str.con = mlx_init();
	main_str.win = mlx_new_window(main_str.con, 1000, 1000, "tmp");
	write_textures(&main_str);
	// main_str.img = mlx_new_image(main_str.con, 1000, 1000);
	// void	*texture;
	// int		bits_per_pixel;
	// int		size_line;
	// int		endian;
	// char	*relative_path = "./path_to_the_north.xpm";
	// int		img_width = 64;
	// int		img_height = 64;
	// int		texture_buffer[64][64];
	
	
	// img->addr[y * img->width + x];
	// texture_buffer[n][y * 64 + x]
	// texture_buffer[0][0] = 3484963;
	// imgg = mlx_new_image(mlx, 100, 100);
	// addr = mlx_get_data_addr();


	// main_str.addr = mlx_get_data_addr(main_str.img, &main_str.bits_per_pixel,
	// 	&main_str.line_length, &main_str.endian);
	// texture = mlx_xpm_file_to_image(main_str.con, relative_path, &img_width, &img_height);
	// main_str.addr = mlx_get_data_addr(texture, &bits_per_pixel, &size_line, &endian);
	// int	pos;
	// int	red = ((*(unsigned int *)(main_str.addr + pos)) >> 16) & 0xFF;
	// int	blu = ((*(unsigned int *)(main_str.addr + pos)) & 0xFF);
	// int	gre = ((*(unsigned int *)(main_str.addr + pos)) >> 8) & 0xFF;


	int	y = -1;
	int	x = -1;
	// while (++ y < img_height)
	// {
	// 	x = -1;
	// 	while (++ x < img_width)
	// 	{
	// 		pos = (y * size_line + x * (bits_per_pixel / 8));
	// 		texture_buffer[y][x] = (*(unsigned int *)(main_str.addr + pos));
	// 		// printf("x = %d, y = %d, color: %d\n", x, y, (*(unsigned int *)(main_str.addr + pos)));
	// 	}
	// }
	// if (texture == NULL)
	// 	printf("cos jest nie tak");
	write_texture(&main_str, "./path_to_the_north.xpm", 64, main_str.tex.n);
	// printf("%d", main_str.tex.n[63][63]);
	// exit(0);
	// mlx_put_image_to_window(main_str.con, main_str.win, texture, 0, 0);
	// mlx_destroy_image(main_str.con, main_str.img);
	main_str.img = mlx_new_image(main_str.con, 1000, 1000);
	main_str.addr = mlx_get_data_addr(main_str.img, &main_str.bits_per_pixel, &main_str.line_length, &main_str.endian);
	y = -1;
	int i = -1;
	int j = -1;
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
	mlx_put_image_to_window(main_str.con, main_str.win, main_str.img, 0, 0);
	mlx_loop(main_str.con);
	// powiekszanie 2 razy
	int z = 0;
	i = 0;
	int	tmp;
	tmp = i;
	while (i < 500)
	{
		z = 0;
		while (z < 2)
		{
			x = 0;
			j = 63;
			y = tmp % 64;
			printf("%d\n", y);
			while (++ j < 128)
			{
				my_mlx_pixel_put(&main_str, j, i, main_str.tex.n[y][x]);
				x ++;
			}
			x = 0;
			j = 127;
			y = tmp % 64;
			printf("%d\n", y);
			while (++ j < 192)
			{
				my_mlx_pixel_put(&main_str, j, i, main_str.tex.n[y][x]);
				x ++;
			}
			i ++;
			z ++;
		}
		tmp ++;
		y ++;
	}

	// pomniejszanie 2 razy
	// z = 0;
	// i = 0;
	// tmp = i;
	// while (i < 64)
	// {
	// 	j = 63;
	// 	y = tmp % 64;
	// 	x = 0;
	// 	while (++ j < 128)
	// 	{
	// 		my_mlx_pixel_put(&main_str, j, i, texture_buffer[y][x]);
	// 		x ++;
	// 	}
	// 	i ++;
	// 	tmp += 2;
	// 	// y ++;
	// }
	
	mlx_put_image_to_window(main_str.con, main_str.win, main_str.img, 0, 0);
	mlx_loop(main_str.con);


	// initilize_map(&map);
	// read_map(&map);
	// ext_map(&hero);
	// checker(&hero, &map);

	// find_start(&hero);
	// calc_axis(&hero, 'y');
	// calc_axis(&hero, 'x');
	// calc_viev(&hero);
	// hero.ma = &map;
	// create_win(&hero);

	// free_list(hero.map);
	// free_map(&map);

	// printf("The map is ok, the program finished!");
}
