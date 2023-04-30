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

// Free memory from a group of arrays
void	ft_nfree_arr(int n, ...)
{
	va_list	args;
	void	**arr;

	va_start(args, n);
	while (n-- > 0)
	{
		arr = va_arg(args, void **);
		ft_striter((char **)arr, free);
		free(arr);
	}
	va_end(args);
}
