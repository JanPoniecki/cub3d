/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:38:40 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:43:06 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	write_texture(t_core *main_str, char *relative_path,
	int img_width, int **buffer)
{
	void	*texture;
	int		pos;
	int		y;
	int		x;

	x = -1;
	y = -1;
	texture = mlx_xpm_file_to_image(main_str->con, relative_path,
			&img_width, &img_width);
	main_str->addr = mlx_get_data_addr(texture, &main_str->bits_per_pixel,
			&main_str->line_length, &main_str->endian);
	while (++ y < img_width)
	{
		x = -1;
		buffer[y] = malloc(sizeof(int) * img_width);
		while (++ x < img_width)
		{
			pos = (y * main_str->line_length + x
					* (main_str->bits_per_pixel / 8));
			buffer[y][x] = (*(unsigned int *)(main_str->addr + pos));
		}
	}
	mlx_destroy_image(main_str->con, texture);
	return (0);
}

int	write_textures(t_core *main_str)
{
	main_str->tex.n = malloc(sizeof(int *) * SIZE_N);
	main_str->tex.s = malloc(sizeof(int *) * SIZE_N);
	main_str->tex.e = malloc(sizeof(int *) * SIZE_N);
	main_str->tex.w = malloc(sizeof(int *) * SIZE_N);
	if (write_texture(main_str, main_str->hero->ma->no,
			SIZE_N, main_str->tex.n)
		|| write_texture(main_str, main_str->hero->ma->so,
			SIZE_N, main_str->tex.s)
		|| write_texture(main_str, main_str->hero->ma->ea,
			SIZE_N, main_str->tex.e)
		|| write_texture(main_str, main_str->hero->ma->we,
			SIZE_N, main_str->tex.w))
		return (1);
	return (0);
}
