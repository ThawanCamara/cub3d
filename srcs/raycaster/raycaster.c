/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:36:42 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/14 16:36:42 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// int fix_ang(int a)
// {
// 	if(a > 359)
// 		a-=360;
// 	 if(a < 0)
// 		a+=360;
// 	 return a;
// }

double vectorAngle(double *v) {
    double angle = atan2(v[Y], v[X]);
    if (angle < 0) {
        angle += 2 * M_PI;  // Convert negative angle to positive
    }
    return angle * 180/M_PI;
}

// printf("%f\n", atan2(info.dir[X], info.dir[Y]) * (180/M_PI));

static void	sidestep(t_inst *inst, t_ray *ray)
{
	if (ray->rayDir[X] < 0)
	{
		ray->step[X] = -1;
		ray->sideDist[X] = (inst->obj->pos[X] - ray->map[X]) * ray->deltaDist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->sideDist[X] = (ray->map[X] + 1.0 - inst->obj->pos[X]) * ray->deltaDist[X];
	}
	if (ray->rayDir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->sideDist[Y] = (inst->obj->pos[Y] - ray->map[Y]) * ray->deltaDist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->sideDist[Y] = (ray->map[Y] + 1.0 - inst->obj->pos[Y]) * ray->deltaDist[Y];
	}

	// ray->step[X] = (2 * -(ray->rayDir[X] < 0) + 1);
	// if (ray->step[X] == -1)
	// 	ray->sideDist[X] = (inst->obj->pos[X] - ray->map[X]) * ray->deltaDist[X];
	// else
	// 	ray->sideDist[X] = (ray->map[X] + 1.0 - inst->obj->pos[X]) * ray->deltaDist[X];
	// ray->step[Y] = (2 * -(ray->rayDir[Y] < 0) + 1);
	// if (ray->step[Y] < -1)
	// 	ray->sideDist[Y] = (inst->obj->pos[Y] - ray->map[Y]) * ray->deltaDist[Y];
	// else
	// 	ray->sideDist[Y] = (ray->map[Y] + 1.0 - inst->obj->pos[Y]) * ray->deltaDist[Y];
}

t_rayhit	*ray(t_game *game, t_inst *inst, t_pane *pane, double camera_x, int w)
{
	t_ray	ray;

	// ray.rayDir[X] = inst->obj->dir[X] + inst->cam->plane[X] * camera_x;
	// ray.rayDir[Y] = inst->obj->dir[Y] + inst->cam->plane[Y] * camera_x;
	ray.rayDir[X] = cos(-camera_x);
	ray.rayDir[Y] = sin(-camera_x);

	ray.deltaDist[X] = (fabs(ray.rayDir[X]) < 1e-9) ? game->mapdata->size[X] : fabs(1 / ray.rayDir[X]);
	ray.deltaDist[Y] = (fabs(ray.rayDir[Y]) < 1e-9) ? game->mapdata->size[Y] : fabs(1 / ray.rayDir[Y]);
	// ray.deltaDist[X] = fabs(1 / ray.rayDir[X]);
	// ray.deltaDist[Y] = fabs(1 / ray.rayDir[Y]);

	// if (ray.deltaDist[X] > game->mapdata->size[X] - inst->obj->pos[X])
		// ray.deltaDist[X] = game->mapdata->size[X] - inst->obj->pos[X];
	// if (ray.deltaDist[Y] > game->mapdata->size[Y] - inst->obj->pos[Y])
		// ray.deltaDist[Y] = game->mapdata->size[Y] - inst->obj->pos[Y];

	ray.map[X] = (int)inst->obj->pos[X];
	ray.map[Y] = (int)inst->obj->pos[Y];

	// printf("========\n");
	// printf("angle : %f - %f\n", inst->obj->rotation, angle);
	// printf("dir    : (%.2f, %.2f)\n", inst->obj->dir[X], inst->obj->dir[Y]);
	// printf("raydir : (%.2f, %.2f)\n", ray.rayDir[X], ray.rayDir[Y]);
	// printf("plane  : (%.2f, %.2f)\n", inst->cam->plane[X], inst->cam->plane[Y]);
	// printf("\e[1;1H\e[2J");


	// printf("dir X : %f\n", inst->obj->dir[X]);
	// printf("dir Y : %f\n", inst->obj->dir[Y]);
	// printf("%f\n", inst->cam->plane[Y]);
	// printf("raydir X : %f\n", ray.rayDir[X]);
	// printf("raydir Y : %f\n", ray.rayDir[Y]);
	// printf("raydelta X : %f\n", ray.deltaDist[X]);
	// printf("raydelta Y : %f\n", ray.deltaDist[Y]);
	// printf("map X : %d\n", ray.map[X]);
	// printf("map Y : %d\n", ray.map[Y]);
	ray.hit_flag = 0;

	sidestep(inst, &ray);

	while (ray.hit_flag == 0)
	{
		if (ray.sideDist[X] < ray.sideDist[Y])
		{
			ray.sideDist[X] += ray.deltaDist[X];
			ray.map[X] += ray.step[X];
			ray.side = 0;
			
			ray.hit.distance = ray.sideDist[X];
		}
		else
		{
			ray.sideDist[Y] += ray.deltaDist[Y];
			ray.map[Y] += ray.step[Y];
			ray.side = 1;
			
			ray.hit.distance = ray.sideDist[Y];
		}
		if (game->mapdata->map[ray.map[Y]][ray.map[X]] == '1')
			ray.hit_flag = 1;
	}

	/* Red Square */
	int pos[2];
	int size[2];
	vector2(game->ui->minimap_box_size, game->ui->minimap_box_size, &size[X], &size[Y]);
	vector2(ray.map[X] * game->ui->minimap_box_size, ray.map[Y] * game->ui->minimap_box_size, &pos[X], &pos[Y]);
	if (ray.sideDist[X] < ray.sideDist[Y])
		draw_rect(game->screen, size, pos, 0x00FF0000);
	else
		draw_rect(game->screen, size, pos, 0x0000FF00);
	/*  */


	t_info info;
	if (ray.sideDist[X] < ray.sideDist[Y])
	{
		/* Red Line */
		info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[X];
		info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[Y];
		info.length = ray.sideDist[X] * game->ui->minimap_box_size;
		info.color = 0x00ff0000;
		info.dir[X] = ray.rayDir[X];
		info.dir[Y] = ray.rayDir[Y];
		draw_line_dir(game->pane[MINIMAP], &info);
		/*  */
	}
	else
	{
		/* Green Line */
		info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[X];
		info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[Y];
		info.length = ray.sideDist[Y] * game->ui->minimap_box_size;
		info.color = 0x0000ff00;
		info.dir[X] = ray.rayDir[X];
		info.dir[Y] = ray.rayDir[Y];
		draw_line_dir(game->pane[MINIMAP], &info);
	}

	/*  */

	// if (ray.side == 0)
	// 	ray.perp_wall_dist = ray.sideDist[X] - ray.deltaDist[X];
	// else
	// 	ray.perp_wall_dist = ray.sideDist[Y] - ray.deltaDist[Y];
	// printf("%f\n", camera_x * (180/M_PI));
	if (ray.side == 0)
		ray.perp_wall_dist = (ray.sideDist[X] - ray.deltaDist[X]) * sin(-camera_x);
	else
		ray.perp_wall_dist = (ray.sideDist[Y] - ray.deltaDist[Y]) * sin(-camera_x);
	// printf("perp(%d): %f\n", pane->size[X] - w, ray.perp_wall_dist);
	ray.line_height = (int) (pane->size[Y] / ray.perp_wall_dist);
	ray.draw_start = -ray.line_height / 2 + pane->size[Y] / 2;
	if (ray.draw_start < 0)
		ray.draw_start = 0;
	ray.draw_end = ray.line_height / 2 + pane->size[Y] / 2;
	if (ray.draw_end >= pane->size[Y])
		ray.draw_end = pane->size[Y] - 1;
	
	// int ca;
	// ca = fix_ang(inst->obj->rotation - vectorAngle(ray.rayDir));
	// ray.perp_wall_dist = ray.perp_wall_dist * cos(ca * game->degtorad);
	

	(void)w;

	/* Red Wall */
	info.pos[X] = w;
	info.pos[Y] = ray.draw_start;
	info.length = ray.draw_end - ray.draw_start;
	// printf("fov_half : %d\n", inst->cam->fov_half);
	// printf("PaneY : %d\n", pane->size[Y]);
	// printf("start : %d | end : %d\n", ray.draw_start, ray.draw_end);
	// printf("height : %d\n", ray.line_height);
	// printf("perpwall : %f\n", ray.perp_wall_dist);
	info.color = 0x00641364;
	info.radians = 270 * game->degtorad;
	draw_line_r(game->pane[FULLSCREEN], &info);
	/*  */
	return (NULL);
}	
// t_rayhit	*ray(t_game *game, t_inst *inst, t_pane *pane, double cameraX)
// {
// 	t_ray	ray;

// 	ray.rayDir[X] = -inst->obj->dir[X] + inst->cam->plane[Y] * cameraX;
// 	ray.rayDir[Y] = -inst->obj->dir[Y] + inst->cam->plane[X] * cameraX;

// 	// printf("%f\n", /* vectorAngle(t) -  */vectorAngle(o));

// 	ray.deltaDist[X] = (fabs(ray.rayDir[X]) < 1e-9) ? game->mapdata->size[X] : fabs(1 / ray.rayDir[X]);
// 	ray.deltaDist[Y] = (fabs(ray.rayDir[Y]) < 1e-9) ? game->mapdata->size[Y] : fabs(1 / ray.rayDir[Y]);
// 	// ray.deltaDist[X] = fabs(1 / ray.rayDir[X]);
// 	// ray.deltaDist[Y] = fabs(1 / ray.rayDir[Y]);

// 	// if (ray.deltaDist[X] > game->mapdata->size[X] - inst->obj->pos[X])
// 		// ray.deltaDist[X] = game->mapdata->size[X] - inst->obj->pos[X];
// 	// if (ray.deltaDist[Y] > game->mapdata->size[Y] - inst->obj->pos[Y])
// 		// ray.deltaDist[Y] = game->mapdata->size[Y] - inst->obj->pos[Y];

// 	ray.map[X] = (int)inst->obj->pos[X];
// 	ray.map[Y] = (int)inst->obj->pos[Y];

// 	// printf("========\n");
// 	// printf("angle : %f\n", inst->obj->rotation);
// 	// printf("dir X : %f\n", inst->obj->dir[X]);
// 	// printf("dir Y : %f\n", inst->obj->dir[Y]);
// 	// printf("%f\n", inst->cam->plane[Y]);
// 	// printf("raydir X : %f\n", ray.rayDir[X]);
// 	// printf("raydir Y : %f\n", ray.rayDir[Y]);
// 	// printf("raydelta X : %f\n", ray.deltaDist[X]);
// 	// printf("raydelta Y : %f\n", ray.deltaDist[Y]);
// 	// printf("map X : %d\n", ray.map[X]);
// 	// printf("map Y : %d\n", ray.map[Y]);
// 	ray.hit_flag = 0;

// 	sidestep(inst, &ray);

// 	while (ray.hit_flag == 0)
// 	{
// 		if (ray.sideDist[X] < ray.sideDist[Y])
// 		{
// 			ray.sideDist[X] += ray.deltaDist[X];
// 			ray.map[X] += ray.step[X];
// 			ray.side = 0;
			
// 			ray.hit.distance = ray.sideDist[X];
// 		}
// 		else
// 		{
// 			ray.sideDist[Y] += ray.deltaDist[Y];
// 			ray.map[Y] += ray.step[Y];
// 			ray.side = 1;
			
// 			ray.hit.distance = ray.sideDist[Y];
// 		}
// 		if (game->mapdata->map[ray.map[Y]][ray.map[X]] == '1')
// 			ray.hit_flag = 1;
// 	}

// 	/* Red Square */
// 	int pos[2];
// 	int size[2];
// 	vector2(game->ui->minimap_box_size, game->ui->minimap_box_size, &size[X], &size[Y]);
// 	vector2(ray.map[X] * game->ui->minimap_box_size, ray.map[Y] * game->ui->minimap_box_size, &pos[X], &pos[Y]);
// 	if (ray.sideDist[X] < ray.sideDist[Y])
// 		draw_rect(game->screen, size, pos, 0x00FF0000);
// 	else
// 		draw_rect(game->screen, size, pos, 0x0000FF00);
// 	/*  */

// 	if (ray.side == 0)
// 		ray.perp_wall_dist = ray.sideDist[X] - ray.deltaDist[X];
// 	else
// 		ray.perp_wall_dist = ray.sideDist[Y] - ray.deltaDist[Y];
// 	ray.line_height = (int) (pane->size[Y] / ray.perp_wall_dist);
// 	ray.draw_start = -ray.line_height / 2 + pane->size[Y] / 2;
// 	if (ray.draw_start < 0)
// 		ray.draw_start = 0;
// 	ray.draw_end = ray.line_height / 2 + pane->size[Y] / 2;
// 	if (ray.draw_end < pane->size[Y])
// 		ray.draw_end = pane->size[Y] - 1;

// 	/* Red Line */
// 	t_info info;
// 	info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
// 		+ game->pane[MINIMAP]->offset[X];
// 	info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
// 		+ game->pane[MINIMAP]->offset[Y];
// 	info.length = ray.sideDist[X] * game->ui->minimap_box_size;
// 	info.color = 0x00ff0000;
// 	info.dir[X] = ray.rayDir[X];
// 	info.dir[Y] = ray.rayDir[Y];
// 	draw_line_dir(game->pane[MINIMAP], &info);
// 	/*  */

// 	/* Green Line */
// 	info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
// 		+ game->pane[MINIMAP]->offset[X];
// 	info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
// 		+ game->pane[MINIMAP]->offset[Y];
// 	info.length = ray.sideDist[Y] * game->ui->minimap_box_size;
// 	info.color = 0x0000ff00;
// 	info.dir[X] = ray.rayDir[X];
// 	info.dir[Y] = ray.rayDir[Y];
	
// 	draw_line_dir(game->pane[MINIMAP], &info);
// 	/*  */

// 	/* Red Wall */
// 	// info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
// 	// 	+ game->pane[MINIMAP]->offset[X];
// 	// info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
// 	// 	+ game->pane[MINIMAP]->offset[Y];
// 	// info.length = ray.sideDist[X] * game->ui->minimap_box_size;
// 	// info.color = 0x00ff0000;
// 	// info.radians = (inst->obj->rotation) * game->degtorad;
// 	// draw_line(game->pane[MINIMAP], &info);
// 	/*  */
// 	return (NULL);
// }	
