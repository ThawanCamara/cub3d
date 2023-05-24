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

void	get_fov(t_game *game, t_inst *inst, t_pane *pane)
{
	int			i;
	double		add;
	double		view;
	double		angle;

	i = 1 + inst->cam->fov_sc_half;
	add = inst->cam->fov_half - inst->cam->fov;
	view = 1;
	while (--i > -inst->cam->fov_sc_half)
	{
		angle = fix_ang(inst->obj->rotation + add);
		// ray(game, inst, pane, angle, inst->cam->fov_sc_half + i - 1, 0x00440000);
		if (i == 400)
			ray(game, inst, pane, angle * game->degtorad, inst->cam->fov_sc_half + i - 1, angle * view, 0x00440000);
		else
			ray(game, inst, pane, angle * game->degtorad, inst->cam->fov_sc_half + i - 1, angle * view, 0x00440000);
			// ray(game, inst, pane, angle, inst->cam->fov_sc_half + i - 1 + (inst->cam->fov_sc_half * 2 * (i == 1)), 0x00004400);
		add += inst->cam->fov_increment;
		// printf("%d) %f %f\n", i, view, inst->cam->view_increment);
		view -= inst->cam->view_increment;
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
