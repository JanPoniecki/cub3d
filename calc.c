/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:17:33 by jponieck          #+#    #+#             */
/*   Updated: 2024/07/17 22:34:36 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	bzero_axis(t_hero *hero, int size, char type)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (type == 'y')
			hero->y_axis[i][0] = -1;
		else
			hero->x_axis[i][0] = -1;
		i ++;
	}
}

double	cosine(int angle)
{
	double	rads;

	rads = angle * (M_PI / 180.0);
	return (cos(rads));
}

double	sine(int angle)
{
	double	rads;

	rads = angle * (M_PI / 180.0);
	return (sin(rads));
}

int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

void	re_init_axis(t_hero *hero, int rotation)
{
	if (rotation == -180)
	{
		// ft_bzero(hero->y_axis, 500);
		bzero_axis(hero, 500, 'y');
		hero->y_index = 0;
	}
	else
	{
		// ft_bzero(hero->x_axis, 500);
		bzero_axis(hero, 500, 'x');
		hero->x_index = 0;
	}
}

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


void	find_collision(t_hero *hero, t_axis *axis, int i)
{
	while (1)
	{
		if (hero->map[axis->x0][axis->y0] != '0')
		{
			axis->colision[0] = axis->x0;
			axis->colision[1] = axis->y0;
			axis->colision[2] = hero->map[axis->x0][axis->y0];
			if (hero->map[axis->x0][axis->y0] == '1' || hero->map[axis->x0][axis->y0] == '3')
				hero->walls[V_RANGE * 2 - 1 - i] = ((axis->colision[2] - 48) * 10000 + axis->x0);
			else
				hero->walls[V_RANGE * 2 - 1 - i] = ((axis->colision[2] - 48) * 10000 + axis->y0);
			hero->walls_c[V_RANGE * 2 - 1 - i][0] = axis->x0;
			hero->walls_c[V_RANGE * 2 - 1 - i][1] = axis->y0;
			return ;
		}
		axis->e2 = 2 * axis->err;
		if (axis->e2 > - axis->dy)
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

void	wall_buffer(t_hero *hero, char type)
{
	int	i;

	i = 0;
	while(i < 500)
	{
		if (type == 'y')
		{
			if (hero->pos[0] == hero->y_axis[i][0] && hero->pos[1] == hero->y_axis[i][1])
				hero->y_index = i;
		}
		else
		{
			if (hero->pos[0] == hero->x_axis[i][0] && hero->pos[1] == hero->x_axis[i][1])
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
	wall_buffer(hero, type);
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
		set_axis_vars_back(hero , &axis, -180);
	else
		set_axis_vars_back(hero , &axis, 90);
	go_to_axis_start(hero, &axis, type);
	if (type == 'y')
		set_axis_vars_forw(hero , &axis, 0);
	else
		set_axis_vars_forw(hero , &axis, -90);
	set_axis_forward(hero, &axis, type);
}

int		calc_height(t_hero *hero, t_axis *axis, int i)
{
	int		a;
	int		b;
	float	c;
	int		ang;

	ang = - V_RANGE + i;
	// a = ft_abs(axis->x0 - hero->pos[0]);
	a = ft_abs(axis->colision[0] - hero->pos[0]);
	// b = ft_abs(axis->y0 - hero->pos[1]);
	b = ft_abs(axis->colision[1] - hero->pos[1]);
	c = sqrt(a * a + b * b);
	c = c * sine(90 - ang);
	a = c;
	a = (int)round(c);
	return (DIVIDER / (a * 0.7));
}

void	get_collision(t_hero *hero, int angle, int i)
{
	t_axis	axis;
	int		height;

	init_collision_vars(hero, &axis, angle);
	find_collision(hero, &axis, i);
	height = calc_height(hero, &axis, i);
	// if (height > HEIGHT)
		// height = HEIGHT;
	hero->vision[V_RANGE * 2 - 1 - i]= height;
}

void	check_neighbour_1(t_hero *hero, int i, int w, int h)
{
	if (i > 0)
	{
		if (hero->walls[i - 1] / 10000 == 1 || hero->walls[i - 1] / 10000 == 3)
		{
			if (ft_abs(hero->walls[i - 1] % 10000 - hero->walls_c[i][0]) <= 1)
			{
				hero->vision[i - 1] = hero->vision[i];
				w = hero->walls[i - 1];
				while (hero->walls[i] / 10000 > 4)
				{
					hero->walls[i] = w;
					i ++;
				}
			}
		}
	}
}

void	handle_corners(t_hero *hero)
{
	int	i;

	i = 0;
	while (i < V_RANGE * 2)
	{
		if (hero->walls[i] / 10000 > 4)
		{
			if (i > 0)
				check_neighbour_1(hero, i, 0, 0);
		}
		i ++;
	}
}

void	calc_viev(t_hero *hero)
{
	int	angle;
	int	i;

	// printf("%d %d\n", hero->pos[0], hero->pos[1]);
	// ft_bzero(hero->vision, V_RANGE * 2);
	angle = hero->angle - V_RANGE;
	i = 0;
	while (i != V_RANGE * 2)
	{
		get_collision(hero, angle, i);
		i ++;
		angle ++;
	}
	handle_corners(hero);
	i = 0;
	int j = 0;
	int k = 0;
	while (i < V_RANGE * 2)
	{
		while (j < FILWI)
		{
			hero->vision_2[k] = hero->vision[i];
			hero->walls_2[k] = hero->walls[i];
			j ++;
			k ++;
		}
		j = 0;
		i ++;
	}
	// i = 0;
	// while (i < V_RANGE * 2)
	// {
	// 	printf("%d\n ", hero->walls[i]);
	// 	i ++;
	// }
	// printf("\n\n\n");
	fine_tune_view(hero);
}