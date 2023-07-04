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

void	set_cam_data(t_game *game, t_inst *inst)
{
	inst->cam->axis[TOP] = 0;
	inst->cam->axis[BOT] = 0;
	inst->cam->axis[LEFT] = 0;
	inst->cam->axis[RIGHT] = 0;
	inst->cam->orientation[PORT] = 0;
	inst->cam->orientation[STARBOARD] = 0;
	inst->cam->plane[X] = 0;
	inst->cam->plane[Y] = 0.66;
	(void) game;
}

void	set_obj_data(t_game *game, t_inst *inst, int i)
{
	(void)game;
	(void)i;
	inst->obj->tag = 'P';
	inst->obj->dir[X] = 0;
	inst->obj->dir[Y] = 1;
	inst->obj->collision = 40;
	inst->obj->speed = PLAYER_SPEED * 0.002;
	inst->obj->turn_rate = PLAYER_TURN * 0.05;
}
