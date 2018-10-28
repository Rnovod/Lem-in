/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_draw_farm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:01:03 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/06 18:01:05 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline void	ftlmnv_default_set_ants(t_vdata *d)
{
	t_ant	*ant;
	t_moves	*moves;

	moves = (t_moves*)d->move;
	while (moves)
	{
		ant = moves->ants;
		while (ant)
		{
			ant->now_x = ant->from_x;
			ant->now_y = ant->from_y;
			ant = ant->next;
		}
		moves = moves->prev;
	}
	d->ant_start = d->ants;
	d->ant_end = 0;
	d->move = d->begin_moves;
}

static inline void	ftlmnv_manage_event(t_vdata *d)
{
	d->fl = (d->keys & KEY_RIGHT && d->move->next) ||
	(d->keys & KEY_LEFT && d->move->prev) ||
	d->keys & KEY_RETURN;
	if (d->keys & KEY_RIGHT && d->move->next)
		d->move = d->move->next;
	else if (d->keys & KEY_RETURN)
		ftlmnv_default_set_ants(d);
	else if (d->keys & KEY_MINUS && d->speed < 50)
		d->speed += 2;
	else if (d->keys & KEY_EQUALS && d->speed > 10)
		d->speed -= 2;
}

static inline void	ftlmnv_event(t_vdata *d, t_sdl_data *s)
{
	if (s->event.type == SDL_KEYDOWN)
		ftlmnv_key_down(d, s);
	else if (s->event.type == SDL_KEYUP)
		ftlmnv_key_up(d, s);
	else if (s->event.type == SDL_QUIT)
		d->keys |= KEY_QUIT;
}

static inline void	ftlmnv_draw(t_vdata *d, t_sdl_data *s)
{
	SDL_RenderClear(s->rend);
	if (d->move->ants)
		ftlmnv_ants_moving(d, s);
	if (SDL_RenderCopy(s->rend, s->background, NULL, NULL) < 0)
		ftlmnv_error(d, -1);
	if (d->keys & KEY_LEFT && d->move->prev)
		d->move = d->move->prev;
	ftlmnv_where_ants(d, s);
	SDL_RenderPresent(s->rend);
}

void				ftlmnv_draw_farm(t_vdata *d, t_sdl_data *s)
{
	d->move = d->begin_moves;
	d->ant_start = d->ants;
	ftlmnv_draw(d, s);
	while (42)
	{
		d->fl = 0;
		d->keys = 0;
		if (SDL_PollEvent(&s->event))
		{
			ftlmnv_event(d, s);
			if (d->keys)
				ftlmnv_manage_event(d);
		}
		if (d->keys & KEY_QUIT)
			break ;
		if (d->fl)
			ftlmnv_draw(d, s);
	}
}
