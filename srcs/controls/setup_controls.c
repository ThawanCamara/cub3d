/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:11:29 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/03 17:11:29 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	setup_controls(t_game *game)
{
	mlx_hook(game->win, EVENT_KEY_PRESS, MASK_KEY_PRESS, keyboard_onpress, game);
	mlx_hook(game->win, EVENT_KEY_RELEASE, MASK_KEY_RELEASE, keyboard_onrelease, game);
	mlx_hook(game->win, EVENT_MOUSE_PRESS, MASK_MOUSE_PRESS, mouse_onpress, game);
	mlx_hook(game->win, EVENT_MOUSE_RELEASE, MASK_MOUSE_RELEASE, mouse_onrelease, game);
	mlx_hook(game->win, EVENT_MOUSE_MOTION, MASK_MOUSE_MOTION, mouse_move, game);
	mlx_hook(game->win, EVENT_EXPOSE, MASK_EXPOSURE, window_onresize, game);
	mlx_hook(game->win, EVENT_CLOSE, MASK_STRUCTNOTIFY, window_onclose, game);
}
