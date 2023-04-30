/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 05:26:00 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/30 15:45:19 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Set a static lookup table for all initilization functions */
const void	**config_table_builder(void)
{
	static const void	*table[FUNC_TABLE_SIZE] = {
		map_init, map_clear,
		data_init, data_clear,
		inst_init, inst_clear
	};

	return ((const void **) table);
}

/* Calls init funcs in order, if one fails call the clear ones in reverse */
void	init_handler(t_game *game)
{
	const void	**table = config_table_builder();
	int			i;

	i = -1;
	while (++i < FUNC_TABLE_SIZE)
	{
		if (!((int (*)())table[i++])(game))
			clear_handler(game, i);
	}
}

void	clear_handler(t_game *game, int i)
{
	const void	**table = config_table_builder();

	printf("\n====%s Freeing Memory %s====\n", B_TEAL, RESET);
	while (i > 0)
	{
		((void (*)())table[i])(game);
		i -= 2;
	}
	exit(1);
}
