/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:36:42 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/14 16:36:42 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ray(t_game *game, )

// static void	ray_fov(t_game *game, t_inst *inst, int color)
// {
// 	int			i;
// 	double		add;
// 	t_draw_info	info;

// 	i = -1 - inst->cam->fov_half;
// 	add = 0 - inst->cam->fov_half;
// 	while (++i < inst->cam->fov_half)
// 	{
// 		info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
// 			+ game->pane[MINIMAP]->offset[X];
// 		info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
// 			+ game->pane[MINIMAP]->offset[Y];
// 		info.color = color;
// 		info.radians = (inst->obj->rotation + add) * game->degtorad;
// 		draw_line(game->pane[MINIMAP], &info);
// 		add += inst->cam->fov_increment;
// 	}
// }

void	raycaster(t_game *game)
{
	
}
