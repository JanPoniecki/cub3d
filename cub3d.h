/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:35 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/15 11:41:02 by bkotwica         ###   ########.fr       */
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
# include <errno.h>

# define HEIGHT 2000
# define WIDTH 2000
# define V_RANGE 45
# define FILAR_SIZE 20
# define FILWI 20
# define DIVIDER 15000
# define PILLOW 5
# define MAPF "test_map.cub"

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
}			t_axis;

typedef struct s_hero
{
	char	**map;
	int		y_axis[500][2];
	int		y_index;
	int		y_end;
	int		x_axis[500][2];
	int		x_index;
	int		x_end;
	int		pos[2];
	int		angle;
	int		walls[V_RANGE * 2];
	int		vision[V_RANGE * 2];
}			t_hero;

typedef struct s_core
{
	void	*con;
	void	*win;
	void	*img;
	char	*addr;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
	int		wid;
	t_hero	*hero;
}			t_core;

typedef struct s_ft
{
	int		m1;
	int		m2;
	int		height;
	int		i;
	float	step;
	int		steps;
}			t_ft;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**f;
	char	**c;
	int		flag;
}			t_map;

void	find_start(t_hero *hero);
double	cosine(int angle);
void	calc_axis(t_hero *hero, char type);
void	print_map(t_hero *hero);
void	calc_viev(t_hero *hero);
void	ext_map(t_hero *hero);
void	create_win(t_hero *hero);
void	move_on_y(t_core *main_struct, int change);
void	move_on_x(t_core *main_struct, int change);
void	rotate(t_core *main_struct, int change);
void	fine_tune_view(t_hero *hero);
int		ft_abs(int num);
int		int_color(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b);

#endif
