/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:55:50 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/03 16:55:50 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	mouse_onpress(int key, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (game->allow_zoom)
	{
		if (key == KEY_SCR_DOWN && game->zoom > 0.20)
			game->zoom -= 0.15;
		if (key == KEY_SCR_UP && game->zoom < 5)
			game->zoom += 0.15;
		printf("Zoom = %f\n", game->zoom);
	}
	return (0);
}

int	mouse_onrelease(int key, int x, int y, t_game *game)
{
	(void)game;
	(void)key;
	(void)x;
	(void)y;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	return (0);
}
