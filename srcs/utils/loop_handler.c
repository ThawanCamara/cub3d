/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:45:18 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/18 22:53:03 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	loop_handler(t_game *game)
{
	player_move_rot(game, &game->inst[0]);
	if (game->enable_parallax)
		player_move_rot(game, &game->inst[1]);
	render_game(game);
	return (0);
}
