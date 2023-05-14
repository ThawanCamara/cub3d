/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:37:59 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/09 14:37:59 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* 
 * Initialize screen data and mlx image. The whole screen is a single mlx image
 * and screen size will scale according with the amount of players. Currently
 * we are aiming to support only two players.
 */
int	screen_init(t_game *game)
{
	t_screen	*sc;

	header_log("Initialization", "Screen", B_ORANGE);
	print_log(1, STR_SET_SCREEN);
	game->screen = (t_screen *)malloc(sizeof(t_screen));
	if (!game->screen)
		return (assert_log(0, STR_SET_SCREEN_S, STR_SET_SCREEN_F));
	sc = game->screen;
	sc->size[X] = SCREEN_WIDTH * game->total_insts;
	sc->size[Y] = SCREEN_HEIGHT;
	sc->img = mlx_new_image(game->mlx, sc->size[X], sc->size[Y]);
	sc->addr = mlx_get_data_addr(sc->img, &sc->bpp, &sc->len, &sc->endian);
	return (assert_log(game->screen && game->screen->img,
			STR_SET_SCREEN_S, STR_SET_SCREEN_F));
}

/* Clear mlx image and the image data struct */
void	screen_clear(t_game *game)
{
	header_log("Clear", "Screen", B_YELLOW);
	mlx_destroy_image(game->mlx, game->screen->img);
	free(game->screen);
}
