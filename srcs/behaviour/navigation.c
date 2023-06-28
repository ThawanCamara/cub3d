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

// static int	perception(t_game *game, t_inst *inst)
// {

// }

/* Mandatory */
void	player_move_rot(t_game *game, t_inst *inst)
{
	int	axis[2];
	int	angle;
	float key[4];

	axis[Y] = inst->cam->axis[TOP] - inst->cam->axis[BOT];
	axis[X] = inst->cam->axis[LEFT] - inst->cam->axis[RIGHT];
	angle = inst->cam->orientation[PORT] - inst->cam->orientation[STARBOARD];

	key[0] = cos(inst->obj->rotation * game->degtorad);
	key[1] = sin(inst->obj->rotation * game->degtorad);
	key[2] = cos((inst->obj->rotation + 90) * game->degtorad);
	key[3] = sin((inst->obj->rotation + 90) * game->degtorad);
	
		inst->obj->pos[X] += key[0] * axis[Y] * inst->obj->speed + key[2] * axis[X] * inst->obj->speed;
		inst->obj->pos[Y] -= key[1] * axis[Y] * inst->obj->speed + key[3] * axis[X] * inst->obj->speed;

	inst->obj->rotation += angle * inst->obj->turn_rate;
	if (inst->obj->rotation < 0)
		inst->obj->rotation = 360 + inst->obj->rotation;
	if (inst->obj->rotation >= 360)
		inst->obj->rotation = 360 - inst->obj->rotation;

	inst->obj->dir[X] = key[0] * game->zoom;
	inst->obj->dir[Y] = key[1] * game->zoom;
	
	inst->cam->plane[X] = key[2] * 0.66;
	inst->cam->plane[Y] = key[3] * 0.66;

	// 	inst->obj->pos[X] += cos(inst->obj->rotation * game->degtorad)/* inst->obj->dir[X] */ * axis[Y] * inst->obj->speed + cos((inst->obj->rotation + 90) * game->degtorad) * axis[X] * inst->obj->speed;
	// 	inst->obj->pos[Y] -= sin(inst->obj->rotation * game->degtorad)/* inst->obj->dir[Y] */ * axis[Y] * inst->obj->speed + sin((inst->obj->rotation + 90) * game->degtorad) * axis[X] * inst->obj->speed;

	// inst->obj->rotation += angle * inst->obj->turn_rate;
	// if (inst->obj->rotation < 0)
	// 	inst->obj->rotation = 360 + inst->obj->rotation;
	// if (inst->obj->rotation >= 360)
	// 	inst->obj->rotation = 360 - inst->obj->rotation;
	// inst->obj->dir[X] = cos(inst->obj->rotation * game->degtorad) * game->zoom;
	// inst->obj->dir[Y] = sin(inst->obj->rotation * game->degtorad) * game->zoom;
	
	// inst->cam->plane[X] = cos((inst->obj->rotation + 90) * game->degtorad) * 0.66;
	// inst->cam->plane[Y] = sin((inst->obj->rotation + 90) * game->degtorad) * 0.66;
}
