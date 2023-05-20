/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:22:01 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/14 14:22:01 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static double	get_rotation(char rot)
{
	if (rot == 'N')
		return (90);
	else if (rot == 'S')
		return (270);
	else if (rot == 'W')
		return (180);
	else if (rot == 'E')
		return (0);
	return (35);
}

void	set_cam_data(t_game *game, t_inst *inst)
{
	inst->cam->axis[TOP] = 0;
	inst->cam->axis[BOT] = 0;
	inst->cam->axis[LEFT] = 0;
	inst->cam->axis[RIGHT] = 0;
	inst->cam->orientation[PORT] = 0;
	inst->cam->orientation[STARBOARD] = 0;
	inst->cam->fov = 66;
	inst->cam->fov_half = game->screen->size[X] / 2;
	inst->cam->fov_increment = (double)inst->cam->fov / SCREEN_WIDTH;
	inst->cam->plane[X] = 0;
	inst->cam->plane[Y] = 0.66;
}

void	set_obj_data(t_game *game, t_inst *inst, int i)
{
	inst->obj->tag = 'P';
	inst->obj->pos[X] = game->mapdata->start_pos[X + (i * 2)];
	inst->obj->pos[Y] = game->mapdata->start_pos[Y + (i * 2)];
	inst->obj->rotation = get_rotation(game->mapdata->inst_rot[i]);
	inst->obj->dir[X] = 0;
	inst->obj->dir[Y] = 1;
	// inst->obj->collision = 100 * 0.01;
	inst->obj->speed = PLAYER_SPEED * 0.01;
	inst->obj->turn_rate = PLAYER_TURN * 0.01;
}
