/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:57 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/28 05:43:15 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Initializes memory for the game's modules */
int	data_init(t_game *game)
{
	printf("%sInitialization:%s %sData%s\n", B_GREEN, RESET, B_SILVER, RESET);
	game->render = (t_render *)malloc(sizeof(t_render));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->cam = (t_cam *)malloc(sizeof(t_cam));
	return (game->render && game->map && game->cam);
}

/* Clears allocations made for the game hub */
void	data_clear(t_game *game)
{
	printf("%sClear:%s %sData%s\n", B_YELLOW, RESET, B_SILVER, RESET);
	free(game->render);
	free(game->map);
	free(game->cam);
}

/*  */
void	safe_exit(t_game *game)
{
	render_clear(game);
	data_clear(game);
}

// void	init_handler(t_game *game,
// 	int (*ini)(t_game *), void (*clr)(t_game *))
// {
// 	const void **table = {
// 		data_init, data_clear,
// 		render_init, render_clear
// 	}
// 	while ()
// 	{	
// 	}
// 	if (!ini(game))
// 	{
// 		clr(game);
// 		exit(1);
// 	}
// }
