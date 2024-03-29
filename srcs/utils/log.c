/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:35:50 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/29 01:35:50 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	header_log(char *header, char *message, char *color)
{
	printf("%s%s:%s %s%s%s\n", color, header, RESET, BOLD, message, RESET);
}

void	print_log(int n, ...)
{
	va_list	args;

	va_start(args, n);
	while (n-- > 0)
		printf("%s%s%s\n", B_GRAY, va_arg(args, char *), RESET);
	va_end(args);
}

int	assert_log(char test, char *str_true, char *str_false)
{
	if (!str_true || !str_false)
		return (0);
	if (test)
		printf("%s%s%s\n", "\033[38;5;65m", str_true, RESET);
	else
		printf("%s%s%s\n", "\033[38;5;124m", str_false, RESET);
	return (test);
}

int	error_log(char *msg)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd("ERROR:\t", STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (1);
}
