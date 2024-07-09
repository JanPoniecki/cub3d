/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:15:04 by bkotwica          #+#    #+#             */
/*   Updated: 2024/06/12 08:17:41 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (0);
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s ++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
}
