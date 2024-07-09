/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:09:51 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:04:53 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putunbr(n / 10);
		i += ft_putunbr(n % 10);
	}
	else
	{
		n += '0';
		i += ft_putchar(n);
	}
	return (i);
}
