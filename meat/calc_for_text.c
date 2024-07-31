/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_for_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:56:32 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:58:19 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	num_of_col(t_core *main_struct, int i, t_tex *tex)
{
	int	check;
	int	num;

	num = 0;
	if (tex->wall == 1 || tex->wall == 3)
		check = 2;
	else
		check = 1;
	while (1)
	{
		if (check_stat(tex, main_struct, i, check))
			break ;
		if (tex->wall == 9)
			break ;
		i ++;
		num ++;
		if (i >= tex->len)
		{
			num = -num;
			tex->x1 = main_struct->hero->walls_2[i - 1][check];
			break ;
		}
	}
	return (num);
}

int	set_color(t_core *main_struct, int n, int x, t_tex *tex)
{
	int	darkener;

	tex->c = interpolation(tex->r_hig, SIZE_N - 1, n);
	if (tex->hig1 > 0)
		tex->e = interpolation(ft_abs(tex->hig1), SIZE_N - x, tex->col);
	else
		tex->e = interpolation(ft_abs(tex->hig1), x, tex->col);
	if (x > 1 && tex->hig1 > 0)
		tex->e += x;
	if (tex->wall == 1)
		tex->color = main_struct->tex.n[tex->c][tex->e % SIZE_N];
	else if (tex->wall == 2)
		tex->color = main_struct->tex.e[tex->c][tex->e % SIZE_N];
	else if (tex->wall == 3)
		tex->color = main_struct->tex.s[tex->c][tex->e % SIZE_N];
	else if (tex->wall == 4)
		tex->color = main_struct->tex.w[tex->c][tex->e % SIZE_N];
	darkener = tex->r_hig / 5;
	if (darkener > 125)
		darkener = 125;
	darkener = 125 - darkener;
	if (darkener > 5)
		tex->color = darken_color(tex->color, darkener);
	return (tex->color);
}

void	calc_for_hig1(t_tex *tex, t_core *main_struct)
{
	if (tex->wid == 0)
		tex->hig1 = num_of_col(main_struct, 0, tex);
	if (tex->wid != 0 && ((tex->wall == 1 || tex->wall == 2)
			&& (main_struct->hero->walls_2[tex->wid - 1][0]
			!= main_struct->hero->walls_2[tex->wid][0]
		|| main_struct->hero->walls_2[tex->wid - 1][tex->check] % POW
			> main_struct->hero->walls_2[tex->wid][tex->check] % POW)))
	{
		tex->col = 0;
		tex->hig1 = num_of_col(main_struct, tex->wid + 1, tex);
		tex->init ++;
	}
	else if (tex->wid != 0 && ((tex->wall == 3 || tex->wall == 4)
			&& (main_struct->hero->walls_2[tex->wid - 1][0]
			!= main_struct->hero->walls_2[tex->wid][0]
		|| main_struct->hero->walls_2[tex->wid - 1][tex->check] % POW
			< main_struct->hero->walls_2[tex->wid][tex->check] % POW)))
	{
		tex->col = 0;
		tex->hig1 = num_of_col(main_struct, tex->wid + 1, tex);
		tex->init ++;
	}
}

void	for_arrows(int keycode, t_core *mlx)
{
	int	len;

	if (keycode == 65361)
	{
		rotate(mlx, 4);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
	else if (keycode == 65363)
	{
		rotate(mlx, -4);
		len = sizeof(mlx->hero->vision_2) / 4;
		put_filars(mlx, mlx->hero->vision_2, len);
	}
}

int	check_stat(t_tex *tex, t_core *main_struct, int i, int check)
{
	if (i != 0 && ((tex->wall == 1 || tex->wall == 2)
			&& (main_struct->hero->walls_2[i - 1][0]
			!= main_struct->hero->walls_2[i][0]
		|| main_struct->hero->walls_2[i - 1][check] % POW
			> main_struct->hero->walls_2[i][check] % POW)))
		return (1);
	else if (i != 0 && ((tex->wall == 3 || tex->wall == 4)
			&& (main_struct->hero->walls_2[i - 1][0]
			!= main_struct->hero->walls_2[i][0]
		|| main_struct->hero->walls_2[i - 1][check] % POW
			< main_struct->hero->walls_2[i][check] % POW)))
		return (1);
	return (0);
}
