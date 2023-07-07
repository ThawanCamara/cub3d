/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:26:15 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/10 19:26:15 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

double	fix_ang(double a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

static void	cast_rays(t_game *game, t_rayhit *hit, double *raydir, int screen_x)
{
	t_iray		iray;

	iray.dir[X] = raydir[X];
	iray.dir[Y] = -raydir[Y];
	iray.start[X] = game->inst[0].obj->pos[X];
	iray.start[Y] = game->inst[0].obj->pos[Y];
	iray.max_len = 0;
	ray2(game, &iray, &hit[screen_x]);
	render_textures(game, &hit[screen_x], screen_x);
}

// if (camera_x < 0.002500 && camera_x > -0.002500)
// if (camera_x < 0.003500 && camera_x > -0.003500)

void	get_fov(t_game *game, t_rayhit *hit, t_inst *inst, t_pane *pane)
{
	int		i;
	double	camera_x;
	double	raydir[2];

	i = -1;
	while (++i < pane->size[X])
	{
		camera_x = -2 * i / (double)pane->size[X] + 1;
		raydir[X] = inst->obj->dir[X] + inst->cam->plane[X] * camera_x;
		raydir[Y] = inst->obj->dir[Y] + inst->cam->plane[Y] * camera_x;
		cast_rays(game, hit, raydir, i);
	}
}

void	render_fov(t_game *game, t_rayhit *hit)
{
	int			i;
	t_pane		*pane;

	i = -1;
	(void) game;
	while (++i < game->total_insts)
	{		
		if (!game->enable_parallax)
			pane = game->pane[FULLSCREEN];
		else
			pane = game->pane[i + 4];
		get_fov(game, hit, &game->inst[i], pane);
	}
}
