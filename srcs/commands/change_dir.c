/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:20 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 14:03:20 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Mandatory */
void	cmd_chdir_two(t_game *game, int key, char pressed)
{
	if (key == KEY_W)
		game->inst[0].cam->axis[TOP] = pressed;
	if (key == KEY_S)
		game->inst[0].cam->axis[BOT] = pressed;
	if (game->enable_parallax)
	{
		if (key == KEY_UP)
			game->inst[1].cam->axis[TOP] = pressed;
		if (key == KEY_DOWN)
			game->inst[1].cam->axis[BOT] = pressed;
	}
}

/* Meant to be used if we are going for mouse angle control bonus */
void	cmd_chdir_four(t_game *game, int key, char pressed)
{
	if (key == KEY_W)
		game->inst[0].cam->axis[TOP] = pressed;
	if (key == KEY_S)
		game->inst[0].cam->axis[BOT] = pressed;
	if (key == KEY_D)
		game->inst[0].cam->axis[RIGHT] = pressed;
	if (key == KEY_A)
		game->inst[0].cam->axis[LEFT] = pressed;
}
