/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:03:03 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/29 01:03:03 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static double	get_rotation(char rot);

int	inst_init(t_game *game)
{
	short	i;

	header_log("Initialization", "Instances", B_ORANGE);
	print_log(1, STR_SET_INST);
	game->inst = (t_inst *)malloc(sizeof(t_inst) * game->total_insts);
	if (!game->inst)
		return (assert_log(0, STR_SET_INST_S, STR_SET_INST_F));
	i = -1;
	while (++i < game->total_insts)
	{
		game->inst[i].cam = (t_cam *)malloc(sizeof(t_cam));
		if (!game->inst[i].cam)
			return (assert_log(game->inst[i].cam != NULL,
					STR_SET_INST_S, STR_SET_INST_F));
		game->inst[i].cam->pos[X] = game->mapdata->start_pos[X + (i * 2)]; 
		game->inst[i].cam->pos[Y] = game->mapdata->start_pos[Y + (i * 2)]; 
		game->inst[i].cam->rotation = get_rotation(game->mapdata->inst_rot[i]);
		game->inst[i].cam->axis[TOP] = 0;
		game->inst[i].cam->axis[BOT] = 0;
		game->inst[i].cam->axis[LEFT] = 0;
		game->inst[i].cam->axis[RIGHT] = 0;
		game->inst[i].cam->speed = PLAYER_SPEED * 0.01;
		game->inst[i].cam->turn_rate = PLAYER_TURN * 0.01;
		game->inst[i].cam->fov = 66;
		game->inst[i].cam->fov_half = SCREEN_WIDTH / 2;
		game->inst[i].cam->fov_increment = (double)game->inst[i].cam->fov / SCREEN_WIDTH;
		// game->inst[i].cam->collision = 0.4;
	}
	return (assert_log(game->inst != NULL,
			STR_SET_INST_S, STR_SET_INST_F));
}

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

void	inst_clear(t_game *game)
{
	short	i;
	t_inst *ins;

	header_log("Clear", "Instances", B_YELLOW);
	i = -1;
	while (++i < game->total_insts)
	{
		ins = &game->inst[i];
		free(ins->cam);
	}
	free(game->inst);
}
