/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/05 00:33:24 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	tmp_init_screen(t_game *game)
{
	t_imgdata *idata;

	idata = game->imgdata;
	idata->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	idata->addr = mlx_get_data_addr(idata->img, &idata->bpp, &idata->len, &idata->endian);
}

void	draw_map(t_game *game, int *size)
{
	int	i[2];
	int	anchor[2];
	int	offset[2];
	int	box[2];

	double scale;
	scale = 1;
	if ((300 / ((double)size[X] * 16)) < scale)
		scale = 300 / ((double)size[X] * 16);
	if ((200 / ((double)size[Y] * 16)) < scale)
		scale = 200 / ((double)size[Y] * 16);
	// double scale[2];
	// scale[Y] = 200 / ((double)size[Y] * 16);

	printf("%f / %f\n", (double)size[X], (double)300);
	printf("%d - %f\n", size[X], scale);
	// printf("%f / %f\n", (double)size[X], (double)300);
	// printf("%d - %f\n", size[X], scale[X]);
	vector2(0, 0, &i[X], &i[Y]);
	vector2(600, 250, &anchor[X], &anchor[Y]);
	vector2(16 * scale, 16 * scale, &box[X], &box[Y]);
	// vector2(16 * scale[X], 16 * scale[Y], &box[X], &box[Y]);
	while (i[X] < size[X] && i[Y] < size[Y])
	{
		//vector2(i[X] * box[X], i[Y] * box[Y], &pos[X], &pos[Y]);
		offset[X] = i[X] * box[X] + anchor[X];
		offset[Y] = i[Y] * box[Y] + anchor[Y];
		if (game->mapdata->map[i[Y]][i[X]] == 49)
			draw_rect(game->imgdata, box, offset, 0x0077771E);
		else if (game->mapdata->map[i[Y]][i[X]] == 48)
			draw_rect(game->imgdata, box, offset, 0x00FFFFFF);
		i[X]++;
		if (i[X] == size[X] && i[Y] < size[Y])
		{
			i[X] = 0;
			i[Y]++;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argc;
	(void)argv;

	/* Temp */
	game.enable_parallax = 0;
	game.total_insts = 2;

	init_handler(&game);
	tmp_init_screen(&game);
	
	int size[2];
	int pos[2];
	vector2(300, 200, &size[X], &size[Y]);
	vector2(600, 250, &pos[X], &pos[Y]);
	draw_rect(game.imgdata, size, pos, 0x0000FF00);
	
	draw_map(&game, game.mapdata->size);
	mlx_put_image_to_window(game.mlx, game.win, game.imgdata->img, 0, 0);
	mlx_loop(game.mlx);
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