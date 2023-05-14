/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:52:25 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 16:03:39 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

// ****************************************************************************
// *                                  DEFINES                                 *
// ****************************************************************************

# define TOTAL_KEYS 56

// ****************************************************************************
// *                                   ENUMS                                  *
// ****************************************************************************

# ifdef __linux__

enum e_keys
{
	KEY_ESC = 65307,
	KEY_LSHIFT = 65505,
	KEY_RSHIFT = 65506,
	KEY_LALT = 65513,
	KEY_RALT = 65514,
	KEY_LCTRL = 65507,
	KEY_UP = 65362,
	KEY_LEFT = 65361,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363,
	KEY_LMB = 1,
	KEY_MMB = 2,
	KEY_RMB = 3,
	KEY_SCR_UP = 4,
	KEY_SCR_DOWN = 5,
	KEY_SPACE = 32,
	KEY_MINUS = 45,
	KEY_DOTCOMMA = 47,
	KEY_ZERO = 48,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_THREE = 51,
	KEY_FOUR = 52,
	KEY_FIVE = 53,
	KEY_SIX = 54,
	KEY_SEVEN = 55,
	KEY_EIGHT = 56,
	KEY_NINE = 57,
	KEY_EQUAL = 61,
	KEY_A = 97,
	KEY_B = 98,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_M = 109,
	KEY_N = 110,
	KEY_O = 111,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_R = 114,
	KEY_S = 115,
	KEY_T = 116,
	KEY_U = 117,
	KEY_V = 118,
	KEY_W = 119,
	KEY_X = 120,
	KEY_Y = 121,
	KEY_Z = 122,
	KEY_ENTER = 65293
};

# else

enum e_keys
{
	KEY_ESC = 53,
	KEY_LSHIFT = 57,
	KEY_RSHIFT = 60,
	KEY_LALT = 58,
	KEY_RALT = 61,
	KEY_LCTRL = 59,
	KEY_UP = 126,
	KEY_LEFT = 123,
	KEY_DOWN = 124,
	KEY_RIGHT = 125,
	KEY_LMB = 1,
	KEY_MMB = 2,
	KEY_RMB = 3,
	KEY_SCR_UP = 4,
	KEY_SCR_DOWN = 5,
	KEY_SPACE = 49,
	KEY_MINUS = 27,
	KEY_DOTCOMMA = 41,
	KEY_ZERO = 29,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_FIVE = 23,
	KEY_SIX = 22,
	KEY_SEVEN = 26,
	KEY_EIGHT = 28,
	KEY_NINE = 25,
	KEY_EQUAL = 24,
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_ENTER = 76
};
# endif

#endif
