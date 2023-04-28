/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:55 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/28 08:06:49 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	render_init(t_game *game)
{
	t_render	*r;

	printf("%sInitialization:%s %sRender%s\n", B_GREEN, RESET, B_SILVER, RESET);
	r = game->render;
	r->screen_width = SCREEN_WIDTH;
	r->screen_height = SCREEN_HEIGHT;
	r->mlx = mlx_init();
	r->win = mlx_new_window(r->mlx, r->screen_width, r->screen_height,
			TITLE);
	r->nwin = mlx_new_window(r->mlx, r->screen_width, r->screen_height,
			TITLE);
	return (r->mlx && r->win);
}

void	render_clear(t_game *game)
{
	printf("%sClear:%s %sRender%s\n", B_YELLOW, RESET, B_SILVER, RESET);
	free(game->render->mlx);
	free(game->render->win);
}
