/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:03:06 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/30 15:03:06 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// size_X
// size_Y
// color
// scale
// pos_X
// pos_Y

// size[2]
// color
// scale
// pos[2]

void	draw_rect(t_game *game, int *size, int *pos, int color)
{
	int	i[2];
	//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
	i[X] = 0;
	i[Y] = 0;
	while (i[X] < size[X] || i[Y] < size[Y])
	{
		mlx_pixel_put(game->mlx, game->win, pos[X] + i[X], pos[Y] + i[Y], color);
		i[X]++;
		if (i[X] == size[X] && i[Y] < size[Y])
		{
			i[X] = 0;
			i[Y]++;
		}
	}
}