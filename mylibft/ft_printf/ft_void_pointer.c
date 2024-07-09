/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:11:09 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:05:02 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printer(void *ptr)
{
	int	len;

	len = 0;
	if ((unsigned long)ptr >= 16)
	{
		len += printer((void *)((unsigned long)ptr / 16));
		len += printer((void *)((unsigned long)ptr % 16));
	}
	else
		len += ft_putchar("0123456789abcdef"[(unsigned long)ptr % 16]);
	return (len);
}

int	ft_void_pointer(void *ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (printer(ptr) + 2);
}
