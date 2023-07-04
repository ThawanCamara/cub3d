/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:46:01 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/28 18:46:01 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	debug_ray(t_game *game, t_rayhit *hit, int color)
{
	t_idraw	info;

	info.pos[X] = hit->start[X] * game->ui->minimap_box_size
		+ game->pane[MINIMAP]->offset[X];
	info.pos[Y] = hit->start[Y] * game->ui->minimap_box_size
		+ game->pane[MINIMAP]->offset[Y];
	info.length = hit->distance * game->ui->minimap_box_size;
	info.color = color;
	info.dir[X] = hit->dir[X];
	info.dir[Y] = hit->dir[Y];
	draw_line_dir(game->pane[MINIMAP], &info);
}
