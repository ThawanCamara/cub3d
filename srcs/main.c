/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/14 14:34:53 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argc;
	(void)argv;
	game.enable_parallax = TRUE;
	game.total_insts = 1 + game.enable_parallax;
	init_handler(&game);
	mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
