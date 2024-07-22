/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:55:11 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/22 13:40:53 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define POW 30

int	len_of_file(char *file)
{
	int		fd;
	int		i;
	char	*buf;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		free(buf);
		i ++;
	}
	close(fd);
	return (i);
}

void	ext_line(t_hero *hero, int i, char *map_buf, int len)
{
	int	j;
	int	d;
	int	s;

	j = 0;
	hero->map[i] = malloc(sizeof(char) * len);
	hero->map[i][len - 1] = '\0';
	d = 0;
	while (map_buf[j])
	{
		s = 0;
		while (s++ < POW)
			hero->map[i][d ++] = map_buf[j];
		j ++;
		if (map_buf[j] == '\n')
			break ;
	}
	hero->map[i][d] = '\0';
}

void	ext_col(t_hero *hero, int *i, int len)
{
	int	c;
	int	j;

	(*i)++;
	c = 0;
	while (c++ < POW - 1)
	{
		j = -1;
		hero->map[*i] = malloc(sizeof(char) * len);
		hero->map[*i][len - 1] = '\0';
		while (hero->map[*i - 1][++ j])
			hero->map[*i][j] = hero->map[*i - 1][j];
		(*i)++;
	}
}

void	change_the_map(t_hero *hero, int i, int j)
{
	int	len_f;

	len_f = list_len(hero->map);
	while (hero->map[i])
	{
		j = 0;
		while (hero->map[i][j])
		{
			if (hero->map[i][j] == '1')
			{
				if (((i - 1 >= 0 && ft_strlen(hero->map[i]) > j + 1 && ft_strlen(hero->map[i - 1]) > j)
					&& ((hero->map[i - 1][j]  == '0' && hero->map[i][j + 1] == '0'
					|| (hero->map[i - 1][j + 1]  == '0' && hero->map[i - 1][j] != '0' && hero->map[i][j + 1] != '0'))))
					|| ((list_len(hero->map) > i + 1 && ft_strlen(hero->map[i + 1]) > j && ft_strlen(hero->map[i]) > j + 1)
					&& ((hero->map[i + 1][j]  == '0' && hero->map[i][j + 1] == '0')
					|| (hero->map[i + 1][j + 1]  == '0' && hero->map[i][j + 1] != '0' && hero->map[i + 1][j] != '0')))
					|| ((list_len(hero->map) > i + 1 && j - 1 > 0 && ft_strlen(hero->map[i + 1]) > j)
					&& ((hero->map[i + 1][j]  == '0' && hero->map[i][j - 1] == '0')
					|| (hero->map[i + 1][j - 1]  == '0' && hero->map[i][j - 1] != '0' && hero->map[i + 1][j] != '0')))
					|| ((j - 1 >= 0 && i - 1 >= 0 && ft_strlen(hero->map[i - 1]) > j)
					&& ((hero->map[i - 1][j]  == '0' && hero->map[i][j - 1] == '0')
					|| (hero->map[i - 1][j - 1]  == '0' && hero->map[i - 1][j] != '0' && hero->map[i][j - 1] != '0'))))
					hero->map[i][j] = '9';
				else if (j > 0 && (hero->map[i][j - 1] == '0'
					|| hero->map[i][j - 1] == 'S'))
					hero->map[i][j] = '2';
				else if (hero->map[i][j + 1] != '\0'
					&& (hero->map[i][j + 1] == '0'
					|| hero->map[i][j + 1] == 'S'))
					hero->map[i][j] = '4';
				else if (i - 1 > 0 && ft_strlen(hero->map[i - 1]) > j && (hero->map[i - 1][j] == '0'
					|| hero->map[i - 1][j] == 'S'))
					hero->map[i][j] = '3';
			}
			j ++;
		}
		i ++;
	}
}

char	check_the_corner(t_hero *hero, int i, int j)
{
	int	ones;

	ones = 0;
	if (hero->map[i - 1][j] == '1')
		ones ++;
	if (hero->map[i + 1][j] == '1')
		ones ++;
	if (hero->map[i][j - 1] == '1')
		ones ++;
	if (hero->map[i][j + 1] == '1')
		ones ++;
	if (ones > 1)
		return ('8');
	else
		return ('9');
}


void	find_inner_corners(t_hero *hero, int i, int j)
{
	while (hero->map[i])
	{
		j = 0;
		while (hero->map[i][j])
		{
			if (hero->map[i][j] == '9')
				hero->map[i][j] = check_the_corner(hero, i, j);
			j ++;
		}
		i ++;
	}
}

void	ext_map(t_hero *hero)
{
	int		fd;
	int		len;
	char	*map_buf;
	int		len_f;
	int		i;

	len_f = len_of_file(M_FILE);
	if (len_f == -1)
		exit (0);
	hero->map = malloc(sizeof(char *) * ((len_f * POW) + 1));
	hero->map[len_f * POW] = NULL;
	fd = open(M_FILE, O_RDONLY);
	map_buf = get_next_line(fd);
	i = 0;
	while (map_buf)
	{
		len = (ft_strlen(map_buf) - 1) * POW + 1;
		ext_line(hero, i, map_buf, len);
		ext_col(hero, &i, len);
		free(map_buf);
		map_buf = get_next_line(fd);
	}
	close(fd);
	change_the_map(hero, 0, 0);
	// find_inner_corners(hero, 0, 0);
}

// glowna funkcja to ext_map
// potrzebuje ona tylko t_hero
// zaalokuje pamiec dla mapy oraz
// zmieni jej liczby na poprawne
// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	t_hero hero;
// 	ext_map(&hero);
// 	i = 0;
// 	while (hero.map[i])
// 	{
// 		printf("%s\n", hero.map[i]);
// 		free(hero.map[i ++]);
// 	}
// 	free(hero.map);
// }


// void	change_the_map(t_hero *hero, int i, int j)
// {
// 	int	len_f;

// 	len_f = list_len(hero->map);
// 	while (hero->map[i])
// 	{
// 		j = 0;
// 		while (hero->map[i][j])
// 		{
// 			if (hero->map[i][j] == '1')
// 			{
// 				if (((i - 1 >= 0 && ft_strlen(hero->map[i]) > j + 1 && ft_strlen(hero->map[i - 1]) > j)
// 					&& ((hero->map[i - 1][j]  == '0' && hero->map[i][j + 1] == '0'
// 					|| (hero->map[i - 1][j + 1]  == '0' && hero->map[i - 1][j] != '0' && hero->map[i][j + 1] != '0'))))
// 					|| ((list_len(hero->map) > i + 1 && ft_strlen(hero->map[i + 1]) > j && ft_strlen(hero->map[i]) > j + 1)
// 					&& ((hero->map[i + 1][j]  == '0' && hero->map[i][j + 1] == '0')
// 					|| (hero->map[i + 1][j + 1]  == '0' && hero->map[i][j + 1] != '0' && hero->map[i + 1][j] != '0')))
// 					|| ((list_len(hero->map) > i + 1 && j - 1 > 0 && ft_strlen(hero->map[i + 1]) > j)
// 					&& ((hero->map[i + 1][j]  == '0' && hero->map[i][j - 1] == '0')
// 					|| (hero->map[i + 1][j - 1]  == '0' && hero->map[i][j - 1] != '0' && hero->map[i + 1][j] != '0')))
// 					|| ((j - 1 >= 0 && i - 1 >= 0 && ft_strlen(hero->map[i - 1]) > j)
// 					&& ((hero->map[i - 1][j]  == '0' && hero->map[i][j - 1] == '0')
// 					|| (hero->map[i - 1][j - 1]  == '0' && hero->map[i - 1][j] != '0' && hero->map[i][j - 1] != '0'))))
// 					hero->map[i][j] = '9';
// 				else if (j > 0 && (hero->map[i][j - 1] == '0'
// 					|| hero->map[i][j - 1] == 'S'))
// 					hero->map[i][j] = '2';
// 				else if (ft_strlen(hero->map[i]) < j + 1 && hero->map[i][j + 1] != '\0'
// 					&& (hero->map[i][j + 1] == '0'
// 					|| hero->map[i][j + 1] == 'S'))
// 					hero->map[i][j] = '4';
// 				else if (i - 1 > 0 && ft_strlen(hero->map[i - 1]) > j
// 					&& (hero->map[i - 1][j] == '0'
// 					|| hero->map[i - 1][j] == 'S'))
// 					hero->map[i][j] = '3';
// 			}
// 			j ++;
// 		}
// 		i ++;
// 	}
// }
