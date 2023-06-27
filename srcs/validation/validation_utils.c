/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:04:03 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/30 14:04:03 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	map_setup_memory(t_game *game)
{
	game->mapdata = (t_map *)malloc(sizeof(t_map));
	if (game->mapdata == NULL)
		return (1);
	game->mapdata->texture = (t_screen *)malloc(sizeof(t_screen ) * 4);
	if (game->mapdata->texture == NULL)
		return (1);
	game->mapdata->start_pos = (int *)malloc(sizeof(int) * (2 * game->total_insts));
	if (game->mapdata->start_pos == NULL)
		return (1);
	game->mapdata->map = NULL;
	game->mapdata->inst_rot[0] = 0;
	game->mapdata->inst_rot[1] = 0;
	game->mapdata->trgb[0] = 0;
	game->mapdata->trgb[1] = 0;
	game->mapdata->valid_skyfloor[SKY] = 0;
	game->mapdata->valid_skyfloor[FLOOR] = 0;
	return (0);
}

double	get_rotation(char rot)
{
	if (rot == 'N')
		return (90);
	else if (rot == 'S')
		return (270);
	else if (rot == 'W')
		return (180);
	else if (rot == 'E')
		return (0);
	return (35);
}
