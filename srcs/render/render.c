/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:26:29 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/10 19:26:29 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	render_game(t_game *game)
{
	render_minimap(game);
	render_fov(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
	return(0);
}
