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

void	draw_rect(t_pane *pane, t_idraw *info)
{
	int	i[2];
	int	newpos[2];

	i[X] = 0;
	i[Y] = 0;
	while (i[X] < info->size[X] && i[Y] < info->size[Y])
	{
		newpos[X] = info->pos[X] + i[X];
		newpos[Y] = info->pos[Y] + i[Y];
		if (check_bounds(newpos, pane->min_bounds, pane->max_bounds)
			&& check_mapbounds(newpos, pane->screen->size))
			draw_pixel(pane->screen, newpos, info->color);
		i[X]++;
		if (i[X] == info->size[X] && i[Y] < info->size[Y])
		{
			i[X] = 0;
			i[Y]++;
		}
	}
}
