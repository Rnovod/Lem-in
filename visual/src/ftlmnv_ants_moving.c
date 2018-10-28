/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_ants_moving.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:05:31 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/18 18:05:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

inline static void	ftlmnv_moves(t_vdata *d, t_sdl_data *s, t_ant *ant,
					int step)
{
	SDL_Rect	rectangel;
	const int	dir = (ant->step_x < 0) * 2;

	rectangel.x = ant->now_x;
	rectangel.y = ant->now_y;
	if (APPROX((int)ant->now_x, d->st->x) &&
		APPROX((int)ant->now_y, d->st->y))
		d->ant_start--;
	else if (APPROX((int)ant->now_x, d->e->x) &&
		APPROX((int)ant->now_y, d->e->y))
		d->ant_end--;
	else if (APPROX((int)(ant->now_x + ant->step_x), d->st->x) &&
		APPROX((int)(ant->now_y + ant->step_y), d->st->y))
		d->ant_start++;
	else if (APPROX((int)(ant->now_x + ant->step_x), d->e->x) &&
		APPROX((int)(ant->now_y + ant->step_y), d->e->y))
		d->ant_end++;
	rectangel.w = d->size;
	rectangel.h = rectangel.w;
	if (SDL_RenderCopy(s->rend, s->ant_mov[step + dir], NULL, &rectangel) < 0)
		ftlmnv_error(d, -1);
	ant->now_x += ant->step_x;
	ant->now_y += ant->step_y;
}

static inline void	ftlmnv_init_forward_coord(t_vdata *d, t_ant *ant)
{
	while (ant)
	{
		ant->step_x = (ant->to_x - ant->now_x) / d->speed;
		ant->step_y = (ant->to_y - ant->now_y) / d->speed;
		ant = ant->next;
	}
}

static inline void	ftlmnv_init_back_coord(t_vdata *d, t_ant *ant)
{
	while (ant)
	{
		ant->step_x = (ant->from_x - ant->now_x) / d->speed;
		ant->step_y = (ant->from_y - ant->now_y) / d->speed;
		ant = ant->next;
	}
}

void				ftlmnv_ants_moving(t_vdata *d, t_sdl_data *s)
{
	int		tick;
	int		step;
	t_ant	*ant;

	(d->keys & KEY_LEFT) ? ftlmnv_init_back_coord(d, d->move->ants) :
	ftlmnv_init_forward_coord(d, d->move->ants);
	step = d->speed;
	while (step--)
	{
		tick = SDL_GetTicks();
		SDL_RenderClear(s->rend);
		if (SDL_RenderCopy(s->rend, s->background, NULL, NULL) < 0)
			ftlmnv_error(d, -1);
		ant = d->move->ants;
		while (ant)
		{
			ftlmnv_moves(d, s, ant, step % 3 % 2);
			ant = ant->next;
		}
		ftlmnv_ants_at_st_end(d, s);
		SDL_RenderPresent(s->rend);
		if (1000 / FPS > SDL_GetTicks() - tick)
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - tick));
	}
}
