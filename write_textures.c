#include "cub3d.h"

int	write_texture(t_core *main_str, char *relative_path, int img_width, int (*buffer)[img_width])
{
	void	*texture;
	int		pos;
	int		img_height;

	img_height = img_width;

	texture = mlx_xpm_file_to_image(main_str->con, relative_path, &img_width, &img_height);

	if (!texture)
	{
		perror("Error\n");
		return (1);
	}
	main_str->addr = mlx_get_data_addr(texture, &main_str->bits_per_pixel, &main_str->line_length, &main_str->endian);
	int	y = -1;
	int	x = -1;
	while (++ y < img_height)
	{
		x = -1;
		while (++ x < img_width)
		{
			pos = (y * main_str->line_length + x * (main_str->bits_per_pixel / 8));
			buffer[y][x] = (*(unsigned int *)(main_str->addr + pos));
			printf("x = %d, y = %d, %d\n", x, y, main_str->tex.n[y][x]);
		}
	}
	return (0);
}

int	write_textures(t_core *main_str)
{
	if (write_texture(main_str, main_str->hero->ma->no, H_N, main_str->tex.n)
		|| write_texture(main_str, main_str->hero->ma->so, H_S, main_str->tex.s)
		|| write_texture(main_str, main_str->hero->ma->ea, H_E, main_str->tex.e)
		|| write_texture(main_str, main_str->hero->ma->we, H_W, main_str->tex.w))
		return (1);
	return (0);
}
