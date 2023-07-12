/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:04:36 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/30 14:04:36 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_missing_data(t_game *game)
{
	if (game->mapdata->texture[NORTH].img
		&& game->mapdata->texture[SOUTH].img
		&& game->mapdata->texture[WEST].img
		&& game->mapdata->texture[EAST].img
		&& game->mapdata->valid_skyfloor[SKY]
		&& game->mapdata->valid_skyfloor[FLOOR])
		return (0);
	return (1);
}

static int	get_input(t_game *game, char *line)
{
	char	**arr;
	char	valid;
	int		check;

	valid = 0;
	if (line == NULL)
		return (0);
	arr = ft_split(line, ' ');
	if (arr != NULL)
	{
		check = type_handler(arr[0]);
		if (check == 2)
			valid += get_skyfloor(game, arr, arr[0][0] == 'F');
		else if (check == 1)
			valid += get_textures(game, arr);
		else if (check != 3)
			valid += error_log("Unknown specifier.");
	}
	ft_free_arr((void **)arr);
	return (valid);
}

int	clear_reading(int fd, char *line)
{
	free(line);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	return (1);
}

int	map_read_loop(t_game *game, int fd)
{
	char	*line;

	line = "";
	while (line)
	{
		if (!check_missing_data(game))
		{
			line = NULL;
			if (build_map(game, fd))
				return (clear_reading(fd, line));
			free(line);
			break ;
		}
		line = get_next_line(fd);
		if (get_input(game, line))
			return (clear_reading(fd, line));
		free(line);
	}
	if (check_missing_data(game))
		return (error_log("Missing Data."));
	return (0);
}
