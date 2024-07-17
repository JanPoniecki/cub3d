#include "cub3d.h"

int	main(void)
{
	t_map	map;
	t_hero	hero;

	initilize_map(&map);
	read_map(&map);
	ext_map(&hero);
	checker(&hero, &map);

	find_start(&hero);
	calc_axis(&hero, 'y');
	calc_axis(&hero, 'x');
	calc_viev(&hero);
	hero.ma = &map;
	printf("%s\n", map.no);
	printf("%s\n", map.so);
	printf("%s\n", map.we);
	printf("%s\n", map.ea);
	printf("%s\n", map.f[0]);
	printf("%s\n", map.f[1]);
	printf("%s\n", map.f[2]);
	printf("%s\n", map.c[0]);
	printf("%s\n", map.c[1]);
	printf("%s\n", map.c[2]);
	printf("%s\n", map.ceiling);
	printf("%s\n", map.floor);
	create_win(&hero);
	
	free_list(hero.map);
	free_map(&map);

	printf("The map is ok, the program finished!");
}
