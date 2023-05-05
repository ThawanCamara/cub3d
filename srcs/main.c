/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/04 15:18:10 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	my_mlx_pixel_put(t_imgdata *imgdata, int x, int y, int color)
{
	char	*dst;

	dst = imgdata->addr + (y * imgdata->line_length + x * (imgdata->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	// int size[2];
	// t_imgdata *imgdata = malloc(sizeof(t_imgdata));
	// imgdata->img = mlx_xpm_file_to_image(game.mlx, game.mapdata->tex_path[NORTH], &size[X], &size[Y]);
	// imgdata->addr = mlx_get_data_addr(imgdata->img, &imgdata->bits_per_pixel, &imgdata->line_length, &imgdata->endian);
	// t_imgdata img2;
	// img2.img = mlx_new_image(game.mlx, 64, 32);
	// img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length, &img2.endian);
	// my_mlx_pixel_put(&img2, 16, 16, 0x0022FF00);
	// img2.addr = ft_strdup(imgdata->addr);
	// mlx_put_image_to_window(game.mlx, game.win, img2.img, 0, 0);
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