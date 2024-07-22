#include "cub3d.h"

int	main(void)
{
	t_map	map;
	t_hero	hero;

	initilize_map(&map);
	read_map(&map);
	ext_map(&hero);
	checker(&hero, &map);
	delete_n(&hero, -1, 0, 0);

	find_start(&hero);
	calc_axis(&hero, 'y');
	calc_axis(&hero, 'x');
	calc_viev(&hero);
	hero.ma = &map;
	create_win(&hero);
	
	free_list(hero.map);
	free_map(&map);

	printf("The map is ok, the program finished!");
}
