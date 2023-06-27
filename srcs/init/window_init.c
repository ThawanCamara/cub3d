/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:55:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/09 14:55:30 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	window_init(t_game *game)
{
	header_log("Initialization", "Window", B_ORANGE);
	print_log(1, STR_SET_WINDOW);
	game->win = mlx_new_window(game->mlx, game->screen->size[X],
			game->screen->size[Y], TITLE);
	if (!game->win)
		return (assert_log(0, STR_SET_WINDOW_S, STR_SET_WINDOW_F));
	setup_controls(game);
	return (assert_log(game->win != NULL,
			STR_SET_WINDOW_S, STR_SET_WINDOW_F));
}

void	window_clear(t_game *game)
{
	header_log("Clear", "Window", B_YELLOW);
	mlx_destroy_window(game->mlx, game->win);
}
