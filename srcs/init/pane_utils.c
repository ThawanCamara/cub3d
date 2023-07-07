/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pane_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:18:34 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/09 15:18:34 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_pane	*create_pane(t_game *game, char *name)
{
	t_pane	*new_pane;

	new_pane = (t_pane *)malloc(sizeof(t_pane));
	if (!new_pane)
		return (NULL);
	new_pane->name = name;
	new_pane->game = game;
	new_pane->screen = game->screen;
	return (new_pane);
}

void	pane_setdata(t_pane *pane, int *size, int *offset)
{
	double	tmp;

	if (!pane)
		return ;
	pane->min_bounds[X] = offset[X];
	pane->min_bounds[Y] = offset[Y];
	pane->max_bounds[X] = offset[X] + size[X];
	pane->max_bounds[Y] = offset[Y] + size[Y];
	pane->offset[X] = offset[X];
	pane->offset[Y] = offset[Y];
	pane->size[X] = size[X];
	pane->size[Y] = size[Y];
	pane->scale = 0;
	tmp = (double)(size[X]) / pane->screen->size[X];
	if (tmp > pane->scale)
		pane->scale = tmp;
	tmp = (double)(size[Y]) / pane->screen->size[Y];
	if (tmp > pane->scale)
		pane->scale = tmp;
}

void	pane_setdata_ratio(t_pane *pane, int *size,
		double ratio_x, double ratio_y)
{
	double		tmp;
	t_screen	*sc;

	if (!pane)
		return ;
	sc = pane->screen;
	pane->min_bounds[X] = sc->size[X] * (double)ratio_x * 0.01;
	pane->min_bounds[Y] = sc->size[Y] * (double)ratio_y * 0.01;
	pane->max_bounds[X] = pane->min_bounds[X] + size[X];
	pane->max_bounds[Y] = pane->min_bounds[Y] + size[Y];
	pane->offset[X] = pane->min_bounds[X];
	pane->offset[Y] = pane->min_bounds[Y];
	pane->size[X] = size[X];
	pane->size[Y] = size[Y];
	pane->scale = 0;
	tmp = (double)(size[X]) / pane->screen->size[X];
	if (tmp > pane->scale)
		pane->scale = tmp;
	tmp = (double)(size[Y]) / pane->screen->size[Y];
	if (tmp > pane->scale)
		pane->scale = tmp;
}

void	pane_resize(t_pane *pane, int value)
{
	double	tmp;

	if (!pane)
		return ;
	pane->size[X] += value;
	pane->size[Y] += value;
	pane->max_bounds[X] += value;
	pane->max_bounds[Y] += value;
	pane->scale = 0;
	tmp = (double)(pane->size[X]) / pane->screen->size[X];
	if (tmp > pane->scale)
		pane->scale = tmp;
	tmp = (double)(pane->size[Y]) / pane->screen->size[Y];
	if (tmp > pane->scale)
		pane->scale = tmp;
}
