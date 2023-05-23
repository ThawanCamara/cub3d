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
	/* player white angle */

	/* player blue plane */
	int	i;

	i = -1;
	while (++i < game->total_insts)
	{		
		info.pos[X] = game->inst[i].obj->pos[X] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[X];
		info.pos[Y] = game->inst[i].obj->pos[Y] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[Y];
		info.length = 300;
		info.color = 0x00ffffff;
		info.radians = game->inst[i].obj->rotation * game->degtorad;
		draw_line_r(game->pane[MINIMAP], &info);
		info.pos[X] = game->inst[i].obj->pos[X] * game->ui->minimap_box_size;
		info.pos[Y] = game->inst[i].obj->pos[Y] * game->ui->minimap_box_size;
		info.length = game->mapdata->size[Y] * game->ui->minimap_box_size;
		info.color = 0x000000FF;
		info.radians = (game->inst[i].obj->rotation - 90) * game->degtorad;
		draw_line_r(game->pane[FULLSCREEN], &info);
		info.pos[X] = game->inst[i].obj->pos[X] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[X];
		info.pos[Y] = game->inst[i].obj->pos[Y] * game->ui->minimap_box_size;
		info.length = -game->mapdata->size[Y] * game->ui->minimap_box_size;
		info.color = 0x000000FF;
		info.radians = (game->inst[i].obj->rotation - 90) * game->degtorad;
		draw_line_r(game->pane[FULLSCREEN], &info);
	}

	// t_info	info;

	// info.pos[X] = 300;
	// info.pos[Y] = 100;
	// info.length = 100;
	// info.color = 0x00FF0000;
	// draw_column(game->pane[FULLSCREEN], &info);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
	return (0);
}
