/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:57 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/29 23:23:23 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Initializes memory for the game's modules */
int	data_init(t_game *game)
{
	header_log("Initialization", "Data", B_ORANGE);
	print_log(1, STR_MLX_CONNECT);
	//game->mlx = malloc(1);
	game->mlx = mlx_init();
	condition_log(game->mlx != NULL, STR_MLX_CONNECT_S, STR_MLX_CONNECT_F);
	return (game->mlx != NULL);
}

/* Clears allocations made for the game hub */
void	data_clear(t_game *game)
{
	header_log("Clear", "Data", B_YELLOW);
	free(game->mlx);
}

/*  */
void	safe_exit(t_game *game)
{
	render_clear(game);
	inst_clear(game);
	data_clear(game);
	map_clear(game);
}
