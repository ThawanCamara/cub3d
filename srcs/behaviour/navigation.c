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
	int	lower[2];
	int	upper[2];
 	// double oldPlaneX;

	axis[Y] = inst->cam->axis[TOP] - inst->cam->axis[BOT];
	axis[X] = inst->cam->axis[LEFT] - inst->cam->axis[RIGHT];
	angle = inst->cam->orientation[PORT] - inst->cam->orientation[STARBOARD];
	vector2(0, 0, &lower[X], &lower[Y]);
	vector2(game->mapdata->size[X], game->mapdata->size[Y], &upper[X], &upper[Y]);
	// if ((game->mapdata, pos))
	// if (check_bounds(pos, lower, upper))
	// {
		inst->obj->pos[X] += cos(inst->obj->rotation * game->degtorad)/* inst->obj->dir[X] */ * axis[Y] * inst->obj->speed + cos((inst->obj->rotation + 90) * game->degtorad) * axis[X] * inst->obj->speed;
		inst->obj->pos[Y] -= sin(inst->obj->rotation * game->degtorad)/* inst->obj->dir[Y] */ * axis[Y] * inst->obj->speed + sin((inst->obj->rotation + 90) * game->degtorad) * axis[X] * inst->obj->speed;
	// }
	inst->obj->rotation += angle * inst->obj->turn_rate;
	if (inst->obj->rotation < 0)
		inst->obj->rotation = 360 + inst->obj->rotation;
	if (inst->obj->rotation >= 360)
		inst->obj->rotation = 360 - inst->obj->rotation;
	inst->obj->dir[X] = cos(inst->obj->rotation * game->degtorad) * game->zoom;
	inst->obj->dir[Y] = sin(inst->obj->rotation * game->degtorad) * game->zoom;
	
	inst->cam->plane[X] = cos((inst->obj->rotation + 90) * game->degtorad) * 0.66;
	inst->cam->plane[Y] = sin((inst->obj->rotation + 90) * game->degtorad) * 0.66;
	// printf("X: %f | Y: %f\n", inst->cam->plane[X], inst->cam->plane[Y]);
	

	// oldPlaneX = inst->cam->plane[X];
	// if (angle < 0)
	// {
		// inst->cam->plane[X] = oldPlaneX * cos(-inst->obj->turn_rate) - inst->cam->plane[Y] * sin(-inst->obj->turn_rate);
		// inst->cam->plane[Y] = oldPlaneX * sin(-inst->obj->turn_rate) + inst->cam->plane[Y] * cos(-inst->obj->turn_rate);
	// }
	// else if (angle > 0)
	// {
	// 	inst->cam->plane[X] = oldPlaneX * cos(inst->obj->turn_rate) - inst->cam->plane[Y] * sin(inst->obj->turn_rate);
	// 	inst->cam->plane[Y] = oldPlaneX * sin(inst->obj->turn_rate) + inst->cam->plane[Y] * cos(inst->obj->turn_rate);
	// }

	
	// printf("Angle: %f, X: %f, Y: %f\n", inst->obj->rotation, inst->obj->dir[X], inst->obj->dir[Y]);
}
