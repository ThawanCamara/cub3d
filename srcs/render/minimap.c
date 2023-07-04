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

void	render_minimap(t_game *game)
{
	int	i[2];
	int	color[4];
	t_idraw	info;

	vector2(0, 0, &i[X], &i[Y]);
	vector2(game->pane[MINIMAP]->size[X], game->pane[MINIMAP]->size[Y],
		&info.size[X], &info.size[Y]);
	vector2(0, 0, &info.pos[X], &info.pos[Y]);
	info.color = 0x00922222;
	// draw_rect(game->pane[MINIMAP], &info);
	color[0] = 0x00444444;
	color[1] = 0x00999999;
	color[2] = 0x00999999;
	color[3] = 0x00444444;
	vector2(game->ui->minimap_box_size, game->ui->minimap_box_size,
		&info.size[X], &info.size[Y]);
	while (i[X] < game->mapdata->size[X] && i[Y] < game->mapdata->size[Y])
	{
		info.pos[X] = i[X] * info.size[X] + game->pane[MINIMAP]->offset[X];
		info.pos[Y] = i[Y] * info.size[Y] + game->pane[MINIMAP]->offset[Y];
		if (game->mapdata->map[i[Y]][i[X]] == 49 || game->mapdata->map[i[Y]][i[X]] == 32)
		{
			info.color = 0x00222222;
			// draw_rect(game->pane[MINIMAP], &info);
		}
		else
			info.color = color[1];
			// info.color = color[i[Y] % 2 == 0 + (i[X] % 2 == 0)];
		draw_rect(game->pane[MINIMAP], &info);
		i[X]++;
		if (i[X] == game->mapdata->size[X] && i[Y] < game->mapdata->size[Y])
		{
			i[X] = 0;
			i[Y]++;
		}
	}
}

void	resize_minimap(t_game *game, int key)
{
	pane_resize(game->pane[MINIMAP], (key == KEY_EQUAL) * game->map_resize * 2 - game->map_resize);
	game->ui->minimap_scale = get_minimap_scale(game, game->pane[MINIMAP]);
	game->ui->minimap_box_size = BOX_SIZE * game->ui->minimap_scale;
}