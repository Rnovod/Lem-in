/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_create_backgrd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:54:35 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/16 16:54:36 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

inline static void	ftlmnv_add_links(t_vdata *d, t_sdl_data *s,
					const t_vroom *room, const int size)
{
	t_vlink		*l;
	const int	x_cur_room = room->x + size / 2;
	const int	y_cur_room = room->y + size / 2;

	l = room->links;
	while (l)
	{
		if (SDL_RenderDrawLine(s->rend, x_cur_room, y_cur_room,
			l->room->x + size / 2, l->room->y + size / 2 - 1) < 0)
			ftlmnv_error(d, -1);
		if (SDL_RenderDrawLine(s->rend, x_cur_room, y_cur_room,
			l->room->x + size / 2 - 1, l->room->y + size / 2) < 0)
			ftlmnv_error(d, -1);
		if (SDL_RenderDrawLine(s->rend, x_cur_room, y_cur_room,
			l->room->x + size / 2, l->room->y + size / 2) < 0)
			ftlmnv_error(d, -1);
		if (SDL_RenderDrawLine(s->rend, x_cur_room, y_cur_room,
			l->room->x + size / 2 + 1, l->room->y + size / 2) < 0)
			ftlmnv_error(d, -1);
		if (SDL_RenderDrawLine(s->rend, x_cur_room, y_cur_room,
			l->room->x + size / 2, l->room->y + size / 2 + 1) < 0)
			ftlmnv_error(d, -1);
		l = l->next;
	}
}

inline static void	ftlmnv_add_name(t_vdata *d, t_sdl_data *s,
					const t_vroom *r, const int size)
{
	SDL_Surface		*sur_ttf;
	SDL_Texture		*tex_ttf;
	SDL_Rect		dst_rect;

	if (TTF_SizeText(s->font, r->name, &dst_rect.w, &dst_rect.h) == -1)
		ftlmnv_error(d, -3);
	if (!(sur_ttf = TTF_RenderText_Blended(s->font, r->name,
		(SDL_Color){0xff, 0xff, 0xff, 0})))
		ftlmnv_error(d, -3);
	if (!(tex_ttf = SDL_CreateTextureFromSurface(s->rend, sur_ttf)))
		ftlmnv_error(d, -1);
	SDL_FreeSurface(sur_ttf);
	dst_rect.x = r->x + size / 2 - dst_rect.w / 2;
	dst_rect.y = r->y + size;
	if (SDL_RenderCopy(s->rend, tex_ttf, NULL, &dst_rect) < 0)
		ftlmnv_error(d, -1);
	SDL_DestroyTexture(tex_ttf);
}

inline static void	ftlmnv_draw_border(t_vdata *d, t_sdl_data *s,
					const t_vroom *r, const int size)
{
	SDL_Rect	rectangle;

	rectangle.x = r->x - 5;
	rectangle.y = r->y - 5;
	rectangle.w = size + 10;
	rectangle.h = size + 10;
	if (r == d->st)
	{
		if (SDL_SetRenderDrawColor(s->rend, 0x57, 0x0, 0x02, 0) < 0)
			ftlmnv_error(d, -1);
	}
	else
	{
		if (SDL_SetRenderDrawColor(s->rend, 0x09, 0x57, 0x0, 0) < 0)
			ftlmnv_error(d, -1);
	}
	if (SDL_RenderFillRect(s->rend, &rectangle) < 0)
		ftlmnv_error(d, -1);
	if (SDL_SetRenderDrawColor(s->rend, 109, 90, 73, 0) < 0)
		ftlmnv_error(d, -1);
}

inline static void	ftlmnv_add_room_links(t_vdata *d, t_sdl_data *s)
{
	SDL_Rect		rectangle;
	const t_vroom	*room = d->b->next;

	d->size = 50 + (WIDTH + HEIGHT) / 2 / ((float)d->num_rooms * M_PI);
	if (SDL_SetRenderDrawColor(s->rend, 109, 90, 73, 0) < 0)
		ftlmnv_error(d, -1);
	rectangle.w = d->size;
	rectangle.h = d->size;
	while (room)
	{
		rectangle.x = room->x;
		rectangle.y = room->y;
		ftlmnv_add_links(d, s, room, d->size);
		ftlmnv_add_name(d, s, room, d->size);
		if (room == d->st || room == d->e)
			ftlmnv_draw_border(d, s, room, d->size);
		if (room->anteater)
			d->fl = 1;
		else if (SDL_RenderFillRect(s->rend, &rectangle) < 0)
			ftlmnv_error(d, -1);
		room = room->next;
	}
}

void				ftlmnv_create_backgrd(t_vdata *d, t_sdl_data *s)
{
	SDL_Surface	*sur_backgrd;
	SDL_Texture	*tex_backgrd;
	SDL_Surface	*load_img;

	if (!(load_img = IMG_Load("./visual/img/ground.png")))
		ftlmnv_error(d, -2);
	if (!(sur_backgrd = SDL_ConvertSurfaceFormat(load_img,
		SDL_PIXELFORMAT_ARGB8888, 0)))
		ftlmnv_error(d, -1);
	if (!(tex_backgrd = SDL_CreateTextureFromSurface(s->rend, sur_backgrd)))
		ftlmnv_error(d, -1);
	if (!(s->background = SDL_CreateTexture(s->rend, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		ftlmnv_error(d, -1);
	if (SDL_SetRenderTarget(s->rend, s->background) < 0 ||
		SDL_RenderCopy(s->rend, tex_backgrd, NULL, NULL) < 0)
		ftlmnv_error(d, -1);
	SDL_DestroyTexture(tex_backgrd);
	SDL_FreeSurface(sur_backgrd);
	SDL_FreeSurface(load_img);
	ftlmnv_add_room_links(d, s);
	ftlmnv_instr_spec(d, s);
	if (SDL_SetRenderTarget(s->rend, NULL) < 0)
		ftlmnv_error(d, -1);
}
