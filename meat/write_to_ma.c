/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_ma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:19:49 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:43:08 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
