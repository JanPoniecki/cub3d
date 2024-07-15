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

void	fine_tune_view(t_hero *hero)
{
	int	i;
	int	j;
	int	n;
	int	last;

	i = 1;
	j = 0;
	n = 0;
	last = hero->walls_2[0];
	while (i < V_RANGE * 2 * FILWI)
	{
		while (last == hero->walls_2[i])
			i++;
		refine_part(j, i - 1, hero);
		last = hero->walls_2[i];
		j = i;
		n ++;
		i ++;
	}
}