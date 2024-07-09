/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:40:26 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/10 13:49:48 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*srcptr;
	unsigned char		*destptr;

	if (!dest && !src)
		return (dest);
	destptr = (unsigned char *)dest;
	srcptr = (const unsigned char *)src;
	while (n--)
		*destptr++ = *srcptr++;
	return (dest);
}
