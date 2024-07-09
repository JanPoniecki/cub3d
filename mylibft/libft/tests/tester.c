/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:53:33 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:16:04 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/*
int	main(void)
{
	// // ft_split.c
	// printf("SPLIT------------------ \n");
	// char	*ft_strsplit = "     taknie  nas e  ";
	// char	character_to_split = ' ';
	// char	**listofstr = ft_split(ft_strsplit, character_to_split);
	// int		i = 0;
	// while (i < 3)
	// {
	// 	printf("%s\n", listofstr[i]);
	// 	//free(listofstr[i]);
	// 	i ++;
	// }
	// free(listofstr);
	// ft_putnbr_fd
	printf("ft_putnbr_fd---------\n");
	int	putnbrfd = open("examplenbr.txt", O_RDWR | O_CREAT, 0644);
	ft_putnbr_fd(123, putnbrfd);
	// ft_putendl_fd
	printf("ft_putendl_fd---------\n");
	int	putendl = open("exampleend.txt", O_RDWR | O_CREAT, 0644);
	ft_putendl_fd("tak", putendl);
	// ft_putstr_fd
	printf("ft_putstr_fd---------\n");
	int	putchar = open("examplechar.txt", O_RDWR | O_CREAT, 0644);
	ft_putstr_fd("tak", putchar);
	// ft_putchar_fd
	printf("ft_putchar_fd---------\n");
	// Utworzyc plik example.txt i sprawdzic
	int	putfd = open("example.txt", O_RDWR | O_CREAT, 0644);
	// O_RDWR read/write mode
	ft_putchar_fd('a', putfd);
	// ft_striteri
	void	ftv_toupper(unsigned int a, char *c)
	{
		(void) a;
		if (*c <= 'z' && *c >= 'a')
			*c = (*c - 32);
	}
	void	ftv_tolower(unsigned int a, char *c)
	{
		(void) a;
		if (*c <= 'Z' && *c >= 'A')
			*c = (*c + 32);
	}
	printf("strinteri---------\n");
	char	strinteri[10] = "tak";
	char	strinter1[10] = "TAK";
	ft_striteri(strinteri, ftv_toupper);
	for (int i = 0; i < 3; i ++)
	{
		if (strinteri[i] != strinter1[i])
			printf (" 0 ");
		else
			printf (" 1 ");
	}
	ft_striteri(strinter1, ftv_tolower);
	char	strinter2[10] = "tak";
	for (int i = 0; i < 3; i ++)
	{
		if (strinter1[i] != strinter2[i])
			printf (" 0 ");
		else
			printf (" 1 ");
	}
	printf("\n");
	// ft_strmapi
	char	fto_toupper(unsigned int a, char c)
	{
		(void) a;
		if (c <= 'z' && c >= 'a')
			return (c - 32);
		return (c);
	}
	char	fto_tolower(unsigned int a, char c)
	{
		(void) a;
		if (c <= 'Z' && c >= 'A')
			return (c + 32);
		return (c);
	}
	printf("strmapi---------\n");
	char	*s = ft_strmapi("tak", fto_toupper);
	char	ss[10] = "TAK";
	for (int i = 0; i < 3; i ++)
	{
		if (s[i] != ss[i])
			printf (" 0 ");
		else
			printf (" 1 ");
	}
	char	*ss1 = ft_strmapi("TAK", fto_tolower);
	char	s1[10] = "tak";
	for (int i = 0; i < 3; i ++)
	{
		if (ss1[i] != s1[i])
			printf (" 0 ");
		else
			printf (" 1 ");
	}
	printf("\n");
	// itoa
	printf("ITOA---------\n");
	printf("%d ", ft_atoi(ft_itoa(-2147483647)) == -2147483647);
	printf("%d ", ft_atoi(ft_itoa(0)) == 0);
	printf("%d ", ft_atoi(ft_itoa(-32)) == -32);
	printf("%d\n", ft_atoi(ft_itoa(2147483647)) == 2147483647);
	// strtrim
	printf("STRTRIM---------\n");
	char	napis3[100] = " dNna Nie dial ";
	char	napis13[100] = " ";
	char	*trimedstring;
	trimedstring = ft_strtrim(napis3, napis13);
	printf("%s\n", trimedstring);
	//substr
	printf("SUBSTR---------\n");
	char	napis11[100] = "Nie";
	char	*napis21 = ft_substr(napis11, 2, 2);
	printf("%s\n", napis21);
	//strdup
	printf("STRDUP---------\n");
	char	napis10[100] = "jasderq";
	char	*napis20 = strdup(napis10);
	char	*napis30 = ft_strdup(napis10);
	printf("%s %s\n", napis20, napis30);
	//calloc
	printf("CALLOC---------\n");
	int	*ptr = (int *) calloc(10, sizeof(int));
	int	*ptr1 = (int *) ft_calloc(10, sizeof(int));
	for (int i = 0; i < 15; i++)
		printf("%d", ptr[i]);
	printf("\n");
	for (int i = 0; i < 15; i++)
		printf("%d", ptr1[i]);
	printf("\n");
	//atoi
	printf("ATOI---------\n");
	char liczba[13] = "  -324";
	printf("%d ", ft_atoi(liczba) == -324);
	printf("%d ", ft_atoi("  	0") == 0);
	printf("%d ", ft_atoi("-+3") == 0);
	printf("%d\n", ft_atoi("234f43") == 234);
}
*/
