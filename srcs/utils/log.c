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

void	condition_log(char test, char *str_true, char *str_false)
{
	if (!str_true || !str_false)
		return ;
	if (test)
		printf("%s%s%s\n", "\033[38;5;65m", str_true, RESET);
	else
		printf("%s%s%s\n", "\033[38;5;124m", str_false, RESET);

}