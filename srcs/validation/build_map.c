#include "game.h"

#define ARR 0
#define TMP 1

//	==============================

void	print(char *s)
{
	ft_printf(">> %s\n", s);
}

//	==============================

size_t	get_max_len(char **arr)
{
	size_t	len;
	size_t	tmp;
	size_t	i;

	if (arr == NULL)
		return (0);
	len = 0;
	i = -1;
	while (*(arr + ++i))
	{
		tmp = ft_strlen(*(arr + i));
		if (tmp > len)
			len = tmp;
	}
	return (len);
}

int	make_map(t_game *game, char **arr)
{
	size_t	i;
	size_t	size;
	size_t	len;

	i = -1;
	if (arr == NULL)
		return (1);
	size = ft_strarr_size(arr);
	len = get_max_len(arr);
	game->mapdata->size[X] = len;
	game->mapdata->size[Y] = size;
	game->mapdata->map = (char **)malloc(sizeof(char *) * (size + 1));
	if (game->mapdata->map == NULL)
		return (1);
	game->mapdata->map[size] = NULL;
	while (++i < size)
	{
		game->mapdata->map[i] = (char *)malloc(sizeof(char) * (len + 1));
		ft_memset(game->mapdata->map[i], 32, len);
		ft_memcpy(game->mapdata->map[i], arr[i], ft_strlen(arr[i]));
		game->mapdata->map[i][len] = 0;
	}
	ft_striter(game->mapdata->map, print); //debug
	if (map_checker(game))
		return (1);
	return (0);
}

int	build_map(t_game *game, int fd)
{
	char	**arr[2];
	char	*line;
	char	check;

	arr[ARR] = NULL;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		arr[TMP] = ft_strarr_expand(arr[ARR], line);
		ft_free_arr((void **)arr[ARR]);
		arr[ARR] = arr[TMP];
		free(line);
	}
	check = make_map(game, arr[ARR]);
	ft_free_arr((void **)arr[ARR]);
	if (check)
		error_log("EXCESSO DE TRAGEDIA");
	return (check);
}