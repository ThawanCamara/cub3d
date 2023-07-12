/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:55:33 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/03 17:55:33 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_limits(char *line)
{
	size_t	i;
	size_t	j;
	char	check;
	// char	wall;

	i = 0;
	if (line == NULL)
		return (0);
	check = 0;
	// wall = 0;
	while (*(line + i) && !ft_isescape(*(line + i)))
	{
		j = -1;
		check = 0;
		while (MAP_BORDERS[++j])
		{
			check += (*(line + i) == MAP_BORDERS[j]);
			// wall += *(line + i) == 1;
		}
		if (check == 0 /* || wall == 0 */)
			return (1);
		i++;
	}
	return (0);
}

static int	check_content(t_game *game, char *line, char *player, int y)
{
	size_t	i;
	size_t	j;
	char	check;

	if (line == NULL)
		return (0);
	i = -1;
	check = 0;
	while (*(line + ++i) && !ft_isescape(*(line + i)))
	{
		j = -1;
		check = 0;
		while (MAP_CONTENT[++j])
			check += (*(line + i) == MAP_CONTENT[j]);
		*player += validate_player(line[i]);
		if (validate_player(line[i]))
		{
			game->mapdata->start_pos[X] = i;
			game->mapdata->start_pos[Y] = y;
			game->mapdata->inst_rot[0] = line[i];
		}
		if (check == 0)
			return (1);
	}
	return (0);
}

static int	check_spots(t_map *map, int x, int y, int bounds[2])
{
	if (x < 0
		|| x > bounds[X] - 1
		|| y < 0
		|| y > bounds[Y] - 1)
		return (0);
	if (map->map[y][x] == '1' || map->map[y][x] == ' ')
		return (0);
	return (1);
}

// int	is_map_closed(t_game *game)
static int	is_map_closed(t_map *map)
{
	int	i[2];

	i[Y] = 0;
	while (i[Y] < map->size[Y])
	{
		i[X] = 0;
		while (i[X] < map->size[X])
		{
			if (map->map[i[Y]][i[X]] == ' ')
			{
				if (check_spots(map, i[X] + 1, i[Y], map->size)
					|| check_spots(map, i[X] - 1, i[Y], map->size)
					|| check_spots(map, i[X], i[Y] + 1, map->size)
					|| check_spots(map, i[X], i[Y] - 1, map->size))
				{
					return (error_log("Map content not fenced."));
				}
			}
			i[X]++;
		}
		i[Y]++;
	}
	return (0);
}

int	map_checker(t_game *game)
{
	char	player;
	char	check;
	size_t	i;

	player = 0;
	check = 0;
	i = -1;
	while (game->mapdata->map[++i] && check == 0)
	{
		// if (check_empty_line(game->mapdata->map[i]))
		// 	return (1);
		if (i == 0 || i == (ft_strarr_size(game->mapdata->map) - 1))
			check += check_limits(game->mapdata->map[i]);
		else
			check += check_content(game, game->mapdata->map[i], &player, i);
	}
	if (is_map_closed(game->mapdata) || single_map(game) > 2)
		return (1);
	game->inst[0].obj->pos[X] = game->mapdata->start_pos[X] + 0.5;
	game->inst[0].obj->pos[Y] = game->mapdata->start_pos[Y] + 0.5;
	game->inst[0].obj->rotation = get_rotation(game->mapdata->inst_rot[0]);
	return ((check || player != 1));
}
