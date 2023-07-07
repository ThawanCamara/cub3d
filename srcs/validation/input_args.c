/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:22:49 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/29 15:22:49 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	print_helper(void)
{
	ft_putstr_fd(B_RED, STDERR_FILENO);
	ft_putstr_fd(">>> Invalid Arguments <<<\n", STDERR_FILENO);
	ft_putstr_fd(SILVER, STDERR_FILENO);
	ft_putstr_fd("\nInput should be like:\n", STDERR_FILENO);
	ft_putstr_fd(TEAL, STDERR_FILENO);
	ft_putstr_fd("./cub3d map.cub\n\n", STDERR_FILENO);
	ft_putstr_fd(GRAY, STDERR_FILENO);
	ft_putstr_fd("Naming Constraints:\n", STDERR_FILENO);
	ft_putstr_fd("\t- cannot be empty\n", STDERR_FILENO);
	ft_putstr_fd("\t- must be alphanumeric\n", STDERR_FILENO);
	ft_putstr_fd("\t- can't start with '.'\n", STDERR_FILENO);
	ft_putstr_fd("\t- can't have more than one '.'\n", STDERR_FILENO);
	ft_putstr_fd("\t- must end with .cub\n", STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	return (1);
}

static int	check_chars(char *str, int (*f)(int))
{
	size_t	i;
	char	valid;

	i = 0;
	valid = 1;
	if (str == NULL)
		return (0);
	while (valid && *(str + i))
	{
		valid = f(*(str + i));
		i++;
	}
	return (valid);
}

int	check_args(t_game *game, int argc, char *argv[])
{
	char	status;
	char	*name;
	char	*extension;

	status = argc != 2;
	if (status)
		return (print_helper());
	game->mapname = argv[1];
	extension = ft_strchr(argv[1], '.');
	if (ft_strlen(extension) == ft_strlen(argv[1]))
		return (print_helper());
	if (extension == NULL
		|| ft_strncmp(extension, ".cub\0", 5) != 0)
		return (print_helper());
	name = ft_substr(argv[1], 0, ft_strdiff(argv[1], '.'));
	if (check_chars(name, ft_isalnum) == 0)
		print_helper();
	free(name);
	return (status);
}

int check_empty_line(char *line)
{
	char	*s;
	char	valid;

	s = ft_strtrim(line, " ");
	valid = 0;
	if (ft_strncmp(s, "\n\0", 2) == 0)
		valid = 1;
	free(s);
	return (valid);
}

int	type_handler(char *type)
{
	const char	*tab[] = {"NO\0", "SO\0", "WE\0", "EA\0", 0};
	char	valid;
	int		i;

	valid = 0;
	i = -1;
	while (tab[++i])
	{
		if (ft_strncmp(tab[i], type, 3) == 0)
			return (1);
	}
	if (ft_strncmp(type, "C\0", 2) == 0 || ft_strncmp(type, "F\0", 2) == 0 )
		valid = 2;
	else if (check_empty_line(type))
		valid = 3;
	return (valid);
}
