/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:57:19 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/05 09:54:40 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	newstr = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstr)
		return (0);
	if (*s == '\0')
	{
		newstr[i] = '\0';
		return (newstr);
	}
	while (*s != 0)
	{
		newstr[i] = *s;
		i ++;
		s ++;
	}
	newstr[i] = '\0';
	return (newstr);
}
