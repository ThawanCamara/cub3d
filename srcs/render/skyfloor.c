/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyfloor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:12:02 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/17 17:29:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_skyfloor(t_game *game)
{
	t_pane	*pane;
	int		color;
	
	pane = game->pane[TOPHALF];
	color = game->mapdata->trgb[SKY];
	draw_rect(game->screen, pane->size, pane->min_bounds, color);
	pane = game->pane[BOTHALF];
	color = game->mapdata->trgb[FLOOR];
	draw_rect(game->screen, pane->size, pane->min_bounds, color);
}
