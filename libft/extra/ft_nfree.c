/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nfree_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:05:31 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/14 15:05:31 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Free memory from a group of pointers
void	ft_nfree(int n, ...)
{
	va_list	args;
	void	*ptr;

	va_start(args, n);
	while (n-- > 0)
	{
		ptr = va_arg(args, void *);
		free(ptr);
	}
	va_end(args);
}
