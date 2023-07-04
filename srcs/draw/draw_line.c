/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:43:27 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/06 12:43:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//Note: Could use dirX dirY instead of cos(-info->radians)

static void	set_data_r(t_idraw *info, int *pos, int *delta, int *step)
{
	pos[X] = info->pos[X] + info->length * cos(-info->rad);
	pos[Y] = info->pos[Y] + info->length * sin(-info->rad);
	delta[X] = abs(pos[X] - info->pos[X]);
	delta[Y] = abs(pos[Y] - info->pos[Y]);
	step[X] = 1 + (!(info->pos[X] < pos[X]) * -2);
	step[Y] = 1 + (!(info->pos[Y] < pos[Y]) * -2);
}

void	draw_line_r(t_pane *pane, t_idraw *info)
{
	int	delta[2];
	int	pos[2];
	int	step[2];
	int	err[2];

	set_data_r(info, pos, delta, step);
	err[0] = delta[X] - delta[Y];
	while (info->pos[X] != pos[X] || info->pos[Y] != pos[Y])
	{
		err[1] = err[0] << 1;
		if (err[1] > -delta[Y])
		{
			err[0] -= delta[Y];
			info->pos[X] += step[X];
		}
		if (err[1] < delta[X])
		{
			err[0] += delta[X];
			info->pos[Y] += step[Y];
		}
		if (check_bounds(info->pos, pane->min_bounds, pane->max_bounds)
			&& check_mapbounds(info->pos, pane->screen->size))
			draw_pixel(pane->screen, info->pos, info->color);
	}
}

static void	set_data_dir(t_idraw *info, int *pos, int *delta, int *step)
{
	pos[X] = info->pos[X] + info->length * info->dir[X];
	pos[Y] = info->pos[Y] + info->length * info->dir[Y];
	delta[X] = abs(pos[X] - info->pos[X]);
	delta[Y] = abs(pos[Y] - info->pos[Y]);
	step[X] = 1 + (!(info->pos[X] < pos[X]) * -2);
	step[Y] = 1 + (!(info->pos[Y] < pos[Y]) * -2);
}

void	draw_line_dir(t_pane *pane, t_idraw *info)
{
	int	delta[2];
	int	pos[2];
	int	step[2];
	int	err[2];

	set_data_dir(info, pos, delta, step);
	err[0] = delta[X] - delta[Y];
	while (info->pos[X] != pos[X] || info->pos[Y] != pos[Y])
	{
		err[1] = err[0] << 1;
		if (err[1] > -delta[Y])
		{
			err[0] -= delta[Y];
			info->pos[X] += step[X];
		}
		if (err[1] < delta[X])
		{
			err[0] += delta[X];
			info->pos[Y] += step[Y];
		}
		if (check_bounds(info->pos, pane->min_bounds, pane->max_bounds)
			&& check_mapbounds(info->pos, pane->screen->size))
			draw_pixel(pane->screen, info->pos, info->color);
	}
}

void	draw_column(t_pane *pane, t_idraw *info)
{
	int	i;

	i = 0;
	while (i < info->length)
	{
		info->pos[Y] += 1;
		if (check_bounds(info->pos, pane->min_bounds, pane->max_bounds)
			&& check_mapbounds(info->pos, pane->screen->size))
			draw_pixel(pane->screen, info->pos, info->color);
		i++;
	}
}
