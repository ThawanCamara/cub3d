/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:57 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/04 22:33:46 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Initializes memory for the game's modules */
int	data_init(t_game *game)
{
	header_log("Initialization", "Data", B_ORANGE);
	print_log(1, STR_MLX_CONNECT);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!game->win)
		return (assert_log(!game->win, STR_MLX_CONNECT_S, STR_MLX_CONNECT_F));
	/* EXPERIMENTAL */
	game->imgdata = (t_imgdata *)malloc(sizeof(t_imgdata));
	/*  */
	setup_controls(game);
	assert_log(game->mlx != NULL, STR_MLX_CONNECT_S, STR_MLX_CONNECT_F);
	return (game->mlx != NULL);
}

/* Clears allocations made for the game hub */
void	data_clear(t_game *game)
{
	header_log("Clear", "Data", B_YELLOW);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	/* EXPERIMENTAL */
	free(game->imgdata);
	/*  */
	free(game->mlx);
}

/*  */
void	safe_exit(t_game *game)
{
	inst_clear(game);
	data_clear(game);
	map_clear(game);
}
