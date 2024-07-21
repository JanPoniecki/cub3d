#include "cub3d.h"

void	find_min_max(int start, int stop, t_hero *hero)
{
	int	min;
	int	max;
	int	i;

	i = start;
	min = 100000;
	max = 0;
	while (i <= stop)
	{
		if (hero->vision_2[i] < min)
			min = hero->vision_2[i];
		if (hero->vision_2[i] > max)
			max = hero->vision_2[i];
		i ++;
	}
	if (hero->vision_2[start] < hero->vision_2[stop])
		hero->vision_2[start] = min;
	else
		hero->vision_2[start] = max;
	if (hero->vision_2[start] > hero->vision_2[stop])
		hero->vision_2[stop] = min;
	else
		hero->vision_2[stop] = max;
}

// void	init_ft_vars(t_ft *ft, t_hero *hero)
// {
// 	ft->m1 = hero->vision[s];

// }

void	refine_part(int start, int stop, t_hero *hero)
{
	// t_ft	ft;

	find_min_max(start, stop, hero);
	int m1 = hero->vision_2[start];
	int m2 = hero->vision_2[stop];
	int height = hero->vision_2[start];
	int i = 0;
	float step;
	int steps = (stop - start);
	if (m1 == m2 || steps == 0)
		step = 0;
	else if (m1 > m2)
		step = (float)(m1 - m2) / (float)steps;
	else
		step = (float)(m2 - m1) / (float)steps;
	if (hero->vision_2[start] < hero->vision_2[stop])
	{
		while (start != stop)
		{
			hero->vision_2[start] = height + step * i;
			i ++;
			start ++;
		}
	}
	else
	{
		while (start != stop)
		{
			hero->vision_2[start] = height - step * i;
			i ++;
			start ++;
		}
	}
}

// void	check_left_n(t_hero *hero, int i, int *l, int check)
// {
// 	if (i == 0)
// 		return ;
// 	if (hero->walls_2[i - 1][0] / 10000 == 1 || hero->walls_2[i - 1][0] / 10000 == 3)
// 		check = 1;
// 	if (hero->walls_2[i - 1][0] / 10000 == 2 || hero->walls_2[i - 1][0] / 10000 == 4)
// 		check = 2;
// 	if (hero->walls_2[i - 1][check] == hero->walls_2[i][check])
// 	{
// 		*l = 1;
// 	}
// }

void	check_left_n(t_hero *hero, int i, int *l, int check)
{
	int	wall;

	if (i == 0)
		return ;
	wall = 5;
	if(hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] + 1] == '3')
	{
		check = 1;
		wall = 3;
	}
	if(hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] - 1] == '1')
	{
		check = 1;
		wall = 1;
	}
	if(hero->map[hero->walls_2[i][1] - 1][hero->walls_2[i][2]] == '2')
	{
		check = 2;
		wall = 2;
	}
	if(hero->map[hero->walls_2[i][1] + 1][hero->walls_2[i][2]] == '4')
	{
		check = 2;
		wall = 4;
	}
	if (hero->walls_2[i - 1][check] == hero->walls_2[i][check] && hero->walls_2[i - 1][0] / 10000 == wall)
	{
		// printf("i wall is %d, wall is %d, i - 1 is %d\n ", hero->walls_2[i][0], wall, hero->walls_2[i - 1][0]);
		*l = 1;
	}
}

void	check_right_n(t_hero *hero, int i, int *r, int check)
{
	int	wall;
	int	corner;

	wall = 5;
	corner = hero->walls_2[i][0];
	while (hero->walls_2[i][0] == corner && i < V_RANGE * 2 * FILWI)
		i ++;
	i --;
	if(hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] + 1] == '1')
	{
		check = 1;
		wall = 1;
	}
	if(hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] - 1] == '3')
	{
		check = 1;
		wall = 3;
	}
	if(hero->map[hero->walls_2[i][1] - 1][hero->walls_2[i][2]] == '4')
	{
		check = 2;
		wall = 4;
	}
	if(hero->map[hero->walls_2[i][1] + 1][hero->walls_2[i][2]] == '2')
	{
		check = 2;
		wall = 2;
	}
	if (hero->walls_2[i + 1][check] == hero->walls_2[i][check] && hero->walls_2[i + 1][0] / 10000 == wall)
	{
		// printf("i wall is %d, wall is %d, i + 1 is %d\n ", hero->walls_2[i][0], wall, hero->walls_2[i + 1][0]);
		*r = 1;
	}
}

// void	check_right_n(t_hero *hero, int i, int *r, int check)
// {
// 	while (hero->walls_2[i][0] / 10000 == 9 && i < V_RANGE * 2 * FILWI)
// 		i ++;
// 	i --;
// 	if(hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] - 1] == '3')
// 		check = 1;
// 	if(hero->map[hero->walls_2[i][1]][hero->walls_2[i][2] + 1] == '1')
// 		check = 1;
// 	if(hero->map[hero->walls_2[i + 1][1]][hero->walls_2[i][2]] == '2')
// 		check = 2;
// 	if(hero->map[hero->walls_2[i - 1][1]][hero->walls_2[i][2]] == '4')
// 		check = 2;
// 	if (hero->walls_2[i][check] == hero->walls_2[i - 1][check])
// 	{
// 		*r = 1;
// 	}
// }

void	overwrite_left(t_hero *hero, int i, int n)
{
	int	w;

	i = i - (n + 1);
	w = hero->walls_2[i][0];
	while(n > 0 && i < V_RANGE * 2 * FILWI)
	{
		hero->walls_2[i][0] = w;
		i ++;
		n --;
	}
}

void	overwrite_right(t_hero *hero, int i, int n)
{
	int	w;

	w = hero->walls_2[i][0];
	while (n > 0 && i > 0)
	{
		hero->walls_2[i][0] = w;
		i --;
		n --;
	}
	i = 0;
	while (i < 30)
	{
		i ++;
	}
}

void	overwrite_both(t_hero *hero, int i, int n)
{
	int	w;

	overwrite_right(hero, i, n / 2);
	i = i - (n + 1);
	w = hero->walls_2[i][0];
	n = n / 2 + 1;
	while(n > 0 && i < V_RANGE * 2 * FILWI)
	{
		hero->walls_2[i][0] = w;
		i ++;
		n --;
	}

}

void	overwrite_corner(t_hero *hero, int i, int l, int r)
{
	int	n;
	int	corner;

	n = 0;
	corner = hero->walls_2[i][0];
	while (hero->walls_2[i][0] == corner && i > 0)
	{
		i++;
		n++;
	}
	if (l == 1 && r == 0)
		overwrite_left(hero, i, n);
	if (l == 0 && r == 1)
		overwrite_right(hero, i, n);
	if (l == 1 && r == 1)
		overwrite_both(hero, i, n);
}

void	fix_corners(t_hero *hero, int i)
{
	int	l;
	int	r;
	int	corner;

	while (i < V_RANGE * 2 * FILWI)
	{
		l = 0;
		r = 0;
		if (hero->walls_2[i][0] / 10000 == 9)
		{
			corner = hero->walls_2[i][0];
			check_left_n(hero, i, &l, 0);
			check_right_n(hero, i, &r, 0);
			overwrite_corner(hero, i, l, r);
			while (hero->walls_2[i][0] == corner)
				i++;
			// printf("%d %d %d %d %d", hero->walls_2[i - 3][0], hero->walls_2[i - 2][0],
			 // hero->walls_2[i - 1][0], hero->walls_2[i][0], hero->walls_2[i + 1][0]);
			// printf("\n--------\n");
		}
		i ++;
	}
}

void	fine_tune_view(t_hero *hero)
{
	int	i;
	int	j;
	int	n;
	int	last;

	i = 1;
	j = 0;
	n = 0;
	fix_corners(hero, 0);
	last = hero->walls_2[0][0];
	while (i < V_RANGE * 2 * FILWI)
	{
		while (last == hero->walls_2[i][0])
			i++;
		refine_part(j, i - 1, hero);
		last = hero->walls_2[i][0];
		j = i;
		n ++;
		i ++;
	}
	// printf("\n");
}