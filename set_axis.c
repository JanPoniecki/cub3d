/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:36:18 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 10:36:24 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_collision_vars(t_hero *hero, t_axis *axis, int angle)
{
	axis->x0 = hero->pos[0];
	axis->y0 = hero->pos[1];
	axis->d = 100;
	axis->x1 = axis->x0 + (int)(axis->d * cosine(angle));
	axis->y1 = axis->y0 + (int)(axis->d * sine(angle));
	axis->dx = ft_abs(axis->x1 - axis->x0);
	axis->dy = ft_abs(axis->y1 - axis->y0);
	if (axis->x0 < axis->x1)
		axis->sx = 1;
	else
		axis->sx = -1;
	if (axis->y0 < axis->y1)
		axis->sy = 1;
	else
		axis->sy = -1;
	axis->err = axis->dx - axis->dy;
}

void	set_axis(t_axis *axis)
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
}

void	find_collision(t_hero *hero, t_axis *axis, int i)
{
	while (1)
	{
		if (hero->map[axis->x0][axis->y0] != '0')
		{
			axis->colision[0] = axis->x0;
			axis->colision[1] = axis->y0;
			axis->colision[2] = hero->map[axis->x0][axis->y0];
			if (hero->map[axis->x0][axis->y0] == '1'
					|| hero->map[axis->x0][axis->y0] == '3')
				hero->walls[V_RANGE * 2 - 1 - i] = ((axis->colision[2] - 48)
						* 10000 + axis->x0);
			else
				hero->walls[V_RANGE * 2 - 1 - i] = ((axis->colision[2] - 48)
						* 10000 + axis->y0);
			hero->walls_c[V_RANGE * 2 - 1 - i][0] = axis->x0;
			hero->walls_c[V_RANGE * 2 - 1 - i][1] = axis->y0;
			return ;
		}
		set_axis(axis);
	}
}

void	set_axis_vars_back(t_hero *hero, t_axis *axis, int rotation)
{
	re_init_axis(hero, rotation);
	axis->x0 = hero->pos[0];
	axis->y0 = hero->pos[1];
	axis->d = 100;
	axis->lastx = -1;
	axis->lasty = -1;
	axis->degr = hero->angle + rotation;
	axis->x1 = axis->x0 + (int)(axis->d * cosine(axis->degr));
	axis->y1 = axis->y0 + (int)(axis->d * sine(axis->degr));
	axis->dx = ft_abs(axis->x1 - axis->x0);
	axis->dy = ft_abs(axis->y1 - axis->y0);
	if (axis->x0 < axis->x1)
		axis->sx = 1;
	else
		axis->sx = -1;
	if (axis->y0 < axis->y1)
		axis->sy = 1;
	else
		axis->sy = -1;
	axis->err = axis->dx - axis->dy;
}

void	set_axis_vars_forw(t_hero *hero, t_axis *axis, int rotation)
{
	axis->degr = hero->angle + rotation;
	axis->x1 = axis->x0 + (int)(axis->d * cosine(axis->degr));
	axis->y1 = axis->y0 + (int)(axis->d * sine(axis->degr));
	axis->dx = ft_abs(axis->x1 - axis->x0);
	axis->dy = ft_abs(axis->y1 - axis->y0);
	if (axis->x0 < axis->x1)
		axis->sx = 1;
	else
		axis->sx = -1;
	if (axis->y0 < axis->y1)
		axis->sy = 1;
	else
		axis->sy = -1;
	axis->err = axis->dx - axis->dy;
}
