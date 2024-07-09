/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:44:04 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:13:48 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0 && s)
	{
		if (*(unsigned char *) s == (unsigned char) c)
			return ((unsigned char *)s);
		s ++;
	}
	return (0);
}
