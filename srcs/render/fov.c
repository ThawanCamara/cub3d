/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:26:15 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/10 19:26:15 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	get_fov(t_game *game, t_inst *inst, t_pane *pane)
{
	int			i;
	double		add;
	double		angle;

	// double		camera_x;

	i = -1 - inst->cam->fov_half;
	// add = 0;
	add = 0 - inst->cam->fov_half;

	// i = -1;

	// while (++i <= pane->size[X])
	while (++i <= inst->cam->fov_half)
	{
		// camera_x = 2 * i / (double)pane->size[X] - 1;
		// ray(game, inst, pane, camera_x, i);
		angle = (inst->obj->rotation + add) * game->degtorad; // AAAAAAAAAAAAAAAAAAAAAA
		// printf(">> %f\n", angle * (180/M_PI));
		// ray(game, inst, pane, angle, inst->cam->fov_half + i);
		// printf("%s\n", pane->name);
		ray(game, inst, pane, -angle, inst->cam->fov_half + i);
		add += inst->cam->fov_increment;
	}
}
// void	get_fov(t_game *game, t_inst *inst, int length, int color)
// {
// 	int			i;
// 	double		add;
// 	t_info	info;

// 	i = -1 - inst->cam->fov_half;
// 	add = 0 - inst->cam->fov_half;
// 	while (++i < inst->cam->fov_half)
// 	{
// 		info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
// 			+ game->pane[MINIMAP]->offset[X];
// 		info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
// 			+ game->pane[MINIMAP]->offset[Y];
// 		info.length = length;
// 		info.color = color;
// 		info.radians = (inst->obj->rotation + add) * game->degtorad;
// 		draw_line_r(game->pane[MINIMAP], &info);
// 		add += inst->cam->fov_increment;
// 	}
// }

// void	get_fov(t_game *game, t_inst *inst)
// {
// 	int			i;
// 	double		cameraX;

// 	i = -1;
// 	while (++i <= game->screen->size[X])
// 	{
// 		cameraX = 2 * i / (double)game->screen->size[X] - 1;
// 		ray(game, inst, game->pane[FULLSCREEN], cameraX);
// 	}
// }

void	render_fov(t_game *game)
{
	int	i;
	t_pane		*pane;

	i = -1;
	(void) game;
	while (++i < game->total_insts)
	{		
		if (!game->enable_parallax)
			pane = game->pane[FULLSCREEN];
		else
			pane = game->pane[i + 4];
		get_fov(game, &game->inst[i], pane);

	}
		// get_fov(game, &game->inst[i], 150, 0x00ff0000);

	// t_info	info;

	// info.pos[X] = game->inst[0].obj->pos[X] * game->ui->minimap_box_size
	// 	+ game->pane[MINIMAP]->offset[X];
	// info.pos[Y] = game->inst[0].obj->pos[Y] * game->ui->minimap_box_size
	// 	+ game->pane[MINIMAP]->offset[Y];
	// info.length = 150;
	// info.color = 0x00ff0000;
	// info.radians = (game->inst[0].obj->rotation) * game->degtorad;
	// draw_line_r(game->pane[MINIMAP], &info);
}
