/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_draw_where_ants.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:43:15 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/17 16:43:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline void		ftlmnv_draw_ants(t_vdata *d, t_sdl_data *s)
{
	SDL_Rect	rectangel;
	const t_ant	*ant = d->move->ants;

	rectangel.w = d->size;
	rectangel.h = rectangel.w;
	while (ant)
	{
		rectangel.x = ant->to_x;
		rectangel.y = ant->to_y;
		if (SDL_RenderCopy(s->rend, s->ant[0], NULL, &rectangel) < 0)
			ftlmnv_error(d, -1);
		ant = ant->next;
	}
}

void					ftlmnv_where_ants(t_vdata *d, t_sdl_data *s)
{
	ftlmnv_ants_at_st_end(d, s);
	if (d->move->ants)
		ftlmnv_draw_ants(d, s);
}
