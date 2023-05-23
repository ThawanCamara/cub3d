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
	int	lower[2];
	int	upper[2];
	int	pos[2];

	axis = inst->cam->axis[TOP] - inst->cam->axis[BOT];
	angle = inst->cam->orientation[PORT] - inst->cam->orientation[STARBOARD];
	inst->obj->dir[X] = cos(inst->obj->rotation * game->degtorad);
	inst->obj->dir[Y] = sin(inst->obj->rotation * game->degtorad);
	// inst->cam->plane[X] = 0.707;
	// inst->cam->plane[Y] = 0.707;
	// inst->cam->plane[X] = cos(inst->obj->rotation * game->degtorad);
	// inst->cam->plane[Y] = sin(inst->obj->rotation * game->degtorad);
	vector2(0, 0, &lower[X], &lower[Y]);
	vector2(game->mapdata->size[X], game->mapdata->size[Y], &upper[X], &upper[Y]);
	pos[X] = inst->obj->pos[X] + inst->obj->dir[X] * axis * inst->obj->speed;
	pos[Y] = inst->obj->pos[Y] - inst->obj->dir[Y] * axis * inst->obj->speed;
	// printf("Pos : (%d, %d) - (%.2f, %.2f)\n", pos[X], pos[Y], inst->obj->pos[X], inst->obj->pos[Y]);
	// printf("Rot : (%.2f) - (%.2f, %.2f)\n", inst->obj->rotation, inst->obj->dir[X], inst->obj->dir[Y]);
	// printf("Valid: %d\n", check_bounds(pos, lower, upper));
	// if (check_map(game->mapdata, pos))
	if (check_bounds(pos, lower, upper))
	{
		inst->obj->pos[X] += inst->obj->dir[X] * axis * inst->obj->speed;
		inst->obj->pos[Y] -= inst->obj->dir[Y] * axis * inst->obj->speed;
	}
	inst->obj->rotation += angle * inst->obj->turn_rate;
	if (inst->obj->rotation < 0)
		inst->obj->rotation = 360 + inst->obj->rotation;
	if (inst->obj->rotation >= 360)
		inst->obj->rotation = 360 - inst->obj->rotation;
}
