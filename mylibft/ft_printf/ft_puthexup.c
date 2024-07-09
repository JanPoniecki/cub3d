/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:03:19 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:04:47 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexup(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthexup(n / 16);
		i += ft_puthexup(n % 16);
	}
	else
	{
		if (n >= 10)
			ft_putchar("ABCDEF"[(n % 16) - 10]);
		else
		{
			n += '0';
			ft_putchar(n);
		}
		i ++;
	}
	return (i);
}
