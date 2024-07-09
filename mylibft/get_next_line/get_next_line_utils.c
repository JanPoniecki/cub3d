/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:18:18 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/04 19:53:23 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lis	*find_last_node(t_lis *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	dealloc(t_lis **list, t_lis *clean_node, char *buffer)
{
	t_lis	*ex;

	if (*list == NULL)
		return ;
	while (*list)
	{
		ex = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = ex;
	}
	*list = NULL;
	if (clean_node->str_buf[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}

void	polish_list(t_lis **list)
{
	t_lis	*last_node;
	t_lis	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_lis));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i ++;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buffer[j++] = last_node->str_buf[i];
	buffer[j] = '\0';
	clean_node->str_buf = buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, buffer);
}

void	copy_str(t_lis *list, char *str)
{
	int	i;
	int	j;

	j = 0;
	if (list == NULL)
		return ;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_buf[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_newline(t_lis *list)
{
	int	i;
	int	j;

	i = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		j = 0;
		while (list->str_buf[j])
		{
			if (list->str_buf[j] == '\n')
			{
				i ++;
				return (i);
			}
			i ++;
			j ++;
		}
		list = list->next;
	}
	return (i);
}
