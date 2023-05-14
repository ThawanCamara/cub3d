/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:59:25 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/10 15:59:25 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* 
 * Initializes the game's UI elements. For now we only need the minimap.
 * Minimap scale differs from Pane's scale. The former is used to ensure that
 * the minimap will always fit it's associated pane area. The latter is meant
 * to make possible that a given image or shape of size AxB
 */
int	ui_init(t_game *game)
{
	header_log("Initialization", "UI", B_ORANGE);
	print_log(1, STR_SET_UI);
	game->ui = (t_ui *)malloc(sizeof(t_ui));
	game->ui->minimap_scale = get_minimap_scale(game, game->pane[MINIMAP]);
	game->ui->minimap_box_size = BOX_SIZE * game->ui->minimap_scale;
	return (assert_log(game->ui != NULL,
			STR_SET_UI_S, STR_SET_UI_F));
}

void	ui_clear(t_game *game)
{
	header_log("Clear", "UI", B_YELLOW);
	free(game->ui);
}
