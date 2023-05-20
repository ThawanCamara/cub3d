/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:26:29 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/10 19:26:29 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	render_game(t_game *game)
{
	render_skyfloor(game);
	// draw_rect(game->screen, game->pane[MINIMAP]->size,
	// 	game->pane[MINIMAP]->offset, 0x00545454);
	// int pos[2];
	// int size[2];
	render_minimap(game);
	render_fov(game);
	
	t_info info;
	info.pos[X] = game->inst[0].obj->pos[X] * game->ui->minimap_box_size
		+ game->pane[MINIMAP]->offset[X];
	info.pos[Y] = game->inst[0].obj->pos[Y] * game->ui->minimap_box_size
		+ game->pane[MINIMAP]->offset[Y];
	info.length = 75;
	info.color = 0x00000000;
	info.radians = game->inst[0].obj->rotation * game->degtorad;
	draw_line_r(game->pane[MINIMAP], &info);

	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
	return (0);
}
