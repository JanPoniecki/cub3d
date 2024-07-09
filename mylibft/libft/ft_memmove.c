/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:28:24 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/05 09:43:12 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;
	size_t	i;

	if (!dest && !src)
		return (0);
	tmp_src = (char *) src;
	tmp_dest = (char *) dest;
	if (tmp_dest > tmp_src)
	{
		while (n -- > 0)
			tmp_dest[n] = tmp_src[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i ++;
		}
	}
	return (dest);
}
