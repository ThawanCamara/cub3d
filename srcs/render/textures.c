/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:24:08 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/03 18:24:08 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_wall(t_game *game, t_wall *wall, t_idraw *info, int face)
{
	int			i;
	double		x;
	double		step;
	char		*dst;
	t_screen	*tex;

	i = -1;
	if (face == EAST || face == WEST)
		x = wall->hit->pos[Y] - (int)(wall->hit->pos[Y]);
	else
		x = wall->hit->pos[X] - (int)(wall->hit->pos[X]);
	tex = &game->mapdata->texture[face];
	step = (wall->end - wall->start) / tex->size[Y];
	while (++i < tex->size[Y])
	{
		info->pos[X] = wall->screen_x + game->pane[FULLSCREEN]->offset[X];
		info->pos[Y] = wall->start + (step * i);
		info->length = step + 1;
		dst = tex->addr + (i * tex->len + (int)(x * tex->size[X])
				* (tex->bpp / 8));
		info->color = *(int *)dst;
		draw_column(game->pane[FULLSCREEN], info);
	}
}

void	render_textures(t_game *game, t_rayhit *hit, int screen_x)
{
	t_wall	wall;
	t_idraw	info;

	wall.screen_x = screen_x;
	wall.dist = hit->distance;
	wall.height = (int)(game->pane[FULLSCREEN]->size[Y] / wall.dist);
	wall.start = -wall.height / 2 + game->pane[FULLSCREEN]->size[Y] / 2;
	wall.end = wall.height / 2 + game->pane[FULLSCREEN]->size[Y] / 2;
	wall.hit = hit;
	info.pos[X] = screen_x + game->pane[FULLSCREEN]->offset[X];
	info.pos[Y] = wall.start;
	info.length = wall.end - wall.start;
	render_wall(game, &wall, &info, hit->face);
}
