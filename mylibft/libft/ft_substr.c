/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:54:09 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/06 10:31:26 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	newstr = (char *) malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (i < len)
	{
		newstr[i] = s[start];
		start ++;
		i ++;
	}
	newstr[i] = '\0';
	return (newstr);
}
