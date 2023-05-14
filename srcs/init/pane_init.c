/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pane_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:08:50 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/09 15:08:50 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	pane_fill(t_game *game, t_pane **pane);

/* 
 * Initializes panes in the screen. Panes are mathematical subdivisions made to
 * the screen to help us to easily display what we want where it needs to be.
 */
int	pane_init(t_game *game)
{
	char	validation;

	header_log("Initialization", "Panes", B_ORANGE);
	print_log(1, STR_SET_PANE);
	game->pane = (t_pane **)malloc(sizeof(t_pane *) * (PANE_AMOUNT + 1));
	if (!game->pane)
		return (assert_log(0, STR_SET_PANE_S, STR_SET_PANE_F));
	game->pane[PANE_AMOUNT] = NULL;
	validation = pane_fill(game, game->pane);
	return (assert_log(game->pane && validation,
			STR_SET_PANE_S, STR_SET_PANE_F));
}

// vector2(100, 140, &offset[X], &offset[Y]);
// pane_setdata(pane[MINIMAP], size, offset);
static int	pane_fill(t_game *game, t_pane **pane)
{
	int	size[2];
	int	offset[2];

	vector2(256, 192, &size[X], &size[Y]);
	pane[MINIMAP] = create_pane(game, "minimap");
	pane_setdata_ratio(pane[MINIMAP], size, 50, 50);
	vector2(0, 0, &offset[X], &offset[Y]);
	pane[MAZE3D] = create_pane(game, "maze");
	pane_setdata(pane[MAZE3D], game->screen->size, offset);
	return (pane[MINIMAP] && pane[MAZE3D]);
}

void	pane_clear(t_game *game)
{
	header_log("Clear", "Panes", B_YELLOW);
	ft_free_arr((void **)game->pane);
}
