/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:47:10 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/10 15:47:10 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// double	get_minimap_scale(t_game *game, t_pane *pane)
// {
// 	double	scale;
// 	t_map	*mapdata;

// 	mapdata = game->mapdata;
// 	scale = 1;
// 	if ((pane->size[X] / ((double)mapdata->size[X] * BOX_SIZE)) < scale)
// 		scale = pane->size[X] / ((double)mapdata->size[X] * BOX_SIZE);
// 	if ((pane->size[Y] / ((double)mapdata->size[Y] * BOX_SIZE)) < scale)
// 		scale = pane->size[Y] / ((double)mapdata->size[Y] * BOX_SIZE);
// 	return (scale);
// }
double	get_minimap_scale(t_game *game, t_pane *pane)
{
	double	scale_x;
	double	scale_y;
	t_map	*mapdata;

	mapdata = game->mapdata;
	scale_x = pane->size[X] / ((double)mapdata->size[X] * BOX_SIZE);
	scale_y = pane->size[Y] / ((double)mapdata->size[Y] * BOX_SIZE);
	if (scale_x < scale_y)
		return (scale_x);
	else
		return (scale_y);
}

void	map_topixel(t_pane *pane, int *pos, int *pixel)
{
	int	size;

	size = pane->game->ui->minimap_box_size;
	pixel[X] = pos[X] * size + pane->offset[X];
	pixel[Y] = pos[Y] * size + pane->offset[Y];
}

int	map_getpixel_x(t_pane *pane, int x)
{
	return (x * pane->game->ui->minimap_box_size + pane->offset[X]);
}

int	map_getpixel_y(t_pane *pane, int y)
{
	return (y * pane->game->ui->minimap_box_size + pane->offset[Y]);
}
