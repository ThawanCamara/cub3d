/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 15:40:23 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	draw_map(t_game *game, t_pane *pane)
{
	int	i[2];
	int	offset[2];
	int	box[2];

	vector2(0, 0, &i[X], &i[Y]);
	vector2(game->ui->minimap_box_size, game->ui->minimap_box_size, &box[X], &box[Y]);
	while (i[X] < game->mapdata->size[X] && i[Y] < game->mapdata->size[Y])
	{
		offset[X] = i[X] * box[X] + pane[MINIMAP].offset[X];
		offset[Y] = i[Y] * box[Y] + pane[MINIMAP].offset[Y];
		if (game->mapdata->map[i[Y]][i[X]] == 49)
			draw_rect(game->screen, box, offset, 0x0077771E);
		else if (game->mapdata->map[i[Y]][i[X]] == 48)
			draw_rect(game->screen, box, offset, 0x00FFFFFF);
		i[X]++;
		if (i[X] == game->mapdata->size[X] && i[Y] < game->mapdata->size[Y])
		{
			i[X] = 0;
			i[Y]++;
		}
	}
	// int limits[2];
	// int pos2[2];
	// vector2((int)game->inst[0].cam->pos[X], (int)game->inst[0].cam->pos[Y], &pos2[X], &pos2[Y]);
	// vector2(300 + 600, 200 + 250, &limits[X], &limits[Y]);
	// draw_line(game->screen, pos2, game->inst[0].cam->rotation, limits);
	
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
	//mlx_clear_window(game->mlx, game->win);
	return (0);
}


// int	draw_map(t_game *game)
// {
// 	int	i[2];
// 	int	anchor[2];
// 	int	offset[2];
// 	int	box[2];
// 	int size[2];

// 	size[X] = game->mapdata->size[X];
// 	size[Y] = game->mapdata->size[Y];

// 	double scale;
// 	scale = 1;
// 	if ((300 / ((double)size[X] * 16)) < scale)
// 		scale = 300 / ((double)size[X] * 16);
// 	if ((200 / ((double)size[Y] * 16)) < scale)
// 		scale = 200 / ((double)size[Y] * 16);
// 	vector2(0, 0, &i[X], &i[Y]);
// 	vector2(600, 250, &anchor[X], &anchor[Y]);
// 	vector2(16 * scale, 16 * scale, &box[X], &box[Y]);
// 	while (i[X] < size[X] && i[Y] < size[Y])
// 	{
// 		offset[X] = i[X] * box[X] + anchor[X];
// 		offset[Y] = i[Y] * box[Y] + anchor[Y];
// 		if (game->mapdata->map[i[Y]][i[X]] == 49)
// 		{
// 			draw_rect(game->screen, box, offset, 0x0077771E);
// 		}
// 		else if (game->mapdata->map[i[Y]][i[X]] == 48)
// 			draw_rect(game->screen, box, offset, 0x00FFFFFF);
// 		i[X]++;
// 		if (i[X] == size[X] && i[Y] < size[Y])
// 		{
// 			i[X] = 0;
// 			i[Y]++;
// 		}
// 	}
// 	int limits[2];
// 	int pos2[2];
// 	vector2((int)game->inst[0].cam->pos[X], (int)game->inst[0].cam->pos[Y], &pos2[X], &pos2[Y]);
// 	vector2(300 + 600, 200 + 250, &limits[X], &limits[Y]);
// 	draw_line(game->screen, pos2, game->inst[0].cam->rotation, limits);
	
// 	mlx_clear_window(game->mlx, game->win);
	
// 	//draw_line(game->imgdata, pos2, 30, limits);
// 	//draw_line(game->imgdata, pos2, 45, limits);
// 	for (int a = -45; a <= 45; a++)
// 	{
// 		// printf("%d\n", a);
// 	}
// 	// printf("DEBUG: %p\n", game->mlx);
// 	// printf("DEBUG: %p\n", game->win);
// 	// printf("DEBUG: %p\n", game->screen->img);
// 	// mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argc;
	(void)argv;

	/* Temp */
	game.enable_parallax = TRUE;
	game.total_insts = 1 + game.enable_parallax;

	init_handler(&game);

	/* Background */
	draw_rect(game.screen, game.pane[MINIMAP]->size, game.pane[MINIMAP]->offset, 0x00545454);
	// 
	// game.inst[0].cam->pos[X] = 750;
	// game.inst[0].cam->pos[Y] = 350;
	// game.inst[0].cam->rotation = 0;
	// for (int o = 359; o > 0; o--)
	// {
		// int limits[2];
		// int pos2[2];
		// vector2((int)game.inst[0].cam->pos[X], (int)game.inst[0].cam->pos[Y], &pos2[X], &pos2[Y]);
		// vector2(300 + 600 + 150, 200 + 250 + 100, &limits[X], &limits[Y]);
		// draw_line(game.imgdata, pos2, (double)o, limits);
		// draw_line(game.imgdata, game.inst[0].cam->pos, 45, limits);
	// }
	// int limits[2];
	// int pos2[2];
	// vector2((int)game.inst[0].cam->pos[X], (int)game.inst[0].cam->pos[Y], &pos2[X], &pos2[Y]);
	// vector2(300 + 600 + 150, 200 + 250 + 100, &limits[X], &limits[Y]);
	// draw_line(game.imgdata, pos2, 15, limits);
	// mlx_put_image_to_window(game.mlx, game.win, game.imgdata->img, 0, 0);
	// draw_map(&game);
	// draw_map(&game, game.pane[MINIMAP]);
	// render_game(&game);
	mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.mlx);
	//clear_handler(&game, FUNC_TABLE_SIZE - 1);
	return (0);
}




/* 	int size[2];
	t_imgdata *imgdata = malloc(sizeof(t_imgdata));
	imgdata->img = mlx_xpm_file_to_image(game.mlx, game.mapdata->path_no, &size[X], &size[Y]);
	imgdata->addr = mlx_get_data_addr(imgdata->img, &imgdata->bits_per_pixel, &imgdata->line_length, &imgdata->endian);
	imgdata->addr2 = (unsigned int *)mlx_get_data_addr(imgdata->img, &imgdata->bits_per_pixel, &imgdata->line_length, &imgdata->endian);
	printf("bpp: %d\n", imgdata->bits_per_pixel);
	printf("len: %d\n", imgdata->line_length);
	printf("size X: %d\n", size[X]);
	printf("size X: %d\n", size[Y]);
	printf("\nchar * : \n");
	for(int i = 0; i < imgdata->line_length ; i++)
	{
		ft_printf("|%X|", imgdata->addr[i]);
	}
	for(int i = 0; i < 731880 ; i++)
	{
		if (i > 730000)
			ft_printf("%d > |%X|\n", i, imgdata->addr2[i]);
	}
	mlx_put_image_to_window(game.mlx, game.win, imgdata->img, 0, 0); */
	
/* 	game.imgdata = malloc(sizeof(t_imgdata));
	game.imgdata->img = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game.imgdata->addr = mlx_get_data_addr(game.imgdata->img, &game.imgdata->bits_per_pixel, &game.imgdata->line_length, &game.imgdata->endian);
	// printf("bpp: %d\n", game.imgdata->bits_per_pixel);
	// printf("len: %d\n", game.imgdata->line_length);
	// printf("endian: %d\n", game.imgdata->endian);
	for (int i = 0; i < 300; i++)
		for (int j = 0; j < 200; j++)
		{
			// my_mlx_pixel_put(game.imgdata, i, j, 0x00FFFF00); // passar data
			//my_mlx_pixel_put(game.imgdata, i, j, 0xFF0A8B1C); // passar data
			my_mlx_pixel_put(game.imgdata, i, j, 4278881052); // passar data
		}
	for (int i = 0 + SCREEN_OFFSET; i < 300 + SCREEN_OFFSET; i++)
		for (int j = 0; j < 200; j++)
			my_mlx_pixel_put(game.imgdata, i, j, 0x0000FFAA);
	mlx_put_image_to_window(game.mlx, game.win, game.imgdata->img, 0, 0); */

/* 	t_imgdata imgdata;

	imgdata.img = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	imgdata.addr = mlx_get_data_addr(imgdata.img, &imgdata.bits_per_pixel, &imgdata.line_legth, &imgdata.endian);
	for (int i = 0; i < 300; i++)n
		for (int j = 0; j < 200; j++)
			my_mlx_pixel_put(&imgdata, i, j, 0x0022FF00);
	for (int i = 0 + SCREEN_OFFSET; i < 300 + SCREEN_OFFSET; i++)
		for (int j = 0; j < 200; j++)
			my_mlx_pixel_put(&imgdata, i, j, 0x00ee3300);
	mlx_put_image_to_window(game.mlx, game.win, imgdata.img, 0, 0);
	
	mlx_string_put(game.mlx, game.win, x, y, 0x00ff0000, "PINTO");
	mlx_string_put(game.mlx, game.win, x + SCREEN_OFFSET, y, 0x0000ff00, "PENIS"); */
/* 	int size[2];
	size[X] = 700;
	size[Y] = 64;
	int pos[2];
	pos[X] = 175;
	pos[Y] = 305;
	draw_rect(&game, size, pos, 0x00ffff00); */