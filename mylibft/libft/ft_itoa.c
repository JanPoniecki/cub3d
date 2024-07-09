/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:04:04 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/10 13:50:09 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	d_count(int number)
{
	int	counter;

	counter = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		counter++;
	while (number)
	{
		number /= 10;
		counter++;
	}
	return (counter);
}

static void	min_int(char *number, int *n, int *len)
{
	if (*n == -2147483648)
	{
		number[(*len)--] = (-(*n % 10)) + '0';
		*n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	len = d_count(n);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (0);
	number[len--] = '\0';
	if (n == 0)
		number[0] = '0';
	min_int(number, &n, &len);
	if (n < 0)
	{
		number[0] = '-';
		n *= -1;
	}
	while (n)
	{
		number[len--] = n % 10 + '0';
		n /= 10;
	}
	return (number);
}
