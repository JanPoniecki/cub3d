/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:40:38 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/05 13:15:10 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 != 0 || *s2 != 0) && n-- > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *) s1 - *(unsigned char *) s2);
		s1 ++;
		s2 ++;
	}
	return (0);
}
