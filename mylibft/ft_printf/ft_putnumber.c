/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:31:26 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:04:49 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumber(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i ++;
	}
	if (n > 9)
	{
		i += ft_putnumber(n / 10);
		i += ft_putnumber(n % 10);
	}
	else
	{
		n += '0';
		ft_putchar(n);
		i ++;
	}
	return (i);
}
