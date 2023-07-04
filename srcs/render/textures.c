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

// static void	render_wall(t_game *game, t_rayhit *hit, )
// {
// 	if (hit->face == FACE_EAST)
// 	{
// 		t_screen *tex;
// 		char *dst;
// 		double x;
// 		double step;

// 		x = hit->pos[Y] - (int)(hit->pos[Y]);
// 		tex = &game->mapdata->texture[EAST];
// 		step = (draw_end - draw_start) / tex->size[Y];
// 		for (int i = 0; i < tex->size[Y]; i++)
// 		{
// 			info.pos[X] = screen_x + game->pane[FULLSCREEN]->offset[X];
// 			info.pos[Y] = draw_start + (step * i);
// 			info.length = step + 1;
// 			dst = tex->addr + (i * tex->len + (int)(x * tex->size[X]) * (tex->bpp / 8));
// 			info.color = *(int *)dst;
// 			draw_column(game->pane[FULLSCREEN], &info);
// 		}
// 	}
// }

void	render_textures(t_game *game, t_rayhit *hit, int screen_x)
{
	double	wall_dist;
	double	wall_height;
	double	draw_start;
	double	draw_end;
	t_idraw	info;
	
	// if (hit->flag == -1)
		// return ;
	wall_dist = hit->distance;
	wall_height = (int) (game->pane[FULLSCREEN]->size[Y] / wall_dist);
	// wall_height = (int) (200 - wall_dist * 64);
	// if (wall_dist == 0)
		// wall_height = 20;
	draw_start = -wall_height / 2 + game->pane[FULLSCREEN]->size[Y] / 2;
	// if (draw_start < 0)
		// draw_start = 0;
	draw_end = wall_height / 2 + game->pane[FULLSCREEN]->size[Y] / 2;
	// if (draw_end >= game->pane[FULLSCREEN]->size[Y])
		// draw_end = game->pane[FULLSCREEN]->size[Y] - 1;
	info.pos[X] = screen_x + game->pane[FULLSCREEN]->offset[X];
	info.pos[Y] = draw_start;
	info.length = draw_end - draw_start;

	if (hit->face == EAST)
	{
		t_screen *tex;
		double x = hit->pos[Y] - (int)(hit->pos[Y]);
		tex = &game->mapdata->texture[EAST];
		double step = (draw_end - draw_start) / tex->size[Y];
		for (int i = 0; i < tex->size[Y]; i++)
		{
			info.pos[X] = screen_x + game->pane[FULLSCREEN]->offset[X];
			info.pos[Y] = draw_start + (step * i);
			info.length = step + 1;
			char *dst;
			dst = tex->addr + (i * tex->len + (int)(x * tex->size[X]) * (tex->bpp / 8));
			info.color = *(int *)dst;
			draw_column(game->pane[FULLSCREEN], &info);
		}
	}
	if (hit->face == WEST)
	{
		t_screen *tex;
		double x = hit->pos[Y] - (int)(hit->pos[Y]);
		tex = &game->mapdata->texture[WEST];
		double step = (draw_end - draw_start) / tex->size[Y];
		for (int i = 0; i < tex->size[Y]; i++)
		{
			info.pos[X] = screen_x + game->pane[FULLSCREEN]->offset[X];
			info.pos[Y] = draw_start + (step * i);
			info.length = step + 1;
			char *dst;
			dst = tex->addr + (i * tex->len + (int)(x * tex->size[X]) * (tex->bpp / 8));
			info.color = *(int *)dst;
			draw_column(game->pane[FULLSCREEN], &info);
		}
	}
	if (hit->face == NORTH)
	{
		t_screen *tex;
		double x = hit->pos[X] - (int)(hit->pos[X]);
		tex = &game->mapdata->texture[NORTH];
		double step = (draw_end - draw_start) / tex->size[Y];
		for (int i = 0; i < tex->size[Y]; i++)
		{
			info.pos[X] = screen_x + game->pane[FULLSCREEN]->offset[X];
			info.pos[Y] = draw_start + (step * i);
			info.length = step + 1;
			char *dst;
			dst = tex->addr + (i * tex->len + (int)(x * tex->size[X]) * (tex->bpp / 8));
			info.color = *(int *)dst;
			draw_column(game->pane[FULLSCREEN], &info);
		}
	}
	if (hit->face == SOUTH)
	{
		t_screen *tex;
		double x = hit->pos[X] - (int)(hit->pos[X]);
		tex = &game->mapdata->texture[SOUTH];
		double step = (draw_end - draw_start) / tex->size[Y];
		for (int i = 0; i < tex->size[Y]; i++)
		{
			info.pos[X] = screen_x + game->pane[FULLSCREEN]->offset[X];
			info.pos[Y] = draw_start + (step * i);
			info.length = step + 1;
			char *dst;
			dst = tex->addr + (i * tex->len + (int)(x * tex->size[X]) * (tex->bpp / 8));
			info.color = *(int *)dst;
			draw_column(game->pane[FULLSCREEN], &info);
		}
	}
}
