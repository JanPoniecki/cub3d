/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:30:32 by bkotwica          #+#    #+#             */
/*   Updated: 2024/07/30 13:31:50 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_on_y(t_core *main_struct, int change)
{
	int	index;

	main_struct->hero->y_index += change;
	index = main_struct->hero->y_index;
	if (index < PILLOW || index + PILLOW > main_struct->hero->y_end)
	{
		main_struct->hero->y_index -= change;
		return ;
	}
	main_struct->hero->pos[0] = main_struct->hero->y_axis[index][0];
	main_struct->hero->pos[1] = main_struct->hero->y_axis[index][1];
	calc_axis(main_struct->hero, 'x');
	calc_viev(main_struct->hero);
}

void	move_on_x(t_core *main_struct, int change)
{
	int	index;

	main_struct->hero->x_index += change;
	index = main_struct->hero->x_index;
	if (index < PILLOW || index + PILLOW > main_struct->hero->x_end)
	{
		main_struct->hero->x_index -= change;
		return ;
	}
	main_struct->hero->pos[0] = main_struct->hero->x_axis[index][0];
	main_struct->hero->pos[1] = main_struct->hero->x_axis[index][1];
	calc_axis(main_struct->hero, 'y');
	calc_viev(main_struct->hero);
}

void	rotate(t_core *main_struct, int change)
{
	main_struct->hero->angle += change;
	calc_axis(main_struct->hero, 'y');
	calc_axis(main_struct->hero, 'x');
	calc_viev(main_struct->hero);
}
