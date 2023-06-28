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
	render_skyfloor(game);
	render_minimap(game);
	render_fov(game);
	
	t_iray		iray;
	t_rayhit	hit;


	// t_idraw info;

	// iray.rad = (game->inst[0].obj->rotation) * game->degtorad;
	iray.dir[X] = game->inst[0].obj->dir[X];
	iray.dir[Y] = -game->inst[0].obj->dir[Y];
	iray.start[X] = game->inst[0].obj->pos[X];
	iray.start[Y] = game->inst[0].obj->pos[Y];
	iray.max_len = 100;
	ray2(game, &iray, &hit);
	int color;
		color = 0x000000ff;
	debug_ray(game, &hit, color);
	for (int i = 0; i < 4; i++)
	{
		// iray.rad = ((game->inst[0].obj->rotation) + (360/4) * i) * game->degtorad;
		iray.dir[X] = cos((game->inst[0].obj->rotation + 90 * i) * game->degtorad);
		iray.dir[Y] = -sin((game->inst[0].obj->rotation + 90 * i) * game->degtorad);
		iray.start[X] = game->inst[0].obj->pos[X];
		iray.start[Y] = game->inst[0].obj->pos[Y];
		iray.max_len = 2;
		ray2(game, &iray, &hit);
		if (hit.flag == 1)
			color = 0x00ff0000;
		else
			color = 0x0000ff00;
		debug_ray(game, &hit, color);
	}

	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
	return (0);
}
