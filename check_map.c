/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:29:44 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/30 14:06:59 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// that is only checking if there is only
// valid characters
int	check_for_wrong(int fd)
{
	char	*line;
	int		count;
	int		i;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (line[++ i])
		{
			if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W')
				count ++;
			else if (line[i] != '0' && line[i] != '1'
				&& line[i] != ' ' && line[i] != '\n')
				count += 2;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count != 1)
		return (1);
	return (0);
}

int	check_the_valid(t_hero *hero, int i, int j, int tm)
{
	int		len_f;

	len_f = list_len(hero->map);
	while (hero->map[++ i])
	{
		j = -1;
		while (hero->map[i][++ j])
		{
			if (hero->map[i][j] == '0')
			{
				if (i > 0 && i + 1 < len_f && (ft_strlen(hero->map[i - 1]) < j
						|| ft_strlen(hero->map[i + 1]) < j))
					return (1);
			}
		}
	}
	i = 0;
	while (hero->ma->f[i])
	{
		tm = ft_atoi(hero->ma->f[i ++]);
		if (tm < 0 || tm > 255)
			return (1);
	}
	return (0);
}

int	existence_fi(t_hero *hero)
{
	int	fd;
	int	tmp;

	tmp = 0;
	fd = open(hero->ma->no, O_RDONLY);
	if (fd < 0)
		tmp = 1;
	close(fd);
	fd = open(hero->ma->so, O_RDONLY);
	if (fd < 0)
		tmp = 1;
	close(fd);
	fd = open(hero->ma->ea, O_RDONLY);
	if (fd < 0)
		tmp = 1;
	close(fd);
	fd = open(hero->ma->we, O_RDONLY);
	if (fd < 0)
		tmp = 1;
	close(fd);
	if (tmp == 1)
		return (1);
	return (0);
}

int	check_the_ext(t_hero *hero, int i, int j)
{
	int	len;
	int	len1;
	int	len2;
	int	len3;

	len = ft_strlen(hero->ma->no);
	len1 = ft_strlen(hero->ma->ea);
	len2 = ft_strlen(hero->ma->we);
	len3 = ft_strlen(hero->ma->so);
	if (len < 5)
		return (1);
	if (ft_strnstr(hero->ma->no + len - 4, ".xpm", 4) == NULL
		|| ft_strnstr(hero->ma->so + len3 - 4, ".xpm", 4) == NULL
		|| ft_strnstr(hero->ma->we + len2 - 4, ".xpm", 4) == NULL
		|| ft_strnstr(hero->ma->ea + len1 - 4, ".xpm", 4) == NULL)
		return (1);
	while (hero->map[++ i])
	{
		j = ft_strlen(hero->map[i]);
		if (hero->map[i][j - 1] != '1'
			|| hero->map[i][0] != '1')
			return (1);
	}
	return (0);
}

void	checker(t_hero *hero, t_map *map)
{
	int	i;
	int	tm;

	i = 0;
	while (hero->ma->c[i])
	{
		tm = ft_atoi(hero->ma->c[i ++]);
		if (tm < 0 || tm > 255)
			break ;
	}
	if (check_the_valid(hero, -1, -1, 0)
		|| check_for_wrong(open(M_FILE, O_RDONLY))
		|| existence_fi(hero)
		|| check_the_ext(hero, -1, -1)
		|| i != 3)
	{
		free_map(map);
		free_list(hero->map);
		free(hero);
		errno = EINVAL;
		perror("Error\n");
		exit (1);
	}
}
