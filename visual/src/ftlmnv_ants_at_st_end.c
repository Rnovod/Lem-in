/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_ants_at_st_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:48:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/18 18:48:37 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline void	ftlmnv_num_ant(t_vdata *d, t_sdl_data *s,
					t_vroom *r, int num)
{
	char		*str_num_ant;
	SDL_Surface	*sur_ttf;
	SDL_Texture	*tex_ttf;
	SDL_Rect	dst_rect;

	if (!(str_num_ant = ft_itoa(num)))
		ftlmnv_error(d, 1);
	if (TTF_SizeText(s->font, r->name, &dst_rect.w, &dst_rect.h) == -1)
		ftlmnv_error(d, -3);
	if (!(sur_ttf = TTF_RenderText_Blended(s->font, str_num_ant,
		(SDL_Color){0xff, 0xff, 0xff, 0})))
		ftlmnv_error(d, -3);
	if (!(tex_ttf = SDL_CreateTextureFromSurface(s->rend, sur_ttf)))
		ftlmnv_error(d, -1);
	SDL_FreeSurface(sur_ttf);
	dst_rect.x = r->x + d->size / 2 - dst_rect.w / 2;
	dst_rect.y = r->y - dst_rect.h;
	if (SDL_RenderCopy(s->rend, tex_ttf, NULL, &dst_rect) < 0)
		ftlmnv_error(d, -1);
	SDL_DestroyTexture(tex_ttf);
	free(str_num_ant);
}

void				ftlmnv_ants_at_st_end(t_vdata *d, t_sdl_data *s)
{
	SDL_Rect	rectangel;

	rectangel.w = d->size;
	rectangel.h = rectangel.w;
	if (d->ant_start)
	{
		rectangel.x = d->st->x;
		rectangel.y = d->st->y;
		if (SDL_RenderCopy(s->rend, s->ant[0], NULL, &rectangel) < 0)
			ftlmnv_error(d, -1);
	}
	if (d->ant_end)
	{
		rectangel.x = d->e->x;
		rectangel.y = d->e->y;
		if (SDL_RenderCopy(s->rend, s->ant[0], NULL, &rectangel) < 0)
			ftlmnv_error(d, -1);
	}
	ftlmnv_num_ant(d, s, d->st, d->ant_start);
	ftlmnv_num_ant(d, s, d->e, d->ant_end);
}
