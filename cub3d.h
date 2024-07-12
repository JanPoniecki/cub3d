/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:35 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/11 23:39:33 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlxlibX/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mylibft/mylibft.h"

# define HEIGHT 800
# define WIDTH 1000
# define V_RANGE 45
# define FILAR_SIZE 15

typedef struct s_axis
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		d;
	int		lastx;
	int		lasty;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	double	degr;
	int		colision[4];
}	t_axis;

typedef struct s_hero
{
	char	**map;
	int		y_axis[500][2];
	int		y_index;
	int		x_axis[500][2];
	int		x_index;
	int		pos[2];
	int		angle;
	int		walls[V_RANGE * 2];
	int		vision[V_RANGE * 2];
}	t_hero;

typedef struct s_core
{
	void	*con;
	void	*win;
	void	*img;
}			t_core;

void	find_start(t_hero *hero);
double	cosine(int angle);
void	calc_axis(t_hero *hero, char type);
void	print_map(t_hero *hero);
void	calc_viev(t_hero *hero);

#endif
