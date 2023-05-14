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

 void	get_fov(t_game *game, t_inst *inst, int length, int color)
{
	int			i;
	double		add;
	t_draw_info	info;

	i = -1 - inst->cam->fov_half;
	add = 0 - inst->cam->fov_half;
	while (++i < inst->cam->fov_half)
	{
		info.pos[X] = inst->cam->pos[X] * game->ui->minimap_box_size + game->pane[MINIMAP]->offset[X];
		info.pos[Y] = inst->cam->pos[Y] * game->ui->minimap_box_size + game->pane[MINIMAP]->offset[Y];
		info.length = length;
		info.color = color;
		info.radians = (inst->cam->rotation + add) * game->degtorad;
		draw_line(game->pane[MINIMAP], &info);
		add += inst->cam->fov_increment;
	}
}

void	render_fov(t_game *game)
{
	int	i;
	int	color[2];

	i = -1;
	color[0] = 0x0000FF00;
	color[1] = 0x00FF0000;
	(void) game;
	(void) color;
	while (++i < game->total_insts)
		get_fov(game, &game->inst[i], 150, color[i]);
}
