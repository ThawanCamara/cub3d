/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcombine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:22:39 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/23 20:00:47 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*combine_handler(int n, va_list args)
{
	char	*ret;
	char	*tmp;
	char	*arg;

	if (n <= 0)
		return (NULL);
	ret = ft_strdup(va_arg(args, char *));
	while (--n > 0)
	{
		tmp = ret;
		arg = va_arg(args, char *);
		if (arg)
		{
			if (ret)
				ret = ft_strjoin(ret, arg);
			else
				ret = ft_strdup(arg);
			free(tmp);
		}
	}
	return (ret);
}

char	*ft_strcombine(int n, ...)
{
	char	*ret;
	va_list	args;

	va_start(args, n);
	ret = combine_handler(n, args);
	va_end(args);
	return (ret);
}
