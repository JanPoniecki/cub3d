/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_axis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:39:40 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:41:54 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	insert_xy(t_hero *hero, t_axis *axis, char type, int i)
{
	if (type == 'y')
	{
		hero->y_axis[i][0] = axis->x0;
		hero->y_axis[i][1] = axis->y0;
	}
	else
	{
		hero->x_axis[i][0] = axis->x0;
		hero->x_axis[i][1] = axis->y0;
	}
}

void	wall_buffer(t_hero *hero, char type, int i)
{
	while (i < 500)
	{
		if (type == 'y')
		{
			if (hero->pos[0] == hero->y_axis[i][0]
					&& hero->pos[1] == hero->y_axis[i][1])
				hero->y_index = i;
		}
		else
		{
			if (hero->pos[0] == hero->x_axis[i][0]
					&& hero->pos[1] == hero->x_axis[i][1])
				hero->x_index = i;
		}
		i ++;
	}
	if (hero->y_index < PILLOW)
		hero->y_index = PILLOW;
	if (hero->y_index + PILLOW > hero->y_end)
		hero->y_index = hero->y_end - PILLOW;
	if (hero->x_index < PILLOW)
		hero->x_index = PILLOW;
	if (hero->x_index + PILLOW > hero->x_end)
		hero->x_index = hero->x_end - PILLOW;
}

void	set_axis_forward(t_hero *hero, t_axis *axis, char type)
{
	int	i;

	i = 0;
	while (hero->map[axis->x0][axis->y0] != '1')
	{
		axis->e2 = 2 * axis->err;
		if (axis->e2 > -axis->dy)
		{
			axis->err -= axis->dy;
			axis->x0 += axis->sx;
		}
		if (axis->e2 < axis->dx)
		{
			axis->err += axis->dx;
			axis->y0 += axis->sy;
		}
		insert_xy(hero, axis, type, i);
		i ++;
	}
	if (type == 'y')
		hero->y_end = i;
	else
		hero->x_end = i;
	wall_buffer(hero, type, 0);
}

void	go_to_axis_start(t_hero *hero, t_axis *axis, char type)
{
	while (hero->map[axis->x0][axis->y0] != '1')
	{
		axis->lastx = axis->x0;
		axis->lasty = axis->y0;
		axis->e2 = 2 * axis->err;
		if (axis->e2 > -axis->dy)
		{
			axis->err -= axis->dy;
			axis->x0 += axis->sx;
		}
		if (axis->e2 < axis->dx)
		{
			axis->err += axis->dx;
			axis->y0 += axis->sy;
		}
		if (type == 'y')
			hero->y_index ++;
		else
			hero->x_index ++;
	}
	if (axis->lastx >= 0)
		axis->x0 = axis->lastx;
	if (axis->lasty >= 0)
		axis->y0 = axis->lasty;
}

void	calc_axis(t_hero *hero, char type)
{
	t_axis	axis;

	if (type == 'y')
		set_axis_vars_back(hero, &axis, -180);
	else
		set_axis_vars_back(hero, &axis, 90);
	go_to_axis_start(hero, &axis, type);
	if (type == 'y')
		set_axis_vars_forw(hero, &axis, 0);
	else
		set_axis_vars_forw(hero, &axis, -90);
	set_axis_forward(hero, &axis, type);
}
