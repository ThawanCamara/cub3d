/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:03:28 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/04 19:46:48 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	get_side_steps(t_ray *ray, t_iray *iray)
{
	if (ray->dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (iray->start[X] - ray->map[X]) * ray->delta_dist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = (ray->map[X] + 1.0 - iray->start[X])
			* ray->delta_dist[X];
	}
	if (ray->dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (iray->start[Y] - ray->map[Y]) * ray->delta_dist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = (ray->map[Y] + 1.0 - iray->start[Y])
			* ray->delta_dist[Y];
	}
}

static double	get_delta(t_game *game, t_ray *ray, int axis)
{
	(void)game;
	if (fabs(ray->dir[axis]) < 1e-9)
		return (1e30);
	else
		return (fabs(1 / ray->dir[axis]));
}

static void	ray_loop(t_game *game, t_ray *ray, t_iray *iray)
{
	while (ray->hit_flag == 0)
	{
		ray->side = !(ray->side_dist[X] < ray->side_dist[Y]);
		ray->side_dist[ray->side] += ray->delta_dist[ray->side];
		ray->map[ray->side] += ray->step[ray->side];
		ray->face = ray_get_face(ray->step[ray->side], ray->side);
		if (iray->max_len > 0 && ray->side_dist[ray->side]
			>= iray->max_len + ray->delta_dist[ray->side])
		{
			ray->hit_flag = 2;
			ray->side_dist[ray->side] = iray->max_len
				+ ray->delta_dist[ray->side];
		}
		else
		{
			if (check_mapbounds(ray->map, game->mapdata->size))
			{
				if (game->mapdata->map[ray->map[Y]][ray->map[X]] == '1')
					ray->hit_flag = 1;
			}
			else
				ray->hit_flag = -1;
		}
	}
}

static void	get_hit_info(t_ray *ray, t_rayhit *hit, t_iray *iray, int side)
{
	hit->rad = iray->rad;
	hit->distance = ray->side_dist[side] - ray->delta_dist[side];
	hit->side = side;
	hit->flag = ray->hit_flag;
	hit->face = ray->face;
	hit->pos[X] = iray->start[X] + hit->distance * iray->dir[X];
	hit->pos[Y] = iray->start[Y] + hit->distance * iray->dir[Y];
	hit->start[X] = iray->start[X];
	hit->start[Y] = iray->start[Y];
	hit->dir[X] = iray->dir[X];
	hit->dir[Y] = iray->dir[Y];
}

void	ray2(t_game *game, t_iray *iray, t_rayhit *hit)
{
	t_ray	ray;

	ray.dir[X] = iray->dir[X];
	ray.dir[Y] = iray->dir[Y];
	ray.delta_dist[X] = get_delta(game, &ray, X);
	ray.delta_dist[Y] = get_delta(game, &ray, Y);
	ray.map[X] = (int)iray->start[X];
	ray.map[Y] = (int)iray->start[Y];
	ray.hit_flag = 0;
	ray.side = 0;
	ray.step[X] = 0;
	ray.step[Y] = 0;
	get_side_steps(&ray, iray);
	ray_loop(game, &ray, iray);
	get_hit_info(&ray, hit, iray, ray.side);
}
