/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:50:04 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:10 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdlib.h>

void	ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

char	*dec_to_hex_helper(unsigned int n)
{
	char	*hex_digits;
	char	*result;
	char	*rest;

	hex_digits = "0123456789ABCDEF";
	if (n < 16)
	{
		result = malloc(2);
		if (result == NULL)
			return (NULL);
		result[0] = hex_digits[n];
		result[1] = '\0';
	}
	else
	{
		rest = dec_to_hex_helper(n / 16);
		result = malloc(ft_strlen(rest) + 2);
		if (result == NULL)
			return (NULL);
		ft_strcpy(result, rest);
		result[ft_strlen(rest)] = hex_digits[n % 16];
		result[ft_strlen(rest) + 1] = '\0';
		free(rest);
	}
	return (result);
}

char	*dec_to_hex(char *str)
{
	unsigned int	n;

	n = ft_atoi(str);
	return (dec_to_hex_helper(n));
}
