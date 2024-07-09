/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:33:14 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/03 17:57:08 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_percentcheck(const char *str, int position);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnumber(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n);
int	ft_puthexup(unsigned int n);
int	ft_void_pointer(void *ptr);
int	ft_printf(const char *str, ...);

#endif
