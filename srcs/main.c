/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/03 21:19:50 by tde-souz         ###   ########.fr       */
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
	game.allow_resize = 1;
	game.allow_zoom = 1;
	game.zoom = 1;
	game.show_minimap = 0;
	init_handler(&game);
	if (game.mapdata->size[X] > game.mapdata->size[Y])
		game.map_resize = game.mapdata->size[X];
	else
		game.map_resize = game.mapdata->size[Y];
	mlx_loop_hook(game.mlx, loop_handler, &game);
	mlx_loop(game.mlx);
	return (0);
}
