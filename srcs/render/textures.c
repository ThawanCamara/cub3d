#include "game.h"

void	render_textures(t_game *game, t_rayhit *hit, int screen_x)
{
	double	wall_dist;
	double	wall_height;
	double	draw_start;
	double	draw_end;
	t_idraw	info;
	
	// if (hit->flag == -1)
		// return ;
	wall_dist = hit->distance/*  * cos(fabs(game->inst[0].obj->rotation * game->degtorad - hit->rad))*/; 
	wall_height = (int) (game->pane[FULLSCREEN]->size[Y] / wall_dist);
	draw_start = -wall_height / 2 + game->pane[FULLSCREEN]->size[Y] / 2;
	// if (draw_start < 0)
		// draw_start = 0;
	draw_end = wall_height / 2 + game->pane[FULLSCREEN]->size[Y] / 2;
	// if (draw_end >= game->pane[FULLSCREEN]->size[Y])
		// draw_end = game->pane[FULLSCREEN]->size[Y] - 1;

	info.pos[X] = screen_x + game->pane[FULLSCREEN]->offset[X];
	info.pos[Y] = draw_start;
	info.length = draw_end - draw_start;

	if (hit->face == FACE_EAST)
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
	if (hit->face == FACE_WEST)
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
	if (hit->face == FACE_NORTH)
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
	if (hit->face == FACE_SOUTH)
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


	// esquerda
	// if (hit->face == 0)
	// 	info.color = 0x00FF0000;
	// direita
	// if (hit->face == 2)
		// info.color = 0x0000FF00;
	// cima
	// if (hit->face == 4)
	// 	info.color = 0x00FF00FF;
	// baixo
	// if (hit->face == 6)
	// 	info.color = 0x000000FF;

	(void)info;
	// draw_column(game->pane[FULLSCREEN], &info);
}
