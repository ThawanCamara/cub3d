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
	(void)game;
	(void)key;
	(void)x;
	(void)y;
	if (key == KEY_SCR_DOWN && game->zoom > 0.20)
		game->zoom -= 0.15;
	if (key == KEY_SCR_UP && game->zoom)
		game->zoom += 0.15;
	printf("Zoom = %f\n", game->zoom);
	ft_printf("Mouse key %s was pressed at [%d,%d]\n", get_key_name(key), x, y);

	return (0);
}

int	mouse_onrelease(int key, int x, int y, t_game *game)
{
	(void)game;
	(void)key;
	(void)x;
	(void)y;
	ft_printf("Mouse key %s was released at [%d,%d]\n", get_key_name(key), x, y);
	return (0);
}

// ft_printf("Mouse moved. Current position is [%d,%d]\n", x, y);
int	mouse_move(int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	//last_x;
	//int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
	//cmd_chrot(game, KEY_RIGHT, TRUE);
	return (0);
}
