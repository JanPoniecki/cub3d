/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:37:08 by bkotwica          #+#    #+#             */
/*   Updated: 2024/02/29 11:51:30 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*nr;
	int		i;
	int		sign;
	int		num;

	num = 0;
	sign = 1;
	i = 0;
	nr = (char *) nptr;
	while (nr[i] == 32 || nr[i] == '\r' || nr[i] == '\n'
		|| nr[i] == '\v' || nr[i] == '\f' || nr[i] == '\t')
		i ++;
	if (nr[i] == '-' || nr[i] == '+')
	{
		if (nr[i] == '-')
			sign = -1;
		i ++;
	}
	while (nr[i] <= '9' && nr[i] >= '0')
	{
		num = num * 10 + nr[i] - '0';
		i ++;
	}
	return (sign * num);
}
