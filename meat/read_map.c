/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:46:31 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:38 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	colors(char **s_line, t_map *map)
{
	if (s_line[0][0] == 'F' && s_line[0][1] == '\0')
	{
		if (list_len(s_line) != 2)
			return (1);
		write_to_ma(NULL, 0, s_line, &map->f);
	}
	else if (s_line[0][0] == 'C' && s_line[0][1] == '\0')
	{
		if (list_len(s_line) != 2)
			return (1);
		write_to_ma(NULL, 0, s_line, &map->c);
	}
	return (0);
}

int	check_line(char **s_line, t_map *map)
{
	if (s_line[0][0] == 'N' && s_line[0][1] == 'O' && s_line[0][2] == '\0')
	{
		if (list_len(s_line) != 2)
			return (1);
		write_to_ma(&map->no, -1, s_line, NULL);
	}
	else if (s_line[0][0] == 'S' && s_line[0][1] == 'O' && s_line[0][2] == '\0')
	{
		if (list_len(s_line) != 2)
			return (1);
		write_to_ma(&map->so, -1, s_line, NULL);
	}
	else if (s_line[0][0] == 'W' && s_line[0][1] == 'E' && s_line[0][2] == '\0')
	{
		if (list_len(s_line) != 2)
			return (1);
		write_to_ma(&map->we, -1, s_line, NULL);
	}
	else if (s_line[0][0] == 'E' && s_line[0][1] == 'A' && s_line[0][2] == '\0')
	{
		if (list_len(s_line) != 2)
			return (1);
		write_to_ma(&map->ea, -1, s_line, NULL);
	}
	return (0);
}

void	while_loop(int fd, int fd_out, char **s_line, t_map *map)
{
	char	*line;
	int		fl;

	fl = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == ' ' || line[0] == '1' || line[0] == '0')
			fl = 1;
		if (fl == 1)
			write_to_file(-1, line, fd_out, map);
		else if (line[0] != '\n')
		{
			line[ft_strlen(line) - 1] = '\0';
			s_line = ft_split(line, ' ');
			if (check_line(s_line, map) || colors(s_line, map))
				map->flag = 1;
			free_list(s_line);
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	change_to_hex(t_map *map)
{
	int		i;
	char	*new_str;
	char	*tmp1;
	char	*tmp2;

	i = -1;
	tmp1 = dec_to_hex(map->c[0]);
	tmp2 = dec_to_hex(map->c[1]);
	new_str = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	tmp1 = ft_strjoin(new_str, map->c[2]);
	map->ceiling = ft_strjoin("0x", tmp1);
	free(tmp1);
	free(new_str);
	tmp1 = dec_to_hex(map->f[0]);
	tmp2 = dec_to_hex(map->f[1]);
	new_str = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	tmp1 = ft_strjoin(new_str, map->f[2]);
	map->floor = ft_strjoin("0x", tmp1);
	free(tmp1);
	free(new_str);
}

void	read_map(t_hero *hero, t_map *map)
{
	int		fd;
	char	**s_line;
	char	fd_out;

	fd_out = open(M_FILE, O_WRONLY | O_CREAT, 0644);
	map->flag = 0;
	fd = open(MAPF, O_RDONLY);
	s_line = NULL;
	while_loop(fd, fd_out, s_line, map);
	close(fd);
	close(fd_out);
	if (map->flag == 1 || map->f == NULL || map->c == NULL)
	{
		errno = EINVAL;
		perror("Error\n");
		free_map(map);
		free(hero);
		exit(1);
	}
	change_to_hex(map);
}
