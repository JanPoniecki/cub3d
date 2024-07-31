/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tune_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:22:48 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:52 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	set_hero_vis(t_ref *ref, int start, int stop, t_hero *hero)
{
	if (hero->vision_2[start] < hero->vision_2[stop])
	{
		while (start != stop)
		{
			hero->vision_2[start] = ref->height + ref->step * ref->i;
			ref->i ++;
			start ++;
		}
	}
	else
	{
		while (start != stop)
		{
			hero->vision_2[start] = ref->height - ref->step * ref->i;
			ref->i ++;
			start ++;
		}
	}
}

void	refine_part(int start, int stop, t_hero *hero)
{
	t_ref	ref;
	int		steps;

	find_min_max(start, stop, hero);
	ref.m1 = hero->vision_2[start];
	ref.m2 = hero->vision_2[stop];
	ref.height = hero->vision_2[start];
	ref.i = 0;
	steps = (stop - start);
	if (ref.m1 == ref.m2 || steps == 0)
		ref.step = 0;
	else if (ref.m1 > ref.m2)
		ref.step = (float)(ref.m1 - ref.m2) / (float)steps;
	else
		ref.step = (float)(ref.m2 - ref.m1) / (float)steps;
	set_hero_vis(&ref, start, stop, hero);
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
}
