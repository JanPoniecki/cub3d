/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:35 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/09 14:25:00 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlxlibX/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mylibft/mylibft.h"

# define HEIGHT 800
# define WIDTH 1000

typedef struct s_axis
{
	int	x0;
	int	y0;
	int	d;
	int	lastx;
	int	lasty;
}	t_axis;

typedef struct s_hero
{
	char	**map;
	int		*y_axis;
	int		y_index;
	int		*x_axis;
	int		x_index;
	int		pos[2];
	int		angle;
}	t_hero;

typedef struct s_core
{
	void	*con;
	void	*win;
	void	*img;
}			t_core;

void	find_start(t_hero *hero);

#endif
