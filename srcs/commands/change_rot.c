/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:27:45 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 14:27:45 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Mandatory */
void	cmd_chrot(t_game *game, int key, char pressed)
{
	if (key == KEY_RIGHT)
		game->inst[0].cam->orientation[STARBOARD] = pressed;
	if (key == KEY_LEFT)
		game->inst[0].cam->orientation[PORT] = pressed;
	// if (game->enable_parallax)
	// {
	// 	if (key == KEY_RIGHT)
	// 		game->inst[1].cam->orientation[STARBOARD] = pressed;
	// 	if (key == KEY_LEFT)
	// 		game->inst[1].cam->orientation[PORT] = pressed;
	// }
}
