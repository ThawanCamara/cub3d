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

static int	pane_fill(t_game *game, t_screen *screen, t_pane **pane);

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
	validation = pane_fill(game, game->screen, game->pane);
	return (assert_log(game->pane && validation,
			STR_SET_PANE_S, STR_SET_PANE_F));
}

// vector2(100, 140, &offset[X], &offset[Y]);
// pane_setdata(pane[MINIMAP], size, offset);
static int	pane_fill(t_game *game, t_screen *screen, t_pane **pane)
{
	int	size[2];
	int	offset[2];

	// vector2(256, 192, &size[X], &size[Y]);
	vector2(300, 200, &size[X], &size[Y]);
	pane[MINIMAP] = create_pane(game, "minimap");
	pane_setdata_ratio(pane[MINIMAP], size, 0, 0);
	// pane_setdata(pane[MINIMAP], size, offset);

	vector2(0, 0, &offset[X], &offset[Y]);

	pane[FULLSCREEN] = create_pane(game, "screen");
	pane_setdata(pane[FULLSCREEN], screen->size, offset);

	vector2(screen->size[X], screen->size[Y] / 2, &size[X], &size[Y]);
	pane[TOPHALF] = create_pane(game, "sc_tophalf");
	pane_setdata_ratio(pane[TOPHALF], size, 0, 0);
	pane[BOTHALF] = create_pane(game, "sc_bothalf");
	pane_setdata_ratio(pane[BOTHALF], size, 0, 50);
	
	vector2(screen->size[X] / 2, screen->size[Y], &size[X], &size[Y]);
	pane[LWING] = create_pane(game, "sc_lwing");
	pane_setdata_ratio(pane[LWING], size, 0, 0);
	pane[RWING] = create_pane(game, "sc_rwing");
	pane_setdata_ratio(pane[RWING], size, 50, 0);
	return (pane[MINIMAP] && pane[FULLSCREEN] && pane[TOPHALF]
			&& pane[BOTHALF] && pane[LWING] && pane[RWING]);
}

void	pane_clear(t_game *game)
{
	header_log("Clear", "Panes", B_YELLOW);
	ft_free_arr((void **)game->pane);
}
