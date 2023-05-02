/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/02 14:19:13 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	my_mlx_pixel_put(t_imgdata *imgdata, int x, int y, int color)
{
	char	*dst;

	dst = imgdata->addr + (y * imgdata->line_length + x * (imgdata->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mouse_test(t_game *game)
{
	int pos[2];

	mlx_mouse_get_pos(game->mlx, game->win, &pos[X], &pos[Y]);
	printf("> X: %d | Y: %d\n", pos[X], pos[Y]);
	int size[2];
	size[X] = 8;
	size[Y] = 8;
	if (pos[X] < SCREEN_WIDTH && pos[X] > 0 && pos[Y] < SCREEN_HEIGHT && pos[Y] > 0)
		draw_rect(game, size, pos, 0x00ffff00);
		//mlx_pixel_put(game->mlx, game->win, pos[X], pos[Y], 0x00ffffff);
		//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
		//my_mlx_pixel_put(game->imgdata, pos[X], pos[Y], 0x000033AA);
	//my_mlx_pixel_put(game.imgdata, i, j, 0x0000FFAA);
	return (0);
}

// plotter(t_game *game, t_imgdata *imgdata, )

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argc;
	(void)argv;

	/* Temp */
	game.enable_parallax = 0;
	game.total_insts = 2;

	init_handler(&game);
//  4294967236
//	FF0A8B1C

// >> 4278881052

	int size[2];
	t_imgdata *imgdata = malloc(sizeof(t_imgdata));
	imgdata->img = mlx_xpm_file_to_image(game.mlx, game.mapdata->path_no, &size[X], &size[Y]);
	imgdata->addr = mlx_get_data_addr(imgdata->img, &imgdata->bits_per_pixel, &imgdata->line_length, &imgdata->endian);
	imgdata->addr2 = (unsigned int *)mlx_get_data_addr(imgdata->img, &imgdata->bits_per_pixel, &imgdata->line_length, &imgdata->endian);
	imgdata->addr3 = (unsigned long *)mlx_get_data_addr(imgdata->img, &imgdata->bits_per_pixel, &imgdata->line_length, &imgdata->endian);
	printf("bpp: %d\n", imgdata->bits_per_pixel);
	printf("len: %d\n", imgdata->line_length);
	printf("\nchar * : \n");
	for(int i = 0; i < imgdata->line_length ; i++)
	{
		ft_printf("|%X|", imgdata->addr[i]);
	}
	printf("\nuint * : \n");
	for(int i = 0; i < imgdata->line_length ; i++)
	{
		ft_printf("|%X|", imgdata->addr2[i]);
	}
	printf("\nulong * : \n");
	for(int i = 0; i < imgdata->line_length ; i++)
	{
		printf("|%lu\n|", imgdata->addr3[i]);
	}
	mlx_put_image_to_window(game.mlx, game.win, imgdata->img, 0, 0);
	/* 
	int x = 200;
	int y = 200; */
	
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
	//mlx_loop_hook (game.mlx, mouse_test, &game);
	mlx_loop(game.mlx);
	clear_handler(&game, FUNC_TABLE_SIZE - 1);
	return (0);
}
