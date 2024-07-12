#include "cub3d.h"

int	main(void)
{
	// int lista[] = {90, 90, 90, 89, 89, 89, 88, 88, 87, 87, 86, 86, 85, 84, 84, 83, 82, 82, 81, 80, 79, 78, 77, 76, 74, 74, 72, 60, 61, 61, 61, 60, 58, 53, 50, 45, 41, 41, 41, 41, 41, 41, 41, 41, 41, 40, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 45, 49, 53, 57, 59, 62, 65, 67, 69, 71, 72, 73, 75, 76, 77, 78, 79, 80, 81, 81, 82, 83, 84, 84, 85, 85, 86, 86, 87, 87, 88, 88, 89, 89};
	// t_core	main_struct;

	// main_struct.con = mlx_init();
	// main_struct.win = mlx_new_window(main_struct.con, WIDTH, HEIGHT, "cub3d");
	// main_struct.img = mlx_new_image(main_struct.con, WIDTH, HEIGHT);
	// for (unsigned long  i = 0; i < sizeof(lista) / 4; i ++)
	// 	printf("%d\n", lista[i]);
	// printf("%zu", ft_strlen("tak"));

	t_hero hero;
	char *map_string;

	map_string = malloc(10000);

	int fd = open("map_test", O_RDONLY);
	read(fd, map_string, 10000);
	// printf("%s\n", map_string);
	hero.map = ft_split(map_string, '\n');
	find_start(&hero);
	// printf("%d, %d, \n", hero.pos[0], hero.pos[1]);
	// printf("%c \n", hero.map[hero.pos[0]][hero.pos[1]]);
	calc_axis(&hero, 'y');
	calc_axis(&hero, 'x');
	calc_viev(&hero);
	// print_map(&hero);
	free(map_string);
}
