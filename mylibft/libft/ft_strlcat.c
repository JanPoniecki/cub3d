/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:43:27 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/10 13:51:47 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	lend;
	size_t			i;
	unsigned int	lens;

	if ((!dest || !src) && !size)
		return (0);
	i = 0;
	lens = ft_strlen(src);
	lend = ft_strlen(dest);
	if (size == 0 && dest == 0)
		return (lens);
	if (size == 0 || size <= lend)
		return (lens + size);
	while (src[i] && lend + i < size - 1)
	{
		dest[lend + i] = src[i];
		i++;
	}
	dest[lend + i] = '\0';
	return (lend + lens);
}
