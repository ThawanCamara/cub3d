/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:55:41 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/03 16:55:41 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	keyboard_onpress(int key, t_game *game)
{
	// ft_printf("Keyboard key %s(%d) was pressed\n", get_key_name(key), key);
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		cmd_chdir_four(game, key, TRUE);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		cmd_chrot(game, key, TRUE);
	if (game->enable_parallax && (key == KEY_UP || key == KEY_DOWN))
		cmd_chdir_four(game, key, TRUE);
	if (game->enable_parallax && (key == KEY_LEFT || key == KEY_RIGHT))
		cmd_chrot(game, key, TRUE);
	return (0);
}

int	keyboard_onrelease(int key, t_game *game)
{
	// ft_printf("Keyboard key %s(%d) was released\n", get_key_name(key), key);
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		cmd_chdir_four(game, key, FALSE);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		cmd_chrot(game, key, FALSE);
	if (game->enable_parallax && (key == KEY_UP || key == KEY_DOWN))
		cmd_chdir_four(game, key, FALSE);
	if (game->enable_parallax && (key == KEY_LEFT || key == KEY_RIGHT))
		cmd_chrot(game, key, FALSE);
	if (key == KEY_ESC)
		clear_handler(game, FUNC_TABLE_SIZE - 1);
	return (0);
}
