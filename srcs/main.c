/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/30 17:56:20 by tde-souz         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argc;
	(void)argv;

	/* Temp */
	game.enable_parallax = 0;
	game.total_insts = 2;

	init_handler(&game);
	int x = 200;
	int y = 200;
	
	game.imgdata = malloc(sizeof(t_imgdata));
	game.imgdata->img = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game.imgdata->addr = mlx_get_data_addr(game.imgdata->img, &game.imgdata->bits_per_pixel, &game.imgdata->line_length, &game.imgdata->endian);
	for (int i = 0; i < 300; i++)
		for (int j = 0; j < 200; j++)
		{
			my_mlx_pixel_put(game.imgdata, i, j, 0x00FFFF00); // passar data
		}
	for (int i = 0 + SCREEN_OFFSET; i < 300 + SCREEN_OFFSET; i++)
		for (int j = 0; j < 200; j++)
			my_mlx_pixel_put(game.imgdata, i, j, 0x0000FFAA);
	mlx_put_image_to_window(game.mlx, game.win, game.imgdata->img, 0, 0);
/* 	t_imgdata imgdata;

	imgdata.img = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	imgdata.addr = mlx_get_data_addr(imgdata.img, &imgdata.bits_per_pixel, &imgdata.line_length, &imgdata.endian);
	for (int i = 0; i < 300; i++)
		for (int j = 0; j < 200; j++)
			my_mlx_pixel_put(&imgdata, i, j, 0x00FFFF00);
	for (int i = 0 + SCREEN_OFFSET; i < 300 + SCREEN_OFFSET; i++)
		for (int j = 0; j < 200; j++)
			my_mlx_pixel_put(&imgdata, i, j, 0x0000FFAA);
	mlx_put_image_to_window(game.mlx, game.win, imgdata.img, 0, 0); */

	mlx_string_put(game.mlx, game.win, x, y, 0x00ff0000, "PINTO");
	mlx_string_put(game.mlx, game.win, x + SCREEN_OFFSET, y, 0x0000ff00, "PENIS");
/* 	int size[2];
	size[X] = 700;
	size[Y] = 64;
	int pos[2];
	pos[X] = 175;
	pos[Y] = 305;
	draw_rect(&game, size, pos, 0x00ffff00); */
	mlx_loop_hook (game.mlx, mouse_test, &game);
	mlx_loop(game.mlx);
	clear_handler(&game, FUNC_TABLE_SIZE - 1);
	return (0);
}
