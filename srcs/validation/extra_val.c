/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:31:00 by llima             #+#    #+#             */
/*   Updated: 2023/07/12 13:32:03 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_line_blank(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
	}
	return (1);
}

static int	is_col_blank(t_game *game, int i)
{
	int	j;

	j = -1;
	while (game->mapdata->map[++j] != NULL)
	{
		if (game->mapdata->map[j][i] != ' '
		&& game->mapdata->map[j][i] != '\n')
			return (0);
	}
	return (1);
}

int	single_map(t_game *game)
{
	int	i;
	int	mf;

	i = -1;
	mf = 0;
	while (game->mapdata->map[++i] != NULL)
	{
		if (is_line_blank(game->mapdata->map[i]))
			continue ;
		mf++;
		while (is_line_blank(game->mapdata->map[i]) == 0
			&& game->mapdata->map[i + 1] != NULL)
			i++;
	}
	i = -1;
	while (game->mapdata->map[0][++i])
	{
		if (is_col_blank(game, i))
			continue ;
		mf++;
		while (is_col_blank(game, i) == 0
			&& game->mapdata->map[0][i + 1] != '\0')
			i++;
	}
	return (mf);
}

int	check_limits_h(char **map)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(map[0]) - 1;
	while (map[++i])
	{
		if ((map[i][0] != '1' && map[i][0] != ' ')
			|| (map[i][len] != '1' && map[i][len] != ' '))
			return (1);
	}
	return (0);
}
