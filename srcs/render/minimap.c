/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:28:21 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/10 19:28:21 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// 16
// 256 x 192
// 48 x 36

// 48 * (16 * f)

void	render_minimap(t_game *game)
{
	int	i[2];
	int	offset[2];
	int	box[2];

	vector2(0, 0, &i[X], &i[Y]);
	vector2(game->ui->minimap_box_size, game->ui->minimap_box_size,
		&box[X], &box[Y]);
	while (i[X] < game->mapdata->size[X] && i[Y] < game->mapdata->size[Y])
	{
		offset[X] = i[X] * box[X] + game->pane[MINIMAP]->offset[X];
		offset[Y] = i[Y] * box[Y] + game->pane[MINIMAP]->offset[Y];
		/* temp */
		if (game->mapdata->map[i[Y]][i[X]] == 49)
				draw_rect(game->screen, box, offset, 0x0077771E);
		else if (game->mapdata->map[i[Y]][i[X]] == 48)
		{
			if (i[Y] % 2)
			{
				if (i[X] % 2)
					draw_rect(game->screen, box, offset, 0x00999999);
				else
					draw_rect(game->screen, box, offset, 0x00999999);
			}
			else
			{
				if (i[X] % 2)
					draw_rect(game->screen, box, offset, 0x00999999);
				else
					draw_rect(game->screen, box, offset, 0x00999999);
			}
		}
		i[X]++;
		if (i[X] == game->mapdata->size[X] && i[Y] < game->mapdata->size[Y])
		{
			i[X] = 0;
			i[Y]++;
		}
	}
}
