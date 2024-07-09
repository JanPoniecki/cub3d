/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:19:37 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/10 13:51:27 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	counter;
	int		switcher;

	counter = 0;
	while (*s)
	{
		switcher = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			if (switcher == 0)
			{
				counter++;
				switcher = 1;
			}
			s++;
		}
	}
	return (counter);
}

static int	safe_malloc(char **arr, int position, size_t buffer)
{
	int	i;

	i = 0;
	arr[position] = malloc(buffer);
	if (arr[position] == 0)
	{
		while (i < position)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		return (1);
	}
	return (0);
}

static int	fill(char **arr, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_malloc(arr, i, len + 1))
				return (1);
			ft_strlcpy(arr[i], s - len, len + 1);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**arr;

	if (s == 0)
		return (0);
	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (0);
	arr[words] = NULL;
	if (fill(arr, s, c))
		return (0);
	return (arr);
}
