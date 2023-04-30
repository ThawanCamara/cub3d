/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/29 23:25:21 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argc;
	(void)argv;

	/* Temp */
	game.enable_parallax = 0;
	game.total_insts = 1;

	init_handler(&game);
	mlx_string_put(game.mlx, game.inst->render->win, 500, 400, 0x00ff0000, "PINTO");
	mlx_loop(game.mlx);

	clear_handler(&game, FUNC_TABLE_SIZE - 1);
	return (0);
}
