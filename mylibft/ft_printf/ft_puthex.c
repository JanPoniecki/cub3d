/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:30:19 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:04:44 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthex(n / 16);
		i += ft_puthex(n % 16);
	}
	else
	{
		if (n >= 10)
			ft_putchar("abcdef"[(n % 16) - 10]);
		else
		{
			n += '0';
			ft_putchar(n);
		}
		i ++;
	}
	return (i);
}
