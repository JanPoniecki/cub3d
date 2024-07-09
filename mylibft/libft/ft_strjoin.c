/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:04:56 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/05 17:49:26 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *) malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (0);
	while (s1[i] != '\0')
		newstr[j ++] = s1[i ++];
	i = 0;
	while (s2[i] != '\0')
		newstr[j ++] = s2[i ++];
	newstr[j] = '\0';
	return (newstr);
}
