/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:29:44 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/15 15:56:32 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		exit(1);
	}
	return (0);
}

// int	main(void)
// {
// 	check_for_wrong();
// }
