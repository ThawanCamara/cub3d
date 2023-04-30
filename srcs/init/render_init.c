/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:55 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/29 23:23:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	render_init(t_game *game)
{
	char 	validation;
	short	i;
	t_render	*r;
	
	header_log("Initialization", "Render", B_ORANGE);
	print_log(1, STR_SET_RENDER);
	i = -1;
	validation = 1;
	while (++i < game->total_insts)
	{
		r = &game->inst->render[i];
		r->screen_width = SCREEN_WIDTH;
		r->screen_height = SCREEN_HEIGHT;
		//r->win = malloc(1);
		r->win = mlx_new_window(game->mlx, r->screen_width, r->screen_height,
			TITLE);
		validation *= r->win != NULL;
	}
	condition_log(validation, STR_SET_RENDER_S, STR_SET_RENDER_F);
	return (validation);
}

void	render_clear(t_game *game)
{
	short	i;
	t_render	*r;
	
	header_log("Clear", "Render", B_YELLOW);
	r = game->inst->render;
	i = -1;
	while (++i < game->total_insts)
	{
		r = &game->inst->render[i];
		free(r->win);
		//mlx_destroy_window(game->mlx, r->win);
	}
}
