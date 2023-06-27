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

// int	get_map_start(char *str)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	check;

// 	i = 0;
// 	if (str == NULL)
// 		return (0);
// 	check = 0;
// 	while (*(str + i) && !ft_isescape(*(str + i)))
// 	{
// 		j = -1;
// 		check = 0;
// 		while (MAP_BORDERS[++j])
// 			check += (*(str + i) == MAP_BORDERS[j]);
// 		if (check == 0)
// 			return (check);
// 		i++;
// 	}
// 	return (check);
// }

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

	valid = 0;
	if (line == NULL)
		return (0);
	arr = ft_split(line, ' ');
	if (arr != NULL && ft_strarr_size(arr) == 2)
	{
		if (!ft_strncmp(arr[0], "C\0", 2) || !ft_strncmp(arr[0], "F\0", 2))
			valid += get_skyfloor(game, arr, arr[0][0] == 'F');
		else
			valid += get_textures(game, arr);
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
	return (error_log("Could not read map data."));
}

int	map_read_loop(t_game *game, int fd) 
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!check_missing_data(game))
		{
			if (build_map(game, fd))
				return (clear_reading(fd, line));
			free(line);
			// printf("---->\n");
			break ;
			// ft_printf("%s%s%s", ORANGE, line, RESET);
		}
		else
		{
			// ft_printf("%s", line);
			if (get_input(game, line))
				return (clear_reading(fd, line));
		}
		free(line);
	}
	if (check_missing_data(game))
		return (error_log("Missing Data."));
	return (0);
}