/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:35 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 09:58:41 by bkotwica         ###   ########.fr       */
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

# define HEIGHT 700
# define WIDTH 800
# define V_RANGE 40
# define FILAR_SIZE 10
# define FILWI 10
# define DIVIDER 10000
# define PILLOW 5
# define MAPF "test_map.cub"
# define M_FILE "out"
# define POW 30

# define SIZE_N 256
# define SIZE_E 256
# define SIZE_S 256
# define SIZE_W 256

typedef struct s_textures
{
	int		**n;
	int		**s;
	int		**e;
	int		**w;
}			t_te;

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

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**f;
	char	**c;
	char	*floor;
	char	*ceiling;
	int		flag;
}			t_map;

typedef struct s_hero
{
	char	**map;
	int		y_axis[2000][2];
	int		y_index;
	int		y_end;
	int		x_axis[2000][2];
	int		x_index;
	int		x_end;
	int		pos[2];
	int		angle;
	int		walls[V_RANGE * 2 + 10];
	int		walls_c[V_RANGE * 2 + 10][2];
	int		walls_2[V_RANGE * 2 * FILWI][3];
	int		vision_2[V_RANGE * 2 * FILWI];
	int		vision[V_RANGE * 2 + 10];
	t_map	*ma;
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
	t_te	tex;
}			t_core;

typedef struct s_text
{
	int		i;
	int		col;
	int		init;
	int		finit;
	int		x;
	int		wall;
	int		check;
	int		len;
	int		j;
	int		hig1;
	int		x1;
	int		hig;
	int		wid;
	int		t_w;
	int		r_hig;
	int		tmph;
	int		tmpe;
	int		c;
	int		e;
	int		color;
}			t_tex;

void	find_start(t_hero *hero);
double	cosine(int angle);
void	calc_axis(t_hero *hero, char type);
void	print_map(t_hero *hero);
void	calc_viev(t_hero *hero);
void	ext_map(t_hero *hero);
void	create_win(t_core *main_struct);
void	move_on_y(t_core *main_struct, int change);
void	move_on_x(t_core *main_struct, int change);
void	rotate(t_core *main_struct, int change);
void	fine_tune_view(t_hero *hero);
int		ft_abs(int num);
int		int_color(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b);
int		darken_color(int color, int darkener);

int		len_of_file(char *file);
int		list_len(char **lista);
void	initilize_map(t_map *map);
void	free_map(t_map *map);
void	free_list(char **lista);
char	*dec_to_hex(char *str);

void	ext_map(t_hero *hero);
void	checker(t_hero *hero, t_map *map);
void	read_map(t_hero *hero, t_map *map);
void	my_mlx_pixel_put(t_core *data, int x, int y, int color);
char	*dec_to_hex_helper(unsigned int n);
int		write_texture(t_core *main_str, \
	char *relative_path, int img_width, int **buffer);
int		write_textures(t_core *main_str);
void	expand_the_texture(t_core *main_str, int **texture);
void	reduce_the_texture(t_core *main_str, int **texture);
void	free_list_int(int **lista, int size);
void	delete_n(t_hero *hero, int i, int j, int sum);
int		interpolation(int height, int txt_height, int point);
int		check_conditions(char **map, int i, int j);
int		len_of_file(char *file);
long	my_strtol(char *str);
void	free_list(char **lista);
void	free_list_int(int **lista, int size);
int		list_len(char **lista);
void	initilize_map(t_map *map);
void	free_map(t_map *map);
void	write_to_file(int i, char *line, int fd_out, t_map *map);
void	write_to_ma(char **var, int i, char **s_line, char ***vars);
int		ass_check(int wall);
int		my_key_hook(int keycode, t_core *mlx);
void	calc_for_hig1(t_tex *tex, t_core *main_struct);
void	draw_ceiling(t_core *main_struct, t_tex *tex);
void	draw_walls(t_tex *tex, t_core *main_struct);
void	draw_floor(t_core *main_struct, t_tex *tex);
void	close_window(t_core *mlx);
void	display_the_win(t_core *main_struct);
void	put_filars(t_core *main_struct, int *lista, int len);
void	for_arrows(int keycode, t_core *mlx);
int		set_color(t_core *main_struct, int n, int x, t_tex *tex);
int		check_stat(t_tex *tex, t_core *main_struct, int i, int check);

#endif
