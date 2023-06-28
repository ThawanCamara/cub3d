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

double fix_ang(double a)
{
	if(a > 359)
		a-=360;
	 if(a < 0)
		a+=360;
	 return a;
}

static void	cast_rays(t_game *game, double *raydir, int screen_x)
{
	t_iray		iray;
	t_rayhit	hit;
	int color;

	(void)screen_x;
	iray.dir[X] = raydir[X];
	iray.dir[Y] = -raydir[Y];
	// iray.rad = 
	iray.start[X] = game->inst[0].obj->pos[X];
	iray.start[Y] = game->inst[0].obj->pos[Y];
	// iray.max_len = 0;
	iray.max_len = 0;
	ray2(game, &iray, &hit);
	color = 0x0000ffff;
	debug_ray(game, &hit, color);
	// printf("%f,%f\n", hit.pos[X], hit.pos[Y]);
	// if (hit.flag != -1)
		render_textures(game, &hit, screen_x);
}

// static void	cast_rays(t_game *game, double angle, int screen_x)
// {
// 	t_iray		iray;
// 	t_rayhit	hit;
// 	int color;

// 	(void)screen_x;
// 	(void)angle;
// 	iray.rad = angle * game->degtorad;
// 	iray.start[X] = game->inst[0].obj->pos[X];
// 	iray.start[Y] = game->inst[0].obj->pos[Y];
// 	iray.max_len = 100;
// 	ray2(game, &iray, &hit);
// 	color = 0x0000ffff;
// 	debug_ray(game, &hit, color);
// 	render_textures(game, &hit, screen_x, angle);
// }

// void	get_fov(t_game *game, t_inst *inst, t_pane *pane)
// {
// 	int			i;
// 	double		add;
// 	double		angle;

// 	(void)pane;
// 	i = 1 + inst->cam->fov_sc_half;
// 	add = inst->cam->fov_half - inst->cam->fov;
// 	while (--i > -inst->cam->fov_sc_half)
// 	{
// 		angle = fix_ang(inst->obj->rotation + add);

// 		cast_rays(game, angle, inst->cam->fov_sc_half + i - 1);
// 		// if (i == 400)
// 		// 	ray(game, inst, pane, angle * game->degtorad, inst->cam->fov_sc_half + i - 1, angle * view, 0x00440000);
// 		// else
// 		// 	ray(game, inst, pane, angle * game->degtorad, inst->cam->fov_sc_half + i - 1, angle * view, 0x00440000);
// 			// ray(game, inst, pane, angle, inst->cam->fov_sc_half + i - 1 + (inst->cam->fov_sc_half * 2 * (i == 1)), 0x00004400);
// 		add += inst->cam->fov_increment;
// 	}
// }
void	get_fov(t_game *game, t_inst *inst, t_pane *pane)
{
	int		i;
	double	camera_x;
	double	raydir[2];

	// i = pane->size[X];
	// // i = 0;
	// while (--i >= 0)
	// {
	// 	camera_x = 2 * i / (double)pane->size[X] - 1;
	// 	raydir[X] = inst->obj->dir[X] + inst->cam->plane[X] * camera_x;
	// 	raydir[Y] = inst->obj->dir[Y] + inst->cam->plane[Y] * camera_x;
	// 	cast_rays(game, raydir, i);
	// 	// if (camera_x < 0.002500 && camera_x > -0.002500)
	// }
	i = -1;
	// i = 0;
	while (++i < pane->size[X])
	{
		camera_x = -2 * i / (double)pane->size[X] + 1;
		raydir[X] = inst->obj->dir[X] + inst->cam->plane[X] * camera_x;
		raydir[Y] = inst->obj->dir[Y] + inst->cam->plane[Y] * camera_x;
		// if (camera_x < 0.002500 && camera_x > -0.002500)
			cast_rays(game, raydir, i);
	}
}

void	render_fov(t_game *game)
{
	int	i;
	t_pane		*pane;

	i = -1;
	(void) game;
	while (++i < game->total_insts)
	{		
		if (!game->enable_parallax)
			pane = game->pane[FULLSCREEN];
		else
			pane = game->pane[i + 4];
		get_fov(game, &game->inst[i], pane);

	}
}
