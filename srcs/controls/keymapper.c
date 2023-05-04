/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymapper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:55:34 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/03 16:55:34 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static const char	**get_keytable_name(void)
{
	static const char	*keytable_name[] = {"ESC", "LSHIFT", "RSHIFT", "LALT",
		"RALT", "LCTRL", "Arrow Up", "Arrow Left", "Arrow Down", "Arrow Right",
		"LMB", "MMB", "RMB", "Scroll Up", "Scroll Down", "SPACE", "-",
		"DOTCOMMA", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "EQUAL",
		"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q",
		"R","S","T","U","V","W","X","Y","Z","ENTER"};

	return ((const char **)keytable_name);
}

static const int	*get_keytable_id(void)
{
	static const int	keytable_id[] = {KEY_ESC, KEY_LSHIFT, KEY_RSHIFT,
		KEY_LALT, KEY_RALT, KEY_LCTRL, KEY_ARROW_U ,KEY_ARROW_L ,KEY_ARROW_D,
		KEY_ARROW_R, KEY_LMB, KEY_MMB, KEY_RMB, KEY_SCR_UP, KEY_SCR_DOWN,
		KEY_SPACE, KEY_MINUS, KEY_DOTCOMMA, KEY_ZERO, KEY_ONE, KEY_TWO,
		KEY_THREE, KEY_FOUR, KEY_FIVE, KEY_SIX, KEY_SEVEN, KEY_EIGHT, KEY_NINE,
		KEY_EQUAL,KEY_A,KEY_B,KEY_C,KEY_D,KEY_E,KEY_F,KEY_G,KEY_H,KEY_I,KEY_J,
		KEY_K,KEY_L,KEY_M,KEY_N,KEY_O,KEY_P,KEY_Q,KEY_R,KEY_S,KEY_T,KEY_U,KEY_V,
		KEY_W,KEY_X,KEY_Y,KEY_Z, KEY_ENTER};

	return ((const int *)keytable_id);
}

char	*get_key_name(int value)
{
	const char	**keytable_name = get_keytable_name();
	const int	*keytable_id = get_keytable_id();
	int			i;

	i = -1;
	while (++i < TOTAL_KEYS)
	{
		if (value == keytable_id[i])
			return ((char *)keytable_name[i]);
	}
	return (NULL);
}

int	get_key_value(char *name)
{
	const char	**keytable_name = get_keytable_name();
	const int	*keytable_id = get_keytable_id();
	int			i;
	size_t		len;

	i = -1;
	len = ft_strlen(name);
	while (++i < TOTAL_KEYS)
	{
		if (ft_strncmp(name, keytable_name[i], len + 1))
			return ((int)keytable_id[i]);
	}
	return (-1);
}
