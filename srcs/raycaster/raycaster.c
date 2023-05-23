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

int	check_map_bounds(t_map *map, int *pos)
{
 	if (pos[X] < 0 || pos[X] > map->size[X] || pos[Y] < 0 || pos[Y] > map->size[Y])
		return (1);
	return (0);
}

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
}

t_rayhit	*ray(t_game *game, t_inst *inst, t_pane *pane, double angle, int w, int color)
{
	t_ray	ray;

	ray.rayDir[X] = cos(angle);
	ray.rayDir[Y] = sin(-angle);

	ray.deltaDist[X] = (fabs(ray.rayDir[X]) < 1e-9) ? game->mapdata->size[X] : fabs(1 / ray.rayDir[X]);
	ray.deltaDist[Y] = (fabs(ray.rayDir[Y]) < 1e-9) ? game->mapdata->size[Y] : fabs(1 / ray.rayDir[Y]);

	ray.map[X] = (int)inst->obj->pos[X];
	ray.map[Y] = (int)inst->obj->pos[Y];

	ray.hit_flag = 0;

	sidestep(inst, &ray);

	while (ray.hit_flag == 0)
	{
		if (ray.sideDist[X] < ray.sideDist[Y])
		{
			ray.sideDist[X] += ray.deltaDist[X];
			ray.map[X] += ray.step[X];
			ray.side = 0;
			ray.face = 1 + ray.step[X];
			
			ray.hit.distance = ray.sideDist[X];
		}
		else
		{
			ray.sideDist[Y] += ray.deltaDist[Y];
			ray.map[Y] += ray.step[Y];
			ray.side = 1;
			ray.face = 5 + ray.step[Y];
			
			ray.hit.distance = ray.sideDist[Y];
		}
		// int	v[2];
		// vector2(0, 0, &v[X], &v[Y]);
		// if (check_bounds(ray.map, v, game->mapdata->size))
		// printf("%d + %d\n", !check_map_bounds(game->mapdata, ray.map) && game->mapdata->map[ray.map[Y]][ray.map[X]] == '1', ray.map[X]);
		// if (check_map_bounds(game->mapdata, ray.map))
		// {
		// 	ray.hit_flag = 1;
		// 	break ;
		// }
		if (game->mapdata->map[ray.map[Y]][ray.map[X]] == '1')
			ray.hit_flag = 1;
	}

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

	(void)color;
	
	// printf("%f\n", angle * (180 / M_PI));

	t_info info;
	if (ray.sideDist[X] < ray.sideDist[Y])
	{
		/* Red Line */
		info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[X];
		info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[Y];
		info.length = ray.sideDist[X] * game->ui->minimap_box_size;
		info.color = color;
		info.dir[X] = ray.rayDir[X];
		info.dir[Y] = ray.rayDir[Y];
		draw_line_dir(game->pane[MINIMAP], &info);
		/*  */

		/* rebatimento */
		double dist = (ray.sideDist[X]) * game->ui->minimap_box_size;

		// bx = px + h * cos(a);
		// by = py - h * sin(a);

		info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[X] + dist * cos(angle);
		info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[Y] - dist * sin(angle);
		info.length = ray.sideDist[X] * game->ui->minimap_box_size * cos((inst->obj->rotation * game->degtorad) - angle);
		// printf(">> Dist: \e[38;5;1m%f \e[0m| Len:\e[38;5;1m %d\e[0m\n", ray.sideDist[X] * game->ui->minimap_box_size, info.length);
		// printf(">> Angle:\e[38;5;1m %f \e[0m| Cos:\e[38;5;1m %f\e[0m\n", angle * (180/M_PI), cos(angle));
		info.color = 0x00FF0000;
		info.radians = (inst->obj->rotation + 180) * game->degtorad;
		draw_line_r(game->pane[MINIMAP], &info);
	}
	else
	{
		/* Green Line */
		info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[X];
		info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[Y];
		info.length = ray.sideDist[Y] * game->ui->minimap_box_size;
		info.color = color;
		info.dir[X] = ray.rayDir[X];
		info.dir[Y] = ray.rayDir[Y];
		draw_line_dir(game->pane[MINIMAP], &info);
		/*  */

		/* rebatimento */
		double dist = (ray.sideDist[Y] ) * game->ui->minimap_box_size;

		info.pos[X] = inst->obj->pos[X] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[X] + dist * cos(angle);
		info.pos[Y] = inst->obj->pos[Y] * game->ui->minimap_box_size
			+ game->pane[MINIMAP]->offset[Y] - dist * sin(angle);
		info.length = ray.sideDist[Y] * game->ui->minimap_box_size * cos((inst->obj->rotation * game->degtorad) - angle);
		// printf(">> Dist: \e[38;5;2m%f \e[0m| Len:\e[38;5;2m %d\e[0m\n", ray.sideDist[Y] * game->ui->minimap_box_size, info.length);
		// printf(">> Angle:\e[38;5;2m %f \e[0m| Cos:\e[38;5;2m %f\e[0m\n", angle * (180/M_PI), cos(angle));
		info.color = 0x00FF0000;
		info.radians = (inst->obj->rotation + 180) * game->degtorad;
		draw_line_r(game->pane[MINIMAP], &info);
	}

	if (ray.side == 0)
		ray.perp_wall_dist = (ray.sideDist[X] - ray.deltaDist[X]) * cos((inst->obj->rotation * game->degtorad) - angle);
	else
		ray.perp_wall_dist = (ray.sideDist[Y] - ray.deltaDist[Y]) * cos((inst->obj->rotation * game->degtorad) - angle);
	ray.line_height = (int) (pane->size[Y] / ray.perp_wall_dist);
	ray.draw_start = -ray.line_height / 2 + pane->size[Y] / 2;
	if (ray.draw_start < 0)
		ray.draw_start = 0;
	ray.draw_end = ray.line_height / 2 + pane->size[Y] / 2;
	if (ray.draw_end >= pane->size[Y])
		ray.draw_end = pane->size[Y] - 1;


	// t_info info;

	/* Red Wall */
	info.pos[X] = w + pane->offset[X];
	info.pos[Y] = ray.draw_start;
	info.length = ray.draw_end - ray.draw_start;

	// double dist = (ray.sideDist[X]) * game->ui->minimap_box_size;
	if (ray.face == 0)
		info.color = 0x00FF0000;
	if (ray.face == 2)
		info.color = 0x00FF9900;
	if (ray.face == 4)
		info.color = 0x00FFFFFF;
	if (ray.face == 6)
		info.color = 0x002222FF;

	draw_column(pane, &info);
	/*  */
	return (NULL);
}	
