/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:41 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:06:18 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percentcheck(const char *str, int position)
{
	if (str[position] == '%'
		&& str[position + 1] != '%')
		return (1);
	else if (str[position] == '%'
		&& str[position + 1] == '%')
		return (1);
	return (0);
}
