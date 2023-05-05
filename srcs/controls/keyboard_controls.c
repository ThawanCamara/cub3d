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
	(void)game;
	(void)key;
	ft_printf("Keyboard key %s(%d) was pressed\n", get_key_name(key), key);
	return (0);
}

int	keyboard_onrelease(int key, t_game *game)
{
	(void)game;
	(void)key;
	ft_printf("Keyboard key %s(%d) was released\n", get_key_name(key), key);
	if (key == KEY_ESC)
		clear_handler(game, FUNC_TABLE_SIZE - 1);
	return (0);
}
