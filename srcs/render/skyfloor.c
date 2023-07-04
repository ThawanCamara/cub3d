/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyfloor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:12:02 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/03 20:23:01 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_skyfloor(t_game *game)
{
	t_pane	*pane;
	t_idraw	info;

	pane = game->pane[TOPHALF];
	info.pos[X] = pane->min_bounds[X];
	info.pos[Y] = pane->min_bounds[Y];
	info.size[X] = pane->size[X];
	info.size[Y] = pane->size[Y];
	info.color = game->mapdata->trgb[SKY];
	draw_rect(pane, &info);
	pane = game->pane[BOTHALF];
	info.pos[X] = pane->min_bounds[X];
	info.pos[Y] = pane->min_bounds[Y];
	info.size[X] = pane->size[X];
	info.size[Y] = pane->size[Y];
	info.color = game->mapdata->trgb[FLOOR];
	draw_rect(pane, &info);
}
