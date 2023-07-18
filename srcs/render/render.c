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

void	render_player(t_game *game, t_rayhit *hit)
{
	int	color;
	int	i;

	color = 0x0000ffff;
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		if (i < 400)
			debug_ray(game, &hit[i], 0x00ff0000);
		else
			debug_ray(game, &hit[i], color);
	}
}

int	render_game(t_game *game)
{
	t_rayhit	hit[SCREEN_WIDTH];

	render_skyfloor(game);
	render_fov(game, hit);
	if (game->show_minimap)
	{
		render_minimap(game, game->mapdata->map);
		render_player(game, hit);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
	return (0);
}
