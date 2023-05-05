/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:56:06 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/03 16:56:06 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	window_onclose(t_game *game)
{
	(void)game;
	ft_printf("Closing the window\n");
	clear_handler(game, FUNC_TABLE_SIZE - 1);
	return (0);
}

int	window_onresize(t_game *game)
{
	(void)game;
	ft_printf("Resizing the window\n");
	return (0);
}
