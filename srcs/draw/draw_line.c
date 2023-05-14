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

static void	set_data(t_draw_info *info, int *pos, int *delta, int *step)
{
	pos[X] = info->pos[X] + info->length * cos(-info->radians);
	pos[Y] = info->pos[Y] + info->length * sin(-info->radians);
	delta[X] = abs(pos[X] - info->pos[X]);
	delta[Y] = abs(pos[Y] - info->pos[Y]);
	step[X] = 1 + (!(info->pos[X] < pos[X]) * -2);
	step[Y] = 1 + (!(info->pos[Y] < pos[Y]) * -2);
}

void	draw_line(t_pane *pane, t_draw_info *info)
{
	int	delta[2];
	int	pos[2];
	int	step[2];
	int	err[2];

	set_data(info, pos, delta, step);
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
		if (check_bounds(info->pos, pane->min_bounds, pane->max_bounds))
			draw_pixel(pane->screen, info->pos, info->color);
	}
}

// void draw_line(t_screen *imgdata, int *start, double angle, int *limits)
// {
// 	int	delta[2];
// 	int	pos[2];
// 	int	step[2];
// 	int	err;

// 	int length = 150;

// 	double rad = -angle * (M_PI / 180);

// 	pos[X] = start[X] + length * cos(rad);
// 	pos[Y] = start[Y] + length * sin(rad);
// 	delta[X] = abs(pos[X] - start[X]);
// 	delta[Y] = abs(pos[Y] - start[Y]);
// 	step[X] = 1 + (!(start[X] < pos[X]) * -2);
// 	step[Y] = 1 + (!(start[Y] < pos[Y]) * -2);

// 	err = delta[X] - delta[Y];
//     while (start[X] != pos[X] || start[Y] != pos[Y])
//     {
//         int e2 = err << 1;

//         if (e2 > -delta[Y])
//         {
// 			err -= delta[Y];
// 			start[X] += step[X];
//         }

//         if (e2 < delta[X])
//         {
// 			err += delta[X];
// 			start[Y] += step[Y];
//         }

//         if (check_bounds(start, limits))
// 			draw_pixel(imgdata, start, 0x0000FF00);
//     }
// }