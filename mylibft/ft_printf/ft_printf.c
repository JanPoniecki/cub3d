/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:27:48 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/03 14:03:01 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printer(const char *str, unsigned int position, va_list ap)
{
	if (str[position + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str[position + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (str[position + 1] == 'p')
		return (ft_void_pointer(va_arg(ap, void *)));
	else if (str[position + 1] == 'd'
		|| str[position + 1] == 'i')
		return (ft_putnumber(va_arg(ap, int)));
	else if (str[position + 1] == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (str[position + 1] == 'x')
		return (ft_puthex(va_arg(ap, unsigned long int)));
	else if (str[position + 1] == 'X')
		return (ft_puthexup(va_arg(ap, unsigned int)));
	else if (str[position + 1] == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	position;
	int				len;
	int				printed;
	va_list			ap;

	position = 0;
	va_start(ap, str);
	len = 0;
	while (str[position])
	{
		if (!ft_percentcheck(str, position))
			len += ft_putchar(str[position]);
		else if (ft_percentcheck(str, position))
		{
			printed = printer(str, position, ap);
			if (printed == -1)
				return (-1);
			len += printed;
			position ++;
		}
		position++;
	}
	va_end(ap);
	return (len);
}
