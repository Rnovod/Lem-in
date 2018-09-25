/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_instr_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:42:09 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/24 10:42:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline void	ftlmnv_add_spec_room(t_vdata *d, t_sdl_data *s)
{
	SDL_Rect		rectangle;
	const t_vroom	*room = d->b->next;

	rectangle.w = d->size + 80;
	rectangle.h = d->size;
	while (room)
	{
		if (room->anteater)
		{
			rectangle.x = room->x - 40;
			rectangle.y = room->y;
			if (SDL_RenderCopy(s->rend, s->anteater, NULL, &rectangle) < 0)
				ftlmnv_error(d, -1);
		}
		room = room->next;
	}
}

void				ftlmnv_instr_spec(t_vdata *d, t_sdl_data *s)
{
	SDL_Surface	*sur_ttf;
	SDL_Texture	*tex_ttf;
	SDL_Rect	dst_rect;
	char		*str;

	str = "Enter: put ants to start;   Left: step back;   "
	"   Right: step forward;   +/- change speed of ants";
	if (TTF_SizeText(s->font, str, &dst_rect.w, &dst_rect.h) == -1)
		ftlmnv_error(d, -3);
	if (!(sur_ttf = TTF_RenderText_Blended(s->font, str,
		(SDL_Color){0xff, 0xff, 0xff, 0})))
		ftlmnv_error(d, -3);
	if (!(tex_ttf = SDL_CreateTextureFromSurface(s->rend, sur_ttf)))
		ftlmnv_error(d, -1);
	SDL_FreeSurface(sur_ttf);
	dst_rect.h -= 10;
	dst_rect.x = WIDTH / 2 - dst_rect.w / 2;
	dst_rect.y = HEIGHT - dst_rect.h;
	if (SDL_RenderCopy(s->rend, tex_ttf, NULL, &dst_rect) < 0)
		ftlmnv_error(d, -1);
	SDL_DestroyTexture(tex_ttf);
	if (d->fl)
		ftlmnv_add_spec_room(d, s);
}
