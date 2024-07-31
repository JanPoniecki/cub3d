/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:11:16 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:22 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	interpolation(int height, int txt_height, int point)
{
	float	sum;

	sum = txt_height * (float)((float)point / (float)height);
	sum -= 0.01;
	sum = floor(sum) + 1;
	if (sum > txt_height)
		sum --;
	return (sum);
}
