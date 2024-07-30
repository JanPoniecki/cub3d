/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:15:05 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/30 14:17:24 by bkotwica         ###   ########.fr       */
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

void	free_list_int(int **lista, int size)
{
	int	i;

	i = 0;
	while (i < size)
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
	free(map);
}
