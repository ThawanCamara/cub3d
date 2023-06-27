/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/06/18 17:22:20 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (check_args(&game, argc, argv))
		return (1);
	game.enable_parallax = FALSE;
	game.total_insts = 1 + game.enable_parallax;
	game.zoom = 1;
	init_handler(&game);
	mlx_loop_hook(game.mlx, loop_handler, &game);
	mlx_loop(game.mlx);
	return (0);
}
