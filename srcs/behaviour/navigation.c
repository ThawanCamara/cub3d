/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:15:06 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 13:15:06 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Mandatory */
void	player_move_rot(t_game *game, t_inst *inst)
{
	int	axis;
	int	angle;

	axis = inst->cam->axis[BOT] - inst->cam->axis[TOP];
	angle = inst->cam->orientation[PORT] - inst->cam->orientation[STARBOARD];
	inst->obj->pos[X] -= cos(-inst->obj->rotation * game->degtorad) * axis
		* inst->obj->speed;
	inst->obj->pos[Y] -= sin(-inst->obj->rotation * game->degtorad) * axis
		* inst->obj->speed;
	inst->obj->rotation += angle * inst->obj->turn_rate;
}

// void	player_move_rot_bonus(t_inst *inst)
// {
// 	int	v_axis;
// 	int	h_axis;

// 	v_axis = inst->cam->axis[BOT] - inst->cam->axis[TOP];
// 	h_axis = inst->cam->axis[RIGHT] - inst->cam->axis[LEFT];
// 	inst->cam->pos[X] += v_axis * inst->cam->speed;
// 	inst->cam->pos[Y] += h_axis * inst->cam->speed;
// }
