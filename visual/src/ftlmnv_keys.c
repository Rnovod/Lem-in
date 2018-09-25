/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:40:38 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/13 13:40:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		ftlmnv_key_down(t_vdata *d, t_sdl_data *s)
{
	if (s->event.key.keysym.sym == SDLK_ESCAPE)
		d->keys |= KEY_QUIT;
	else if (s->event.key.keysym.sym == SDLK_RETURN)
		d->keys |= KEY_RETURN;
	else if (s->event.key.keysym.sym == SDLK_RIGHT)
		d->keys |= KEY_RIGHT;
	else if (s->event.key.keysym.sym == SDLK_LEFT)
		d->keys |= KEY_LEFT;
	else if (s->event.key.keysym.sym == SDLK_EQUALS)
		d->keys |= KEY_EQUALS;
	else if (s->event.key.keysym.sym == SDLK_MINUS)
		d->keys |= KEY_MINUS;
}

void		ftlmnv_key_up(t_vdata *d, t_sdl_data *s)
{
	if (s->event.key.keysym.sym == SDLK_RETURN ||
		s->event.key.keysym.sym == SDLK_RIGHT ||
		s->event.key.keysym.sym == SDLK_LEFT ||
		s->event.key.keysym.sym == SDLK_EQUALS ||
		s->event.key.keysym.sym == SDLK_MINUS)
		d->keys = 0;
}
