/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:33:38 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/03 12:33:38 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

// ****************************************************************************
// *                                  DEFINES                                 *
// ****************************************************************************

# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_MOUSE_PRESS 4
# define EVENT_MOUSE_RELEASE 5
# define EVENT_MOUSE_MOTION 6
# define EVENT_WIN_ENTER 7
# define EVENT_WIN_LEAVE 8
# define EVENT_FOCUS_IN 9
# define EVENT_FOCUS_OUT 10
# define EVENT_EXPOSE 12
# define EVENT_CLOSE 17

# define MASK_KEY_PRESS 1L<<0
# define MASK_KEY_RELEASE 1L<<1
# define MASK_MOUSE_PRESS 1L<<2
# define MASK_MOUSE_RELEASE 1L<<3
# define MASK_WIN_ENTER 1L<<4
# define MASK_WIN_LEAVE 1L<<5
# define MASK_MOUSE_MOTION 1L<<6
# define MASK_EXPOSURE 1L<<15
# define MASK_STRUCTNOTIFY 1L<<17
# define MASK_FOCUS 1L<<21

#endif