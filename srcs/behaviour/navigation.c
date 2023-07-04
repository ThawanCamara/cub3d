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

int	perception(t_game *game, t_inst *inst, int value, int angle)
{
	t_iray		iray;
	t_rayhit	hit;
	int			color;

	iray.dir[X] = cos((inst->obj->rotation + angle)
	* game->degtorad);
	iray.dir[Y] = -sin((inst->obj->rotation + angle)
	* game->degtorad);
	iray.start[X] = inst->obj->pos[X];
	iray.start[Y] = inst->obj->pos[Y];
	iray.max_len = 0.2;
	if (angle == 0)
		iray.max_len = 0.35;
	ray2(game, &iray, &hit);
	if (hit.flag == 1)
	{
		color = 0x00ff0000;
		value = 0;
	}
	else
		color = 0x0000ff00;
	debug_ray(game, &hit, color);
	return (value);
}

static void	fix_rot(t_inst *inst)
{
	if (inst->obj->rotation < 0)
		inst->obj->rotation = 360 + inst->obj->rotation;
	if (inst->obj->rotation >= 360)
		inst->obj->rotation = 360 - inst->obj->rotation;
}

/* Mandatory */
void	player_move_rot(t_game *game, t_inst *inst)
{
	int		axis[2];
	int		angle;
	float	key[4];

	axis[Y] = inst->cam->axis[TOP] - inst->cam->axis[BOT];
	axis[Y] = perception(game, inst, axis[Y], 0 + (axis[Y] == -1) * 180);
	axis[X] = inst->cam->axis[LEFT] - inst->cam->axis[RIGHT];
	axis[X] = perception(game, inst, axis[X], 90 + (axis[X] == -1) * 180);
	angle = inst->cam->orientation[PORT] - inst->cam->orientation[STARBOARD];
	key[0] = cos(inst->obj->rotation * game->degtorad);
	key[1] = sin(inst->obj->rotation * game->degtorad);
	key[2] = cos((inst->obj->rotation + 90) * game->degtorad);
	key[3] = sin((inst->obj->rotation + 90) * game->degtorad);
	inst->obj->pos[X] += key[0] * axis[Y] * inst->obj->speed + key[2] * axis[X]
		* inst->obj->speed;
	inst->obj->pos[Y] -= key[1] * axis[Y] * inst->obj->speed + key[3] * axis[X]
		* inst->obj->speed;
	inst->obj->rotation += angle * inst->obj->turn_rate;
	fix_rot(inst);
	inst->obj->dir[X] = key[0] * game->zoom;
	inst->obj->dir[Y] = key[1] * game->zoom;
	inst->cam->plane[X] = key[2] * 0.66;
	inst->cam->plane[Y] = key[3] * 0.66;
}
