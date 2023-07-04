/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:03:28 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/04 03:58:55 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	get_side_steps(t_ray *ray, t_iray *iray)
{
	if (ray->dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->sideDist[X] = (iray->start[X] - ray->map[X]) * ray->deltaDist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->sideDist[X] = (ray->map[X] + 1.0 - iray->start[X])
			* ray->deltaDist[X];
	}
	if (ray->dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->sideDist[Y] = (iray->start[Y] - ray->map[Y]) * ray->deltaDist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->sideDist[Y] = (ray->map[Y] + 1.0 - iray->start[Y])
			* ray->deltaDist[Y];
	}
}

static double	get_delta(t_game *game, t_ray *ray, int axis)
{
	(void)game;
		// return (game->mapdata->size[axis]);
	if (fabs(ray->dir[axis]) < 1e-9)
		return (1e30);
	else
		return (fabs(1 / ray->dir[axis]));
}

//Y cima
// 1 + (0 * 4) + (-1) = 0
//Y baixo
// 1 + (0 * 4) + (+1) = 2
//X esquerda
// 1 + (1 * 4) + (-1) = 4
//X direita
// 1 + (1 * 4) + (+1) = 6

static void	ray_loop(t_game *game, t_ray *ray, t_iray *iray)
{
	while (ray->hit_flag == 0)
	{
		ray->side = !(ray->sideDist[X] < ray->sideDist[Y]);
		ray->sideDist[ray->side] += ray->deltaDist[ray->side];
		ray->map[ray->side] += ray->step[ray->side];
		ray->face = (1 + (ray->side * 4)) + ray->step[ray->side];
		if (iray->max_len > 0 && ray->sideDist[ray->side]
			>= iray->max_len + ray->deltaDist[ray->side])
		{
			ray->hit_flag = 2;
			ray->sideDist[ray->side] = iray->max_len
				+ ray->deltaDist[ray->side];
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
		// printf("side: %d | step %d\n", ray->side, ray->step[ray->side]);
}

// hit->pos[X] = iray->start[X] + hit->distance * cos(iray->rad);
// hit->pos[Y] = iray->start[Y] - hit->distance * sin(iray->rad);

static void	get_hit_info(t_ray *ray, t_rayhit *hit, t_iray *iray, int side)
{

	hit->rad = iray->rad;
	hit->distance = ray->sideDist[side] - ray->deltaDist[side];
	hit->side = side;
	hit->flag = ray->hit_flag;
	hit->face = ray->face;
	hit->pos[X] = iray->start[X] + hit->distance * iray->dir[X];
	hit->pos[Y] = iray->start[Y] + hit->distance * iray->dir[Y];
	hit->start[X] = iray->start[X];
	hit->start[Y] = iray->start[Y];
	hit->dir[X] = iray->dir[X];
	hit->dir[Y] = iray->dir[Y];
	// printf("face: %d\n", hit->face);
}

// ray.dir[X] = cos(iray->rad);
// ray.dir[Y] = sin(-iray->rad);

void	ray2(t_game *game, t_iray *iray, t_rayhit *hit)
{
	t_ray	ray;

	ray.dir[X] = iray->dir[X];
	ray.dir[Y] = iray->dir[Y];
	ray.deltaDist[X] = get_delta(game, &ray, X);
	ray.deltaDist[Y] = get_delta(game, &ray, Y);
	ray.map[X] = (int)iray->start[X];
	ray.map[Y] = (int)iray->start[Y];
	ray.hit_flag = 0;
	ray.side = 0;
	ray.step[X] = 0;
	ray.step[Y] = 0;
	get_side_steps(&ray, iray);
	ray_loop(game, &ray, iray);
	get_hit_info(&ray, hit, iray, ray.side);
	// printf("step: %d | side: %d)\n", ray.step[X], hit->side);
}
