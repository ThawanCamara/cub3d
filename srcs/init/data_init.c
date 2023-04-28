/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:57 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/28 08:05:43 by tde-souz         ###   ########.fr       */
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
