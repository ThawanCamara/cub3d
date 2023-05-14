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
		game->inst[i].obj = (t_obj *)malloc(sizeof(t_obj));
		if (!game->inst[i].obj || !game->inst[i].cam)
			return (assert_log(0, STR_SET_INST_S, STR_SET_INST_F));
		set_cam_data(&game->inst[i]);
		set_obj_data(game, &game->inst[i], i);
	}
	return (assert_log(game->inst != NULL,
			STR_SET_INST_S, STR_SET_INST_F));
}

void	inst_clear(t_game *game)
{
	short	i;
	t_inst	*ins;

	header_log("Clear", "Instances", B_YELLOW);
	i = -1;
	while (++i < game->total_insts)
	{
		ins = &game->inst[i];
		free(ins->cam);
		free(ins->obj);
	}
	free(game->inst);
}
