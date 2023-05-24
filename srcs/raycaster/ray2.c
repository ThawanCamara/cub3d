/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:03:28 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/23 22:42:00 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	get_side_steps(t_inst *inst, t_ray *ray)
{
	if (ray->dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->sideDist[X] = (inst->obj->pos[X] - ray->map[X]) * ray->deltaDist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->sideDist[X] = (ray->map[X] + 1.0 - inst->obj->pos[X]) * ray->deltaDist[X];
	}
	if (ray->dir[Y] < 0)
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

static double	get_delta(t_game *game, t_ray *ray, int axis)
{
	if (fabs(ray->dir[axis]) < 1e-9)
		return (game->mapdata->size[axis]);
	else
		return (ray->deltaDist[axis] = fabs(1 / ray->dir[axis]));
}

static void	ray_loop(t_game *game, t_ray *ray, t_rayhit *hit)
{
	while (ray->hit_flag == 0)
	{
		if (ray->sideDist[X] < ray->sideDist[Y])
		{
			ray->sideDist[X] += ray->deltaDist[X];
			ray->map[X] += ray->step[X];
			ray->side = 0;
			ray->face = 1 + ray->step[X];
			
		}
		else
		{
			ray->sideDist[Y] += ray->deltaDist[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1;
			ray->face = 5 + ray->step[Y];
			hit->distance = ray->sideDist[Y] - ray->deltaDist[Y];
		}
		if (game->mapdata->map[ray->map[Y]][ray->map[X]] == '1')
			ray->hit_flag = 1;
	}
}

static void	get_hit_info(t_ray *ray, t_rayhit *hit, int side)
{
	hit->distance = ray->sideDist[side] - ray->deltaDist[side];
	hit->side = side;
	hit->face = (1 + side * 4) + ray->step[side];
}

t_rayhit	*ray2(t_game *game, t_inst *inst, t_info *info)
{
	t_ray		ray;
	t_rayhit	*hit;

	hit = (t_rayhit *)malloc(sizeof(t_rayhit));
	if (!hit)
		return (NULL);
	ray.dir[X] = cos(info->rad);
	ray.dir[Y] = sin(-info->rad);
	ray.deltaDist[X] = get_delta(game, &ray, X);
	ray.deltaDist[Y] = get_delta(game, &ray, Y);
	ray.map[X] = (int)inst->obj->pos[X];
	ray.map[Y] = (int)inst->obj->pos[Y];
	ray.hit_flag = 0;
	get_side_steps(inst, &ray);
	ray_loop(game, &ray, hit);
	get_hit_info(&ray, hit, !(ray.sideDist[X] < ray.sideDist[Y]));
	return (hit);
}
