/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:04 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/04 19:53:12 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_lis *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(sizeof(char) * (str_len + 1));
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

int	is_newline(t_lis *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i ++;
		}
		list = list->next;
	}
	return (0);
}

void	append(t_lis **list, char *buffer)
{
	t_lis	*new_node;
	t_lis	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_lis));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buffer;
	new_node->next = NULL;
}

void	create_list(t_lis **list, int fd)
{
	int		read_num;
	char	*buffer;

	while (!is_newline(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (!read_num || read_num < 0)
		{
			free(buffer);
			return ;
		}
		buffer[read_num] = '\0';
		append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_lis	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list);
	return (next_line);
}
