/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:57 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 14:51:25 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Initializes memory for the game's modules */
int	data_init(t_game *game)
{
	header_log("Initialization", "Data", B_ORANGE);
	print_log(1, STR_MLX_CONNECT);
	game->mlx = mlx_init();
	game->degtorad = M_PI / 180;
	return (assert_log(game->mlx != NULL,
			STR_MLX_CONNECT_S, STR_MLX_CONNECT_F));
}

/* Clears allocations made for the game hub */
void	data_clear(t_game *game)
{
	header_log("Clear", "Data", B_YELLOW);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

/* Safe emergencial exit */
void	safe_exit(t_game *game)
{
	window_clear(game);
	pane_clear(game);
	screen_clear(game);
	inst_clear(game);
	data_clear(game);
	map_clear(game);
	exit(0);
}
