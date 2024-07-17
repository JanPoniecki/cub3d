/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:46:31 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/17 11:48:10 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_list(char **lista)
{
	int	i;

	i = 0;
	while (lista[i])
		free(lista[i ++]);
	free(lista);
	lista = NULL;
}

int	list_len(char **lista)
{
	int	i;

	i = 0;
	while (lista[i])
		i ++;
	return (i);
}

void	write_to_vars(char ***vars, int i, int j, char **buff)
{
	(*vars)[j] = malloc(sizeof(char) * (ft_strlen(buff[j]) + 1));
	(*vars)[j][ft_strlen(buff[j])] = '\0';
	i = -1;
	while (buff[j][++ i])
		(*vars)[j][i] = buff[j][i];
}

void	write_to_ma(char **var, int i, char **s_line, char ***vars)
{
	char	**buff;
	int		j;

	if (i != -1)
	{
		buff = ft_split(s_line[1], ',');
		if (list_len(buff) != 3)
		{
			free_list(buff);
			return ;
		}
		(*vars) = malloc(sizeof(char *) * 4);
		(*vars)[3] = NULL;
		j = -1;
		while (++ j < 3)
			write_to_vars(vars, -1, j, buff);
		free_list(buff);
		return ;
	}
	*var = malloc(sizeof(char) * ft_strlen(s_line[1]) + 1);
	(*var)[ft_strlen(s_line[1])] = '\0';
	while (s_line[1][++ i])
		(*var)[i] = s_line[1][i];
}

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

int	check_line(char **s_line, char *line, int fd, t_map *map)
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

void	free_map(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->ea)
		free(map->ea);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->f)
		free_list(map->f);
	if (map->c)
		free_list(map->c);
	if (map->floor)
		free(map->floor);
	if (map->ceiling)
		free(map->ceiling);
}

void	write_to_file(int i, char *line, int fd_out)
{
	while (line[++ i])
	{
		if (line[i] == ' ')
			write(fd_out, "1", 1);
		else
			write(fd_out, &line[i], 1);
	}
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
			write_to_file(-1, line, fd_out);
		else if (line[0] != '\n')
		{
			line[ft_strlen(line) - 1] = '\0';
			s_line = ft_split(line, ' ');
			if (check_line(s_line, line, fd, map) || colors(s_line, map))
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

void	read_map(t_map *map)
{
	int		fd;
	char	**s_line;
	char	fd_out;

	fd_out = open(M_FILE, O_WRONLY | O_CREAT, 0644);
	map->flag = 0;
	fd = open(MAPF, O_RDONLY);
	while_loop(fd, fd_out, s_line, map);
	close(fd);
	close(fd_out);
	if (map->flag == 1 || map->f == NULL || map->c == NULL)
	{
		errno = EINVAL;
		perror("Error\n");
		free_map(map);
		exit(1);
	}
	change_to_hex(map);
}

void	initilize_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
}

// the "main" function is the read_map
// it will read the date from file and write to 
// strutc t_map

// int	main(void)
// {
// 	t_map	map;
// 	t_hero	hero;

// 	map.no = NULL;
// 	map.so = NULL;
// 	map.we = NULL;
// 	map.ea = NULL;
// 	map.f = NULL;
// 	map.c = NULL;
// 	read_map(&map);
// 	printf("%s\n", map.no);
// 	printf("%s\n", map.so);
// 	printf("%s\n", map.we);
// 	printf("%s\n", map.ea);
// 	printf("%s\n", map.f[0]);
// 	printf("%s\n", map.c[0]);
// 	free_map(&map);
// 	ext_map(&hero);
// 	int	i = 0;
// 	i = 0;
// 	while (hero.map[i])
// 	{
// 		// printf("%s\n", hero.map[i]);
// 		free(hero.map[i ++]);
// 	}
// 	free(hero.map);
// }
