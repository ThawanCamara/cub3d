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

// int	check_map_bounds(t_map *map, int *pos)
// {
//  	if (pos[X] < 0 || pos[X] > map->size[X] || pos[Y] < 0 || pos[Y] > map->size[Y])
// 		return (1);
// 	return (0);
// }

// static void	get_side_steps(t_inst *inst, t_ray *ray)
// {
// 	if (ray->dir[X] < 0)
// 	{
// 		ray->step[X] = -1;
// 		ray->sideDist[X] = (inst->obj->pos[X] - ray->map[X]) * ray->deltaDist[X];
// 	}
// 	else
// 	{
// 		ray->step[X] = 1;
// 		ray->sideDist[X] = (ray->map[X] + 1.0 - inst->obj->pos[X]) * ray->deltaDist[X];
// 	}
// 	if (ray->dir[Y] < 0)
// 	{
// 		ray->step[Y] = -1;
// 		ray->sideDist[Y] = (inst->obj->pos[Y] - ray->map[Y]) * ray->deltaDist[Y];
// 	}
// 	else
// 	{
// 		ray->step[Y] = 1;
// 		ray->sideDist[Y] = (ray->map[Y] + 1.0 - inst->obj->pos[Y]) * ray->deltaDist[Y];
// 	}
// }

// t_rayhit	*ray(t_game *game, t_inst *inst, t_pane *pane, double angle, int width, double view, int color)
// {
// 	t_ray	ray;

// 	ray.dir[X] = cos(angle);
// 	ray.dir[Y] = sin(-angle);

// 	ray.deltaDist[X] = (fabs(ray.dir[X]) < 1e-9) ? game->mapdata->size[X] : fabs(1 / ray.dir[X]);
// 	ray.deltaDist[Y] = (fabs(ray.dir[Y]) < 1e-9) ? game->mapdata->size[Y] : fabs(1 / ray.dir[Y]);

// 	ray.map[X] = (int)inst->obj->pos[X];
// 	ray.map[Y] = (int)inst->obj->pos[Y];

// 	ray.hit_flag = 0;

// 	get_side_steps(inst, &ray);

// 	while (ray.hit_flag == 0)
// 	{
// 		if (ray.sideDist[X] < ray.sideDist[Y])
// 		{
// 			ray.sideDist[X] += ray.deltaDist[X];
// 			ray.map[X] += ray.step[X];
// 			ray.side = 0;
// 			ray.face = 1 + ray.step[X];
			
// 			ray.hit.distance = ray.sideDist[X] - ray.deltaDist[X];
// 		}
// 		else
// 		{
// 			ray.sideDist[Y] += ray.deltaDist[Y];
// 			ray.map[Y] += ray.step[Y];
// 			ray.side = 1;
// 			ray.face = 5 + ray.step[Y];
			
// 			ray.hit.distance = ray.sideDist[Y] - ray.deltaDist[Y];
// 		}

// 		if (game->mapdata->map[ray.map[Y]][ray.map[X]] == '1')
// 			ray.hit_flag = 1;
// 	}

	/* Red Square */
	// int pos[2];
	// int size[2];
	// vector2(game->ui->minimap_box_size, game->ui->minimap_box_size, &size[X], &size[Y]);
	// vector2(ray.map[X] * game->ui->minimap_box_size, ray.map[Y] * game->ui->minimap_box_size, &pos[X], &pos[Y]);
	// if (ray.sideDist[X] < ray.sideDist[Y])
	// 	draw_rect(game->screen, size, pos, 0x00440000);
	// else
	// 	draw_rect(game->screen, size, pos, 0x00004400);
	/*  */
	
	// printf("%f\n", angle * (180 / M_PI));

	// (void)color;
	// (void)view;
	// t_idraw info;
	// info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
	// 	+ game->pane[MINIMAP]->offset[X];
	// info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
	// 	+ game->pane[MINIMAP]->offset[Y];
	// info.length = ray.hit.distance * game->ui->minimap_box_size;
	// info.color = 0x00880000;
	// info.dir[X] = ray.dir[X];
	// info.dir[Y] = ray.dir[Y];
	// draw_line_dir(game->pane[MINIMAP], &info);

	// info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
	// 	+ game->pane[MINIMAP]->offset[X] + ray.hit.distance * game->ui->minimap_box_size * cos(angle);
	// info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
	// 	+ game->pane[MINIMAP]->offset[Y] - ray.hit.distance * game->ui->minimap_box_size * sin(angle);

	// printf("[%.2f,%.2f] - %d\n",
	// (inst->obj->pos[X] + ray.hit.distance * cos(angle)),
	// (inst->obj->pos[Y] - ray.hit.distance * sin(angle)), ray.side);

	// info.length = ray.hit.distance * game->ui->minimap_box_size * cos(inst->obj->rotation * game->degtorad - angle);
	// info.color = 0x00FF0000;
	// info.rad = (inst->obj->rotation + 180) * game->degtorad;
	// draw_line_r(game->pane[MINIMAP], &info);

	// if (ray.sideDist[X] < ray.sideDist[Y])
	// {
	// 	/* Red Line */
	// 	info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
	// 		+ game->pane[MINIMAP]->offset[X];
	// 	info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
	// 		+ game->pane[MINIMAP]->offset[Y];
	// 	info.length = fabs(ray.hit.distance) * game->ui->minimap_box_size;
	// 	info.color = 0x00880000;
	// 	info.dir[X] = ray.rayDir[X];
	// 	info.dir[Y] = ray.rayDir[Y];
	// 	draw_line_dir(game->pane[MINIMAP], &info);
	// 	/*  */

	// 	/* rebatimento */
	// 	double dist = (ray.sideDist[X]) * game->ui->minimap_box_size;


	// 	info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
	// 		+ game->pane[MINIMAP]->offset[X] + dist * cos(angle);
	// 	info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
	// 		+ game->pane[MINIMAP]->offset[Y] - dist * sin(angle);
	// 	info.length = ray.sideDist[X] * game->ui->minimap_box_size * cos(inst->obj->rotation * game->degtorad - angle);
	// 	info.color = 0x00FF0000;
	// 	info.radians = (inst->obj->rotation + 180) * game->degtorad;
	// 	draw_line_r(game->pane[MINIMAP], &info);
	// }
	// else
	// {
		/* Green Line */
		// info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
		// 	+ game->pane[MINIMAP]->offset[X];
		// info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
		// 	+ game->pane[MINIMAP]->offset[Y];
		// info.length = fabs(ray.sideDist[Y] - ray.deltaDist[Y]) * game->ui->minimap_box_size;
		// info.color = 0x00008800;
		// info.dir[X] = ray.rayDir[X];
		// info.dir[Y] = ray.rayDir[Y];
		// draw_line_dir(game->pane[MINIMAP], &info);
		/*  */

		/* rebatimento */
		// double dist = (ray.sideDist[Y] ) * game->ui->minimap_box_size;

		// info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
		// 	+ game->pane[MINIMAP]->offset[X] + dist * cos(angle);
		// info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
		// 	+ game->pane[MINIMAP]->offset[Y] - dist * sin(angle);
		// info.length = ray.sideDist[Y] * game->ui->minimap_box_size * cos(inst->obj->rotation * game->degtorad - angle);
		// info.color = 0x00FF0000;
		// info.radians = (inst->obj->rotation + 180) * game->degtorad;
		// draw_line_r(game->pane[MINIMAP], &info);
	//}

	// printf("%f - %f = %f\n", inst->obj->rotation * game->degtorad, angle, inst->obj->rotation * game->degtorad - angle);

	// if (ray.side == 0)
	// 	ray.perp_wall_dist = (ray.sideDist[X] - ray.deltaDist[X]) * cos(inst->obj->rotation * game->degtorad - angle);
	// else
	// 	ray.perp_wall_dist = (ray.sideDist[Y] - ray.deltaDist[Y]) * cos(inst->obj->rotation * game->degtorad - angle);
	// // ray.perp_wall_dist = ray.hit.distance * cos(inst->obj->rotation * game->degtorad - angle);
	// // ray.line_height = (int) (pane->size[Y] / ray.perp_wall_dist);
	// ray.line_height = (int) (pane->size[Y] / ray.perp_wall_dist);
	// ray.draw_start = -ray.line_height / 2 + pane->size[Y] / 2;
	// if (ray.draw_start < 0)
	// 	ray.draw_start = 0;
	// ray.draw_end = ray.line_height / 2 + pane->size[Y] / 2;
	// if (ray.draw_end >= pane->size[Y])
	// 	ray.draw_end = pane->size[Y] - 1;


// 	// t_info info;

// 	/* Red Wall */
// 	info.pos[X] = width + pane->offset[X];
// 	info.pos[Y] = ray.draw_start;
// 	info.length = ray.draw_end - ray.draw_start;

// 	// double dist = (ray.sideDist[X]) * game->ui->minimap_box_size;
// 	if (ray.face == 0)
// 		info.color = 0x00FF0000;
// 	if (ray.face == 2)
// 		info.color = 0x00FF9900;
// 	if (ray.face == 4)
// 		info.color = 0x00FFFFFF;
// 	if (ray.face == 6)
// 		info.color = 0x002222FF;

// 	draw_column(pane, &info);
// 	/*  */
// 	return (NULL);
// }	



/* 
 	x * cos(angle) 
 */