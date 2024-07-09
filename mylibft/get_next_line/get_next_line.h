/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:48 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/04 19:54:09 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl_list
{
	char				*str_buf;
	struct s_gnl_list	*next;
}						t_lis;

t_lis	*find_last_node(t_lis *list);
int		is_newline(t_lis *list);
int		len_to_newline(t_lis *list);
void	dealloc(t_lis **list, t_lis *clean_node, char *buffer);
void	polish_list(t_lis **list);
void	copy_str(t_lis *list, char *str);
void	append(t_lis **list, char *buffer);
void	create_list(t_lis **list, int fd);
char	*get_line(t_lis *list);
char	*get_next_line(int fd);

#endif
