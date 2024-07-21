/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:29:44 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/19 20:29:33 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// that is only checking if there is only
// valid characters
int	check_for_wrong(void)
{
	int		fd;
	char	*line;
	int		count;
	int		i;

	count = 0;
	fd = open(M_FILE, O_RDONLY);
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
	{
		errno = EINVAL;
		perror("Error\n");
		return (1);
	}
	return (0);
}

int	check_the_valid(t_hero *hero, int i, int j)
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
				if (i > 0 && i  + 1 < len_f && (ft_strlen(hero->map[i - 1]) < j
					|| ft_strlen(hero->map[i + 1]) < j))
					{
						errno = EINVAL;
						perror("Error\n");
						return (1);
					}
			}
		}
	}
	return (0);
}

void	checker(t_hero *hero, t_map *map)
{
	if (check_the_valid(hero, -1, -1)
		|| check_for_wrong())
	{
		// we have to exit but i dont know what to free
		// for that moment
		free_map(map);
		free_list(hero->map);
		exit (1);
	}
}

// int	main(void)
// {
// 	t_hero	hero;
// 	int		i;

// 	ext_map(&hero);
// 	check_for_wrong();
// 	if (check_the_valid(&hero, -1, -1))
// 	{
// 		i = 0;
// 		while (hero.map[i])
// 			free(hero.map[i ++]);
// 		free(hero.map);
// 	}
// 	i = 0;
// 	while (hero.map[i])
// 		free(hero.map[i ++]);
// 	free(hero.map);
// }
