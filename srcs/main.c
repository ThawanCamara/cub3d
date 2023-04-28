/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/28 08:07:38 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argc;
	(void)argv;
	init_handler(&game);
	mlx_string_put(game.render->mlx, game.render->win, 500, 400, 0x00ff0000, "PINTO");
	mlx_string_put(game.render->mlx, game.render->nwin, 500, 400, 0x0000ff00, "PINTO");
	mlx_loop(game.render->mlx);
	//data_clear(&game);
	return (0);
}
