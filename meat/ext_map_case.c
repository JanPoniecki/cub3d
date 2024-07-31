/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_map_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:50:22 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:15 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_top_right(char **map, int i, int j)
{
	if (i - 1 >= 0 && (int)ft_strlen(map[i]) > j + 1
		&& (int)ft_strlen(map[i - 1]) > j)
	{
		if ((map[i - 1][j] == '0' && map[i][j + 1] == '0') ||
			(map[i - 1][j + 1] == '0' && map[i - 1][j] != '0'
			&& map[i][j + 1] != '0'))
			return (1);
	}
	return (0);
}

int	check_bottom_right(char **map, int i, int j)
{
	if (list_len(map) > i + 1 && (int)ft_strlen(map[i + 1]) > j
		&& (int)ft_strlen(map[i]) > j + 1)
	{
		if ((map[i + 1][j] == '0' && map[i][j + 1] == '0') ||
			(map[i + 1][j + 1] == '0' && map[i][j + 1] != '0'
				&& map[i + 1][j] != '0'))
			return (1);
	}
	return (0);
}

int	check_bottom_left(char **map, int i, int j)
{
	if (list_len(map) > i + 1 && j - 1 > 0
		&& (int)ft_strlen(map[i + 1]) > j)
	{
		if ((map[i + 1][j] == '0' && map[i][j - 1] == '0') ||
			(map[i + 1][j - 1] == '0' && map[i][j - 1] != '0'
				&& map[i + 1][j] != '0'))
			return (1);
	}
	return (0);
}

int	check_top_left(char **map, int i, int j)
{
	if (j - 1 >= 0 && i - 1 >= 0
		&& (int)ft_strlen(map[i - 1]) > j)
	{
		if ((map[i - 1][j] == '0' && map[i][j - 1] == '0') ||
			(map[i - 1][j - 1] == '0' && map[i - 1][j] != '0'
				&& map[i][j - 1] != '0'))
			return (1);
	}
	return (0);
}

int	check_conditions(char **map, int i, int j)
{
	if (check_top_right(map, i, j) || check_bottom_right(map, i, j)
		|| check_bottom_left(map, i, j) || check_top_left(map, i, j))
		return (1);
	return (0);
}
