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
	char 	validation;
	short	i;
	t_inst *ins;

	header_log("Initialization", "Instances", B_ORANGE);
	print_log(1, STR_SET_INST);
	game->inst = (t_inst *)malloc(sizeof(t_inst) * game->total_insts);
	i = -1;
	validation = 1;
	while (++i < game->total_insts)
	{
		ins = &game->inst[i];
		ins->render = (t_render *)malloc(sizeof(t_render) * game->total_insts);
		ins->cam = (t_cam *)malloc(sizeof(t_cam) * game->total_insts);
		//ins->cam = NULL;
		validation *= ins->render && ins->cam;
	}
	condition_log(game->inst && validation, STR_SET_INST_S, STR_SET_INST_F);
	return (game->inst && validation);
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
		free(ins->render);
		free(ins->cam);
	}
	free(game->inst);
}