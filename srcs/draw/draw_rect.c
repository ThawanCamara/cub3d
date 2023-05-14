/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:03:06 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/30 15:03:06 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_rect(t_screen *idata, int *size, int *pos, int color)
{
	int	i[2];
	int	newpos[2];
	i[X] = 0;
	i[Y] = 0;
	while (i[X] < size[X] && i[Y] < size[Y])
	{
		newpos[X] = pos[X] + i[X];
		newpos[Y] = pos[Y] + i[Y];
		draw_pixel(idata, newpos, color);
		i[X]++;
		if (i[X] == size[X] && i[Y] < size[Y])
		{
			i[X] = 0;
			i[Y]++;
		}
	}
}
