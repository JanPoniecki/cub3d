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
		if (hero->vision[i] < min)
			min = hero->vision[i];
		if (hero->vision[i] > max)
			max = hero->vision[i];
		i ++;
	}
	if (hero->vision[start] < hero->vision[stop])
		hero->vision[start] = min;
	else
		hero->vision[start] = max;
	if (hero->vision[start] > hero->vision[stop])
		hero->vision[stop] = min;
	else
		hero->vision[stop] = max;
}

// void	init_ft_vars(t_ft *ft, t_hero *hero)
// {
// 	ft->m1 = hero->vision[s];

// }

void	refine_part(int start, int stop, t_hero *hero)
{
	// t_ft	ft;

	find_min_max(start, stop, hero);
	int m1 = hero->vision[start];
	int m2 = hero->vision[stop];
	int height = hero->vision[start];
	int i = 0;
	float step;
	int steps = (stop - start);
	if (m1 == m2 || steps == 0)
		step = 0;
	else if (m1 > m2)
		step = (float)(m1 - m2) / (float)steps;
	else
		step = (float)(m2 - m1) / (float)steps;
	if (hero->vision[start] < hero->vision[stop])
	{
		while (start != stop)
		{
			hero->vision[start] = height + step * i;
			i ++;
			start ++;
		}
	}
	else
	{
		while (start != stop)
		{
			hero->vision[start] = height - step * i;
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
	last = hero->walls[0];
	while (i < V_RANGE * 2)
	{
		while (last == hero->walls[i])
			i++;
		refine_part(j, i - 1, hero);
		last = hero->walls[i];
		j = i;
		n ++;
		i ++;
	}
}